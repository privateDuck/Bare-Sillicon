#pragma once

#include <unordered_set>
#include <vector>
#include <format>
#include "ir_common.hpp"

namespace bsc {

	struct TrackedValue {
		long long value;
		size_t currentLine;
		bool isConst;
		bool wasUsed;
		bool isParam;
		Type type;
		IRARG valueType;
		std::vector<size_t> initialization;
		std::vector<size_t> assignments;
		TrackedValue() : value(0), currentLine(0), isConst(true), wasUsed(false), isParam(false), type(Type::INT_t), valueType(IRARG::VALUE) {}
		TrackedValue(long long value, size_t currentLine, Type type, IRARG vtype) : value(value), currentLine(currentLine), isConst(true), wasUsed(false), isParam(false), type(type), valueType(vtype) {}

		void removeLastAssignment() {
			if (assignments.size() > 0 && !isParam) {
				assignments.pop_back();
			}
		}
	};

	class IR {
	public:
		void OptimizationPass1();
		void RemoveUnreachableCode();
		void PropagateConstants();
		void TrackVariables();
		void DeadCodeElimination();
		void RemoveMarkedOperations();

		void RemoveRedundantUnaryOperators();
		void OptimizeDeclarations();

		std::string ConvertToString() const;

		// arg: operator argument
		void AddUnaryMinus(TAC_ARG arg);
		// arg: operator argument
		void AddLogicalNot(TAC_ARG arg);
		// arg: operator argument
		void AddBitwiseNot(TAC_ARG arg);

		// result = arg1 oper arg2
		void AddBinaryOp(TAC_ARG result, TAC_ARG arg1, TAC_ARG arg2, IROpertion oper);

		// arg1: variable, arg2: value
		void AddVariableDefinition(const std::string& name, TAC_ARG arg2, Type type);
		// arg1: pointer, arg2: rvalue ([arg1:type] = arg2)
		void AddPointerLValue(TAC_ARG arg1, TAC_ARG arg2, Type type);
		// arg1: lvalue, arg2: pointer (arg1 = [arg2:type])
		void AddPointerRValue(TAC_ARG arg1, TAC_ARG arg2, Type type);
		void AddLoadPointer(TAC_ARG result, const std::string& name, Type type);

		// arg1: casted value, arg2: value to cast, type: cast type
		void AddStaticCast(TAC_ARG arg1, TAC_ARG arg2, Type type);
		// arg1: casted value, arg2: value to cast, type: cast type
		void AddReinterpretCast(TAC_ARG arg1, TAC_ARG arg2, Type type);

		// arg1: destination, arg2: function name, arg3: no of arguments, type: return type
		void AddFunctionCall(TAC_ARG arg1, const std::string& name, int no_params, Type return_type);
		// arg1: return value, type: return type
		void AddReturn(TAC_ARG arg1, Type type);

		// arg1: label
		void AddGotoLabel(const std::string& label);
		// arg1: argument to check, arg2: label
		void AddGotoIfTrue(TAC_ARG arg1, const std::string& label);
		// arg1: argument to check, arg2: label
		void AddGotoIfFalse(TAC_ARG arg1, const std::string& label);

		// arg1: label
		void AddDeclareLabel(const std::string& name);
		// arg1: argument value, type: argument type
		void AddDeclareFunctionArgument(const std::string& name, Type type);
		// arg1: argument name, type: parameter type
		void AddDeclareFunctionParameter(const std::string& name, Type type);
		// arg1: variable name, type: variable type
		void AddDeclareVariable(const std::string& name, Type type);
		// arg1: array name, arg2: array size, type: array type
		void AddDeclareArray(const std::string& name, int size, Type type);
		// arg1: function name, arg2: no of parameters, type: return type
		void AddDeclareFunction(const std::string& name, int no_params, Type return_type);
		// arg1: name, arg2: initial value, type: type
		void AddDeclareGlobal(const std::string& name, long long value, Type type);
	private:
		std::vector<TAC> tacs;
		std::unordered_set<size_t> markers;
		//std::unordered_map<TAC_Temp, std::vector<size_t>> tempAssignmentMap;
		std::unordered_map<long long, TrackedValue> valueUsageMap;
		void moveLine(size_t from, size_t to);
		TrackedValue& getTrackedValue(const TAC_ARG& arg);
		const TrackedValue& getTrackedValue(const TAC_ARG& arg) const;
		TrackedValue& tryAddTrackedValue(const TAC_ARG& arg, size_t current);
		long long computeArgumentValue(TAC_ARG& arg);
		long long computeBinaryOpertion(long long arg1, long long arg2, IROpertion oper);
		long long computeUnaryOpertion(long long arg, IROpertion oper);
		bool checkArgConst(const TAC_ARG& arg) const;
	};

}; // namespace bsc