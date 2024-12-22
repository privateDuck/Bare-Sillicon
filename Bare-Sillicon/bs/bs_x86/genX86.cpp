#include "genX86.hpp"

namespace bsX86{

X86Generator::X86Generator()
{
	registers.push_back(RegType::REG_ECX);
	for (int i = RegType::REG_R8; i < RegType::REG_R15; i++)
	{
		registers.push_back(static_cast<RegType>(i));
	}
	registers.push_back(RegType::REG_EBX);
	for (auto& [r, b] : regAvailability) b = true;
}

void bsX86::X86Generator::generateX86(bsc::IR& ir)
{
	std::vector<bsc::IRFunction> functions = ir.PackFunctions();

	for (const auto& func : functions)
	{
		emitFunctionPrologue(func.name, func.GetLocalCount() * 4);
		currentFn = &func;

		for (const auto& tac : func.tacs)
		{
			analyzeIROperation(tac);
		}

		emitFunctionEpilogue();
		ReclaimAllRegisters();
	}

	/*for (const auto& tac : ir.getTACs())
	{
		analyzeIROperation(tac);
	}*/
}

std::string X86Generator::getOutput()
{
	return out.str();
}

void X86Generator::analyzeIROperation(const bsc::TAC& tac)
{
	bsc::IROpertion oper = tac.oper;
	
	if (tac.isUnary())
		emitUnaryOp(tac);
	else if(tac.isBinary())
		emitBinaryOp(tac);
	
	switch (oper)
	{
	case bsc::IROpertion::VAR_INIT:
	{
		INSTR_ARG dest, src;
		resolveTACArg(tac.arg1, dest, true);
		resolveTACArg(tac.arg2, src);
		out << "mov " << dest << ", " << src;
		out.endline();
		FreeReg(src.reg);
		break;
	}
	case bsc::IROpertion::PTR_LVAL:
		break;
	case bsc::IROpertion::PTR_RVAL:
		break;
	case bsc::IROpertion::LOAD_PTR:
		break;
	case bsc::IROpertion::STATIC_CAST:
		break;
	case bsc::IROpertion::REINTERPRET_CAST:
		break;
	case bsc::IROpertion::CALL:
		break;
	case bsc::IROpertion::RETURN:
	{
		INSTR_ARG src;
		resolveTACArg(tac.arg1, src);
		if (src.type != Instr_Arg_Type::REGISTER || src.reg.type != REG_EAX) {
			out << "mov eax, " << src;
			out.endline();
		}
		if (src.type == Instr_Arg_Type::REGISTER)
			FreeReg(src.reg);
		break;
	}
	case bsc::IROpertion::GOTO:
		break;
	case bsc::IROpertion::GOTO_IF_TRUE:
		break;
	case bsc::IROpertion::GOTO_IF_FALSE:
		break;
	case bsc::IROpertion::DECL_LABEL:
		break;
	case bsc::IROpertion::DECL_FN_ARG:
		break;
	case bsc::IROpertion::DECL_FN_PARAM:
		break;
	case bsc::IROpertion::DECL_VAR:
		break;
	case bsc::IROpertion::DECL_ARRAY:
		break;
	case bsc::IROpertion::DECL_FUNC:
		break;
	case bsc::IROpertion::DECL_GLOBL:
		break;
	default:
		break;
	}
}

void X86Generator::emitFunctionPrologue(const std::string& func, size_t stack_size)
{
	out.empty();
	out << "global " << func;
	out.endline();
	out << func << ":";
	out.endline();

	out.indent();

	out << "push ebp";
	out.endline();
	out << "mov ebp, esp";
	out.endline();

	if (stack_size > 0)
	{
		out << "sub esp, " << stack_size;
		out.endline();
	}
}

void X86Generator::emitFunctionEpilogue()
{
	out << "mov esp, ebp";
	out.endline();
	out << "pop ebp";
	out.endline();
	out << "ret";
	out.endline();

	out.unindent();
	out.empty();
}

void X86Generator::emitBinaryOp(const bsc::TAC& tac)
{
	INSTR_ARG dest, src1, src2;
	resolveTACArg(tac.arg1, dest, true);
	resolveTACArg(tac.arg2, src1);
	resolveTACArg(tac.arg3, src2);

	// 3 cases
	// 1. dest == src1 : operator dest, src2
	// 2. dest == src2 : operator dest, src1
	// 3. dest != src1 && dest != src2 : mov dest, src1; operator dest, src2

	if (tac.arg1.value == tac.arg2.value && tac.arg2.argType != bsc::IRARG::VALUE) {
		// nothing
	}
	else if (tac.arg1.value == tac.arg3.value && tac.arg3.argType != bsc::IRARG::VALUE) {
		std::swap(src1, src2);
	}
	else {
		out << "mov " << dest << ", " << src1;
		out.endline();
	}

	switch (tac.oper)
	{
	case bsc::IROpertion::ADD:
	{
		out << "add " << dest << ", " << src2;
		out.endline();
		break;
	}
	case bsc::IROpertion::SUB:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "sub " << dest << ", " << src2;
		out.endline();
		break;
	}
	case bsc::IROpertion::MUL:
	{
		auto eax = RequestRegister(bsX86::RegType::REG_EAX, tac.type);
		out << "mov " << eax << ", " << src1;
		out.endline();
		if (bsc::isSigned(tac.type))
			out << "imul " << src2;
		else
			out << "mul " << src2;
		out.endline();
		out << "mov " << dest << ", " << eax;
		out.endline();
		FreeReg(eax);
		out.endline();
		break;
	}
	case bsc::IROpertion::DIV:
	{
		auto eax = RequestRegister(bsX86::RegType::REG_EAX, tac.type);
		out << "mov " << eax << ", " << src1;
		out.endline();
		if (bsc::isSigned(tac.type))
			out << "idiv " << src2;
		else
			out << "div " << src2;
		out.endline();
		out << "mov " << dest << ", " << eax;
		out.endline();
		FreeReg(eax);
		out.endline();
		break;
	}
	case bsc::IROpertion::MOD:
	{
		auto eax = RequestRegister(bsX86::RegType::REG_EDX, tac.type);
		auto edx = RequestRegister(bsX86::RegType::REG_EAX, tac.type);
		out << "mov " << eax << ", " << src1;
		out.endline();
		if (bsc::isSigned(tac.type))
			out << "imul " << src2;
		else
			out << "mul " << src2;
		out.endline();
		out << "mov " << dest << ", " << edx;
		out.endline();
		FreeReg(eax);
		FreeReg(edx);
		out.endline();
		break;
	}
	case bsc::IROpertion::BITWISE_AND:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "and " << dest << ", " << src2;
		out.endline();
		break;
	}
	case bsc::IROpertion::BITWISE_OR:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "or " << dest << ", " << src2;
		out.endline();
		break;
	}
	case bsc::IROpertion::BITWISE_XOR:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "xor " << dest << ", " << src2;
		out.endline();
		break;
	}
	case bsc::IROpertion::SHIFT_LEFT:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		if (bsc::isSigned(tac.type))
			out << "sal " << dest << ", " << src2;
		else
			out << "shl " << dest << ", " << src2;
		out.endline();
		break;
	}
	case bsc::IROpertion::SHIFT_RIGHT:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		if (bsc::isSigned(tac.type))
			out << "sar " << dest << ", " << src2;
		else
			out << "shr " << dest << ", " << src2;
		out.endline();
		break;
	}
	case bsc::IROpertion::EQUAL:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "cmp " << dest << ", " << src2;
		out.endline();
		out << "sete " << dest;
		break;
	}
	case bsc::IROpertion::NOT_EQUAL:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "cmp " << dest << ", " << src2;
		out.endline();
		out << "setne " << dest;
		break;
	}
	case bsc::IROpertion::LESS:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "cmp " << dest << ", " << src2;
		out.endline();
		out << "setl " << dest;
		break;
	}
	case bsc::IROpertion::GREATER:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "cmp " << dest << ", " << src2;
		out.endline();
		out << "setg " << dest;
		break;
	}
	case bsc::IROpertion::LESS_EQUAL:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "cmp " << dest << ", " << src2;
		out.endline();
		out << "setle " << dest;
		break;
	}
	case bsc::IROpertion::GREATER_EQUAL:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "cmp " << dest << ", " << src2;
		out.endline();
		out << "setge " << dest;
		break;
	}
	case bsc::IROpertion::LOGICAL_AND:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "cmp " << dest << ", 0";
		out.endline();
		out << "setne " << dest;
		out.endline();
		out << "mov " << src1 << ", " << src2;
		out.endline();
		out << "cmp " << src1 << ", 0";
		out.endline();
		out << "setne " << src1;
		out.endline();
		out << "and " << dest << ", " << src1;
		break;
	}
	case bsc::IROpertion::LOGICAL_OR:
	{
		out << "mov " << dest << ", " << src1;
		out.endline();
		out << "cmp " << dest << ", 0";
		out.endline();
		out << "setne " << dest;
		out.endline();
		out << "mov " << src1 << ", " << src2;
		out.endline();
		out << "cmp " << src1 << ", 0";
		out.endline();
		out << "setne " << src1;
		out.endline();
		out << "or " << dest << ", " << src1;
		break;
	}
	}
}

