#include "ir_common.hpp"

namespace bsc {
std::string TAC::to_string() const
{
	switch (oper)
	{
	case bsc::IROpertion::UNARY_MINUS:
		return std::format("{} = -{}", arg1.get(), arg2.get());
	case bsc::IROpertion::LOGICAL_NOT:
		return std::format("{} = !{}", arg1.get(), arg2.get());
	case bsc::IROpertion::BITWISE_NOT:
		return std::format("{} = ~{}", arg1.get(), arg2.get());
	case bsc::IROpertion::ADD:
		return std::format("{} = {} + {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::SUB:
		return std::format("{} = {} - {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::MUL:
		return std::format("{} = {} * {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::DIV:
		return std::format("{} = {} / {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::MOD:
		return std::format("{} = {} % {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::BITWISE_AND:
		return std::format("{} = {} & {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::BITWISE_OR:
		return std::format("{} = {} | {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::BITWISE_XOR:
		return std::format("{} = {} ^ {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::SHIFT_LEFT:
		return std::format("{} = {} << {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::SHIFT_RIGHT:
		return std::format("{} = {} >> {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::EQUAL:
		return std::format("{} = {} == {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::NOT_EQUAL:
		return std::format("{} = {} != {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::LESS:
		return std::format("{} = {} < {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::GREATER:
		return std::format("{} = {} > {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::LESS_EQUAL:
		return std::format("{} = {} <= {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::GREATER_EQUAL:
		return std::format("{} = {} >= {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::LOGICAL_AND:
		return std::format("{} = {} && {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::LOGICAL_OR:
		return std::format("{} = {} || {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::VAR_INIT:
		return std::format("{} = {}", arg1.get(), arg2.get());
	case bsc::IROpertion::PTR_LVAL:
		return std::format("[{}:{}] = {}", arg1.get(), getTypeName(type), arg2.get());
	case bsc::IROpertion::PTR_RVAL:
		return std::format("{} = [{}:{}]", arg1.get(), arg2.get(), getTypeName(type));
	case bsc::IROpertion::LOAD_PTR:
		return std::format("{} = load ptr {}", arg1.get(), arg2.get());
	case bsc::IROpertion::STATIC_CAST:
		return std::format("{} = cast_to_{}({})", arg1.get(), getTypeName(type), arg2.get());
	case bsc::IROpertion::REINTERPRET_CAST:
		return std::format("{} = reinterpret_as_{}({})", arg1.get(), getTypeName(type), arg2.get());
	case bsc::IROpertion::CALL:
		return std::format("{} = call {}, {}", arg1.get(), arg2.get(), arg3.get());
	case bsc::IROpertion::RETURN:
		return std::format("return {}", arg1.get());
	case bsc::IROpertion::GOTO:
		return std::format("goto {}", arg1.get());
	case bsc::IROpertion::GOTO_IF_TRUE:
		return std::format("ifTrue {} goto {}", arg1.get(), arg2.get());
	case bsc::IROpertion::GOTO_IF_FALSE:
		return std::format("ifFalse {} goto {}", arg1.get(), arg2.get());
	case bsc::IROpertion::DECL_LABEL:
		return std::format("{}:", arg1.get());
	case bsc::IROpertion::DECL_FN_ARG:
		return std::format("arg: {} {}", arg1.get(), getTypeName(type));
	case bsc::IROpertion::DECL_FN_PARAM:
		return std::format("param: {} {}", arg1.get(), getTypeName(type));
	case bsc::IROpertion::DECL_VAR:
		return std::format("local: {} {}", arg1.get(), getTypeName(type));
	case bsc::IROpertion::DECL_ARRAY:
		return std::format("array: {} [{}] {}", arg1.get(), arg2.get(), getTypeName(type));
	case bsc::IROpertion::DECL_FUNC:
		return std::format("func: {} {} returns {}", arg1.get(), arg2.get(), getTypeName(type));
	case bsc::IROpertion::DECL_GLOBL:
		return std::format("globl: {} {} {}", arg1.get(), arg2.get(), getTypeName(type));
	default:
		break;
	}
	return std::string();
}

TAC TAC::IUnaryMinus(TAC_ARG arg)
{
	return TAC(arg.type, IROpertion::UNARY_MINUS, arg);
}

TAC TAC::ILogicalNot(TAC_ARG arg)
{
	return TAC(arg.type, IROpertion::LOGICAL_NOT, arg);
}

TAC TAC::IBitwiseNot(TAC_ARG arg)
{
	return TAC(arg.type, IROpertion::BITWISE_NOT, arg);
}

TAC TAC::IBinaryOp(TAC_ARG result, TAC_ARG arg1, TAC_ARG arg2, IROpertion oper)
{
	return TAC(result.type, oper, result, arg1, arg2);
}

TAC TAC::IVariableDefinition(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	return TAC(type, IROpertion::VAR_INIT, arg1, arg2);
}

TAC TAC::IPointerLValue(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	return TAC(type, IROpertion::PTR_LVAL, arg1, arg2);
}

TAC TAC::IPointerRValue(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	return TAC(type, IROpertion::PTR_RVAL, arg1, arg2);
}

TAC TAC::IStaticCast(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	return TAC(type, IROpertion::STATIC_CAST, arg1, arg2);
}

TAC TAC::IReinterpretCast(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	return TAC(type, IROpertion::REINTERPRET_CAST, arg1, arg2);
}

TAC TAC::IFunctionCall(TAC_ARG arg1, TAC_ARG arg2, TAC_ARG arg3, Type type)
{
	return TAC(type, IROpertion::CALL, arg1, arg2, arg3);
}

TAC TAC::IReturn(TAC_ARG arg1, Type type)
{
	return TAC(type, IROpertion::RETURN, arg1);
}

TAC TAC::IGotoLabel(TAC_ARG arg1)
{
	return TAC(Type::INT_t, IROpertion::GOTO, arg1);
}

TAC TAC::IGotoIfTrue(TAC_ARG arg1, TAC_ARG arg2)
{
	return TAC(Type::INT_t, IROpertion::GOTO_IF_TRUE, arg1, arg2);
}

TAC TAC::IGotoIfFalse(TAC_ARG arg1, TAC_ARG arg2)
{
	return TAC(Type::INT_t, IROpertion::GOTO_IF_FALSE, arg1, arg2);
}

TAC TAC::IDeclareLabel(TAC_ARG arg1)
{
	return TAC(Type::INT_t, IROpertion::DECL_LABEL, arg1);
}

TAC TAC::IDeclareFunctionArgument(TAC_ARG arg1, Type type)
{
	return TAC(type, IROpertion::DECL_FN_ARG, arg1);
}

TAC TAC::IDeclareFunctionParameter(TAC_ARG arg1, Type type)
{
	return TAC(type, IROpertion::DECL_FN_PARAM, arg1);
}

TAC TAC::IDeclareVariable(TAC_ARG arg1, Type type)
{
	return TAC(type, IROpertion::DECL_VAR, arg1);
}

TAC TAC::IDeclareArray(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	return TAC(type, IROpertion::DECL_ARRAY, arg1, arg2);
}

TAC TAC::IDeclareFunction(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	return TAC(type, IROpertion::DECL_FUNC, arg1, arg2);
}


NAMERESOLVER& NAMERESOLVER::get()
{
	static NAMERESOLVER _inst;
	return _inst;
}

void NAMERESOLVER::clear()
{
	rmap.clear();
	map.clear();
	counter = 32;
}

const std::string& NAMERESOLVER::getID(long long index) const
{
	return map.at(index);
}

long long NAMERESOLVER::registerID(const std::string& name)
{
	if (rmap.count(name) == 0) {
		map[counter] = name;
		rmap[name] = counter;
		counter++;
		return counter - 1;
	}
	return rmap.at(name);
}

void TAC_ARG::setAsVariable(const std::string& name, Type type)
{
	value = NAMERESOLVER::get().registerID(name);
	this->type = type;
	argType = IRARG::VARIABLE;
}

void TAC_ARG::setAsIRTemporary(TAC_Temp temp, Type type)
{
	value = temp.index;
	this->type = type;
	argType = IRARG::TEMP;
}

void TAC_ARG::setAsConstant(long long value, Type type)
{
	this->value = value;
	this->type = type;
	argType = IRARG::VALUE;
}

TAC_ARG TAC_ARG::getAsVariable(const std::string& name, Type type)
{
	TAC_ARG tac;
	tac.setAsVariable(name, type);
	return tac;
}

TAC_ARG TAC_ARG::getAsIRTemporary(TAC_Temp temp, Type type)
{
	TAC_ARG tac;
	tac.setAsIRTemporary(temp, type);
	return tac;
}

TAC_ARG TAC_ARG::getAsConstant(long long value, Type type)
{
	TAC_ARG tac;
	tac.setAsConstant(value, type);
	return tac;
}

};