#pragma once

#include "../bs_IR/ir_common.hpp"
#include "../bs_IR/ir.hpp"
#include "x86_common.hpp"
#include "../bs_common/indentedstream.hpp"


namespace bsX86 {

	class X86Generator {
	public:
		X86Generator();
		~X86Generator() = default;

		void generateX86(bsc::IR &ir);
		std::string getOutput();

	private:
		void analyzeIROperation(const bsc::TAC& tac);

		void emitFunctionPrologue(const std::string& func);
		void emitFunctionEpilogue();
		void emitBinaryOp(const bsc::TAC& tac);
		void emitUnaryOp(const bsc::TAC& tac);

		void resolveTACArg(const bsc::TAC_ARG& arg, INSTR_ARG& out, bool isDest = false);

		Register RequestRegister(Register reg);
		Register RequestRegister(RegType regType, bsc::Type type);

		Register GetReg(bsX86::RegSize size);
		Register GetReg(bsc::Type type);
		void FreeReg(Register reg);
		void ReclaimAllRegisters();

		int currentStackSize = 0;
		int currentStackOffset = 0;
		bool keepVariablesInRegisters = false;
		std::vector<RegType> registers;
		std::unordered_map<std::string, int> stackVars;
		std::unordered_map<RegType, bool> regAvailability;
		std::unordered_map<long long, Register> registerArgs;
		std::vector<INSTR_ARG> stack;

		IndentedStream out;
	};

} // namespace bsX86

/*
		// arg: operator argument
		void IUnaryMinus(const INSTR_ARG& arg);
		// arg: operator argument
		void ILogicalNot(const INSTR_ARG& arg);
		// arg: operator argument
		void IBitwiseNot(const INSTR_ARG& arg);

		// arg1: variable, arg2: value
		void IVariableDefinition(const INSTR_ARG& arg1, const INSTR_ARG& arg2);
		// arg1: pointer, arg2: rvalue ([arg1:type] = arg2)
		void IPointerLValue(const INSTR_ARG& arg1, const INSTR_ARG& arg2);
		// arg1: lvalue, arg2: pointer (arg1 = [arg2:type])
		void IPointerRValue(const INSTR_ARG& arg1, const INSTR_ARG& arg2);

		// arg1: casted value, arg2: value to cast, type: cast type
		void IStaticCast(const INSTR_ARG& arg1, const INSTR_ARG& arg2);
		// arg1: casted value, arg2: value to cast, type: cast type
		void IReinterpretCast(const INSTR_ARG& arg1, const INSTR_ARG& arg2);

		// arg1: destination, arg2: function name, arg3: no of arguments, type: return type
		void IFunctionCall(const INSTR_ARG& arg1, const INSTR_ARG& arg2, const INSTR_ARG& arg3);
		// arg1: return value, type: return type
		void IReturn(const INSTR_ARG& arg1);

		// arg1: label
		void IGotoLabel(const INSTR_ARG& arg1);
		// arg1: argument to check, arg2: label
		void IGotoIfTrue(const INSTR_ARG& arg1, const INSTR_ARG& arg2);
		// arg1: argument to check, arg2: label
		void IGotoIfFalse(const INSTR_ARG& arg1, const INSTR_ARG& arg2);

		// arg1: label
		void IDeclareLabel(const INSTR_ARG& arg1);
		// arg1: argument value, type: argument type
		void IDeclareFunctionArgument(const INSTR_ARG& arg1);
		// arg1: argument name, type: parameter type
		void IDeclareFunctionParameter(const INSTR_ARG& arg1);
		// arg1: variable name, type: variable type
		void IDeclareVariable(const INSTR_ARG& arg1);
		// arg1: array name, arg2: array size, type: array type
		void IDeclareArray(const INSTR_ARG& arg1, const INSTR_ARG& arg2);
		// arg1: function name, arg2: no of parameters, type: return type
		void IDeclareFunction(const INSTR_ARG& arg1, const INSTR_ARG& arg2);
		*/