void X86Generator::emitUnaryOp(const bsc::TAC& tac)
{
	INSTR_ARG arg1;
	resolveTACArg(tac.arg1, arg1);
	switch (tac.oper)
	{
	case bsc::IROpertion::UNARY_MINUS:
		out << "xor " << arg1 << ", -1";
		out.endline();
		break;
	case bsc::IROpertion::LOGICAL_NOT:
		out << "cmp " << arg1 << ", 0";
		out.endline();
		out << "sete " << arg1;
		out.endline();
		break;
	case bsc::IROpertion::BITWISE_NOT:
		out << "not " << arg1;
		out.endline();
		break;
	default:
		break;
	}
}

void X86Generator::resolveTACArg(const bsc::TAC_ARG& arg, INSTR_ARG& out_arg, bool isDest)
{
	if (arg.argType == bsc::IRARG::VALUE) {
		out_arg.imm = arg.value;
		out_arg.type = IMMEDIATE;
		return;
	}

	if (isDest && arg.argType == bsc::IRARG::VARIABLE) {
		std::string name = bsc::NAMERESOLVER::get().getID(arg.value);
		if (currentFn->HasLocal(name)) {
			if (keepVariablesInRegisters) {
				Register reg = GetReg(arg.type);
				out.empty();
				out << "; symbol " << name << " uses register " << reg;
				out.endline();
				out_arg.setAsRegister(reg);
				registerArgs[arg.value] = reg;
				return;
			}
			else {
				out_arg.type = Instr_Arg_Type::POINTER_WOFFSET;
				out_arg.reg.type = REG_EBP;
				out_arg.offset = currentFn->GetLocal(name).offset * 4;
				return;
			}
		}
		else {
			out_arg.type = Instr_Arg_Type::LABEL;
			out_arg.label = name;
			return;
		}
	}

	if (arg.argType == bsc::IRARG::VARIABLE) {
		if (registerArgs.count(arg.value) > 0) {
			out_arg.type = Instr_Arg_Type::REGISTER;
			out_arg.reg = registerArgs.at(arg.value);
			return;
		}

		std::string idName = bsc::NAMERESOLVER::get().getID(arg.value);
		if (currentFn->HasLocal(idName)) {

			if (keepVariablesInRegisters) {
				Register reg = GetReg(arg.type);
				if (currentFn->IsParam(idName)) {
					std::string crs = std::format("[ebp{}]", currentFn->GetLocal(idName).offset * 4);
					out << "mov " << reg << ", " << crs << "; pre-load fn parameter " << idName;
					out.endline();
				}
				else {
					out << "mov " << reg << ", [ebp" << std::format("{:+}", currentFn->GetLocal(idName).offset * 4) << "]" << "; pre-load symbol " << idName;
					out.endline();
				}
				registerArgs[arg.value] = reg;
				out_arg.setAsRegister(reg);
			}
			else
				out_arg.setAsPointerOffset(EBP_REG, currentFn->GetLocal(idName).offset * 4);
		}
		else
			out_arg.setAsLabel(idName); // Global variable

		return;
	}

	if (arg.argType == bsc::IRARG::TEMP) {
		if (registerArgs.count(arg.value) > 0) {
			out_arg.setAsRegister(registerArgs.at(arg.value));
			return;
		}
		Register reg = GetReg(arg.type);
		out_arg.setAsRegister(reg);
		registerArgs[arg.value] = reg;
		return;
	}
}

