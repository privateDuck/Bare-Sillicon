#include "ir.hpp"
#include "../bs_common/indentedstream.hpp"

namespace bsc
{
void IR::OptimizationPass1()
{
	// Change grammar to eliminate signed number matching
	// OptimizeDeclarations();
	RemoveUnreachableCode();
	RemoveMarkedOperations();
	PropagateConstants();
	TrackVariables();
	DeadCodeElimination();
	RemoveMarkedOperations();
}

void IR::RemoveUnreachableCode()
{
	bool passedReturn = false, passedUncondJump = false;

	for (size_t i = 0; i < tacs.size(); i++)
	{
		const TAC& tac = tacs[i];

		if (tac.oper == IROpertion::GOTO) passedUncondJump = true;
		if (passedReturn || passedUncondJump) markers.insert(i);
		
		if (tac.oper == IROpertion::RETURN) passedReturn = true;
		else if (tac.oper == IROpertion::DECL_FN_PARAM) passedReturn = false;
		else if (tac.oper == IROpertion::DECL_LABEL) passedUncondJump = false;
	}
}

void IR::PropagateConstants()
{
	for (size_t i = 0; i < tacs.size(); i++)
	{
		const TAC& tac = tacs[i];
		if (tac.isUnary()) {
			auto& vt = tryAddTrackedValue(tac.arg1, i);
			vt.isConst = checkArgConst(tac.arg2);
			vt.value = computeUnaryOpertion(tac.arg2.value, tac.oper);
		}
		else if (tac.isBinary()) {
			auto& vt = tryAddTrackedValue(tac.arg1, i);
			vt.isConst = checkArgConst(tac.arg2) && checkArgConst(tac.arg3);
			vt.value = computeBinaryOpertion(tac.arg2.value, tac.arg3.value, tac.oper);
		}
		else if (tac.oper == IROpertion::VAR_INIT) {
			auto& vt = tryAddTrackedValue(tac.arg1, i);
			vt.value = tac.arg2.value;
			vt.isConst = checkArgConst(tac.arg2);
		}
		else if (tac.oper == IROpertion::DECL_FN_PARAM) {
			auto& vt = tryAddTrackedValue(tac.arg1, i);
			vt.value = 0;
			vt.isConst = false;
			vt.isParam = true;
		}
	}
}

void IR::TrackVariables()
{
	bool inside_var_init = false;
	std::vector<size_t> var_init;
	for (size_t i = 0; i < tacs.size(); i++)
	{
		const TAC& tac = tacs[i];
		IROpertion oper = tac.oper;
		if (inside_var_init)
			var_init.emplace_back(i);

		switch (oper)
		{
		case bsc::IROpertion::VAR_INIT:
		{
			auto& vt = getTrackedValue(tac.arg1);
			inside_var_init = false;
			vt.initialization = std::vector<size_t>(var_init.begin(), var_init.end());
			var_init.clear();
			break;
		}
		case bsc::IROpertion::DECL_FN_PARAM:
			break;
		case bsc::IROpertion::DECL_VAR:
			inside_var_init = true;
			var_init.push_back(i);
			break;
		case bsc::IROpertion::DECL_ARRAY:
			break;
		default:
			break;
		}
		if (tac.isBinary()) {
			if (tac.arg2.argType != IRARG::VALUE) {
				auto& vt = getTrackedValue(tac.arg2);
				vt.wasUsed = true;
				vt.removeLastAssignment();
			}
			if (tac.arg3.argType != IRARG::VALUE) {
				auto& vt = getTrackedValue(tac.arg3);
				vt.wasUsed = true;
				vt.removeLastAssignment();
			}
			if (tac.arg1.argType != IRARG::VALUE && !inside_var_init) {
				auto& vt = getTrackedValue(tac.arg1);
				vt.assignments.push_back(i);
				vt.wasUsed = false;
			}
		}
		else if (tac.isUnary()) {
			if (tac.arg2.argType != IRARG::VALUE) {
				auto& vt = getTrackedValue(tac.arg2);
				vt.wasUsed = true;
				vt.removeLastAssignment();
			}
			if (tac.arg1.argType != IRARG::VALUE && !inside_var_init) {
				auto& vt = getTrackedValue(tac.arg1);
				vt.assignments.push_back(i);
				vt.wasUsed = false;
			}
		}
		else if (tac.oper == IROpertion::VAR_INIT) {
			if (tac.arg2.argType != IRARG::VALUE) {
				auto& vt = getTrackedValue(tac.arg2);
				vt.wasUsed = true;
				vt.removeLastAssignment();
			}
		}
	}
}

void IR::DeadCodeElimination()
{
	bool passedReturn = false, passedUncondJump = false;
	// Remove redundant assignments
	for (const auto& [index, tracker] : valueUsageMap) {
		std::copy(tracker.assignments.begin(), tracker.assignments.end(), std::inserter(markers, markers.end()));
		if (!tracker.wasUsed && tracker.valueType == IRARG::VARIABLE) std::copy(tracker.initialization.begin(), tracker.initialization.end(), std::inserter(markers, markers.end()));
	}
}

void IR::RemoveMarkedOperations()
{
	std::vector<TAC> copy;
	for (size_t i = 0; i < tacs.size(); i++)
	{
		if (markers.count(i) == 0) copy.emplace_back(tacs[i]);
	}
	tacs.clear();
	tacs.reserve(copy.size());
	tacs.insert(tacs.end(), copy.begin(), copy.end());
}

void IR::RemoveRedundantUnaryOperators()
{
	for (size_t i = 0; i < tacs.size(); i++)
	{
		const TAC& tac = tacs[i];
		if (tac.oper == IROpertion::UNARY_MINUS)
		{
			if (tacs[i + 1].oper == IROpertion::UNARY_MINUS)
			{
				tacs.erase(tacs.begin() + i + 1);
				tacs.erase(tacs.begin() + i);
				--i;
			}
		}
		else if (tac.oper == IROpertion::BITWISE_NOT) {
			if (tacs[i + 1].oper == IROpertion::BITWISE_NOT)
			{
				tacs.erase(tacs.begin() + i + 1);
				tacs.erase(tacs.begin() + i);
				--i;
			}
		}
	}
}

void IR::OptimizeDeclarations()
{
	size_t func_idx = 0;
	for (size_t i = 0; i < tacs.size(); i++)
	{
		const TAC& tac = tacs[i];
		if (tac.oper == IROpertion::DECL_FUNC) {
			func_idx = i+1;
		}
		else if (tac.oper == IROpertion::DECL_VAR && (tacs[i - 1].oper != IROpertion::DECL_FUNC || tacs[i - 1].oper != IROpertion::DECL_VAR)) {
			moveLine(i, func_idx);
			func_idx++;
		}
	}
}

std::string IR::ConvertToString() const
{
	IndentedStream istr;
	istr.indent();
	for (const TAC& tac : tacs)
	{
		if (tac.isLabel()) istr.unindent();
		istr << tac.to_string();
		istr.endline();
		if (tac.isLabel()) istr.indent();
	}
	istr.unindent();
	return istr.str();
}

void IR::AddUnaryMinus(TAC_ARG arg)
{
	tacs.emplace_back(arg.type, IROpertion::UNARY_MINUS, arg);
}

void IR::AddLogicalNot(TAC_ARG arg)
{
	tacs.emplace_back(arg.type, IROpertion::LOGICAL_NOT, arg);
}

void IR::AddBitwiseNot(TAC_ARG arg)
{
	tacs.emplace_back(arg.type, IROpertion::BITWISE_NOT, arg);
}

void IR::AddBinaryOp(TAC_ARG result, TAC_ARG arg1, TAC_ARG arg2, IROpertion oper)
{
	tacs.emplace_back(result.type, oper, result, arg1, arg2);
}

void IR::AddVariableDefinition(const std::string& name, TAC_ARG arg2, Type type)
{
	tacs.emplace_back(type, IROpertion::VAR_INIT, TAC_ARG::getAsVariable(name, Type::INT_t), arg2);
}

void IR::AddPointerLValue(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	tacs.emplace_back(type, IROpertion::PTR_LVAL, arg1, arg2);
}

void IR::AddPointerRValue(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	tacs.emplace_back(type, IROpertion::PTR_RVAL, arg1, arg2);
}

void IR::AddLoadPointer(TAC_ARG result, const std::string& name, Type type)
{
	tacs.emplace_back(Type::UINT_t, IROpertion::LOAD_PTR, result, TAC_ARG::getAsVariable(name, type));
}

void IR::AddStaticCast(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	tacs.emplace_back(type, IROpertion::STATIC_CAST, arg1, arg2);
}

void IR::AddReinterpretCast(TAC_ARG arg1, TAC_ARG arg2, Type type)
{
	tacs.emplace_back(type, IROpertion::REINTERPRET_CAST, arg1, arg2);
}

void IR::AddFunctionCall(TAC_ARG arg1, const std::string& name, int no_params, Type return_type)
{
	tacs.emplace_back(return_type, IROpertion::CALL, arg1, TAC_ARG::getAsVariable(name, return_type), TAC_ARG::getAsConstant(no_params, return_type));
}

void IR::AddReturn(TAC_ARG arg1, Type type)
{
	tacs.emplace_back(type, IROpertion::RETURN, arg1);
}

void IR::AddGotoLabel(const std::string& label)
{
	tacs.emplace_back(Type::INT_t, IROpertion::GOTO, TAC_ARG::getAsVariable(label,Type::INT_t));
}

void IR::AddGotoIfTrue(TAC_ARG arg1, const std::string& label)
{
	tacs.emplace_back(Type::INT_t, IROpertion::GOTO_IF_TRUE, arg1, TAC_ARG::getAsVariable(label, Type::INT_t));
}

void IR::AddGotoIfFalse(TAC_ARG arg1, const std::string& label)
{
	tacs.emplace_back(Type::INT_t, IROpertion::GOTO_IF_FALSE, arg1, TAC_ARG::getAsVariable(label, Type::INT_t));
}

void IR::AddDeclareLabel(const std::string& name)
{
	tacs.emplace_back(Type::INT_t, IROpertion::DECL_LABEL, TAC_ARG::getAsVariable(name, Type::INT_t));
}

void IR::AddDeclareFunctionArgument(const std::string& name, Type type)
{
	tacs.emplace_back(type, IROpertion::DECL_FN_ARG, TAC_ARG::getAsVariable(name, Type::INT_t));
}

void IR::AddDeclareFunctionParameter(const std::string& name, Type type)
{
	tacs.emplace_back(type, IROpertion::DECL_FN_PARAM, TAC_ARG::getAsVariable(name, Type::INT_t));
}

void IR::AddDeclareVariable(const std::string& name, Type type)
{
	tacs.emplace_back(type, IROpertion::DECL_VAR, TAC_ARG::getAsVariable(name, Type::INT_t));
}

void IR::AddDeclareArray(const std::string& name, int size, Type type)
{
	tacs.emplace_back(type, IROpertion::DECL_ARRAY, TAC_ARG::getAsVariable(name, Type::INT_t), TAC_ARG::getAsConstant(size,type));
}

void IR::AddDeclareFunction(const std::string& name, int param_count, Type type)
{
	tacs.emplace_back(type, IROpertion::DECL_FUNC, TAC_ARG::getAsVariable(name, Type::INT_t), TAC_ARG::getAsConstant(param_count, type));
}

void IR::AddDeclareGlobal(const std::string& name, long long value, Type type)
{
	tacs.emplace_back(type, IROpertion::DECL_GLOBL, TAC_ARG::getAsVariable(name, Type::INT_t), TAC_ARG::getAsConstant(value, type));
}

void IR::moveLine(size_t from, size_t to) {
	if (from >= tacs.size() || to >= tacs.size()) {
		return;
	}
	TAC line = tacs[from]; // Copy the line
	tacs.erase(tacs.begin() + from); // Remove the line
	tacs.insert(tacs.begin() + to, line); // Insert it at the new position
}

TrackedValue& IR::getTrackedValue(const TAC_ARG& arg)
{
	if (arg.argType == IRARG::VALUE) throw std::runtime_error("Illegal operation");

	return valueUsageMap.at(arg.value);
}

const TrackedValue& IR::getTrackedValue(const TAC_ARG& arg) const
{
	if (arg.argType == IRARG::VALUE) throw std::runtime_error("Illegal operation");

	return valueUsageMap.at(arg.value);
}

TrackedValue& IR::tryAddTrackedValue(const TAC_ARG& arg, size_t current)
{
	if (arg.argType == IRARG::VALUE) throw std::runtime_error("Illegal operation");
	if (valueUsageMap.count(arg.value) > 0) return valueUsageMap.at(arg.value);
	TrackedValue& vt = valueUsageMap[arg.value] = TrackedValue(0, current, arg.type, arg.argType);
	return vt;
}

long long IR::computeArgumentValue(TAC_ARG& arg)
{
	switch (arg.argType)
	{
	case IRARG::VALUE:
		return arg.value;
	case IRARG::VARIABLE:
		return getTrackedValue(arg).value;
	case IRARG::TEMP:
		return 0;
	default:
		break;
	}
}

long long IR::computeBinaryOpertion(long long arg1, long long arg2, IROpertion oper)
{
	switch (oper)
	{
	case bsc::IROpertion::ADD:
		return arg1 + arg2;
	case bsc::IROpertion::SUB:
		return arg1 - arg2;
	case bsc::IROpertion::MUL:
		return arg1 * arg2;
	case bsc::IROpertion::DIV:
		return arg1 / arg2;
	case bsc::IROpertion::MOD:
		return arg1 % arg2;
	case bsc::IROpertion::BITWISE_AND:
		return arg1 & arg2;
	case bsc::IROpertion::BITWISE_OR:
		return arg1 | arg2;
	case bsc::IROpertion::BITWISE_XOR:
		return arg1 ^ arg2;
	case bsc::IROpertion::SHIFT_LEFT:
		return arg1 << arg2;
	case bsc::IROpertion::SHIFT_RIGHT:
		return arg1 >> arg2;
	case bsc::IROpertion::EQUAL:
		return arg1 == arg2;
	case bsc::IROpertion::NOT_EQUAL:
		return arg1 != arg2;
	case bsc::IROpertion::LESS:
		return arg1 < arg2;
	case bsc::IROpertion::GREATER:
		return arg1 > arg2;
	case bsc::IROpertion::LESS_EQUAL:
		return arg1 <= arg2;
	case bsc::IROpertion::GREATER_EQUAL:
		return arg1 >= arg2;
	case bsc::IROpertion::LOGICAL_AND:
		return arg1 && arg2;
	case bsc::IROpertion::LOGICAL_OR:
		return arg1 || arg2;
	default:
		return 0;
	}
}

long long IR::computeUnaryOpertion(long long arg, IROpertion oper)
{
switch (oper)
	{
	case bsc::IROpertion::UNARY_MINUS:
		return -arg;
	case bsc::IROpertion::LOGICAL_NOT:
		return !arg;
	case bsc::IROpertion::BITWISE_NOT:
		return ~arg;
	default:
		return 0;
	}
}

bool IR::checkArgConst(const TAC_ARG& arg) const
{
	if (arg.argType == IRARG::VALUE) return true;
	return getTrackedValue(arg).isConst;
}

};