Register X86Generator::RequestRegister(Register reg)
{
	if (regAvailability[reg.type])
	{
		regAvailability[reg.type] = false;
		return reg;
	}
	else {
		out << "push " << reg.to_string();
		out.endline();
		INSTR_ARG arg;
		arg.setAsRegister(reg);
		stack.push_back(arg);
		return reg;
	}
}

Register X86Generator::RequestRegister(RegType regType, bsc::Type type)
{
	switch (type)
	{
	case bsc::Type::CHAR_t:
	case bsc::Type::UCHAR_t:
	{
		Register reg(regType, bsX86::RegSize::REG_8);
		return RequestRegister(reg);
	}
	case bsc::Type::INT_t:
	case bsc::Type::UINT_t:
	{
		Register reg(regType, bsX86::RegSize::REG_32);
		return RequestRegister(reg);
	}
	default:
		break;
	}
}

Register X86Generator::GetReg(bsX86::RegSize size)
{
	Register reg;
	reg.type = registers.back();
	reg.size = size;
	regAvailability[reg.type] = false;
	registers.pop_back();
	return reg;
}

Register bsX86::X86Generator::GetReg(bsc::Type type)
{
	switch (type)
	{
	case bsc::Type::CHAR_t:
	case bsc::Type::UCHAR_t:
		return GetReg(bsX86::RegSize::REG_8);
	case bsc::Type::INT_t:
	case bsc::Type::UINT_t:
		return GetReg(bsX86::RegSize::REG_32);
	default:
		break;
	}
}

void X86Generator::FreeReg(Register reg)
{
	if (!stack.empty() && stack.back().type == reg.type)
	{
		out << "pop " << reg.to_string();
		out.endline();
		stack.pop_back();
	}
	else
	{
		registers.push_back(reg.type);
		regAvailability[reg.type] = true;
	}
}

void X86Generator::ReclaimAllRegisters()
{
	for (const auto& [key, value] : registerArgs)
	{
		if (!regAvailability[value.type])
			registers.push_back(value.type);
		regAvailability[value.type] = true;
	}
}

void X86Generator::FreeTemporaryRegisters()
{
}


}