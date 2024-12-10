#pragma once

#include <string>
#include <format>
#include <sstream>
#include "../bs_common/types.hpp"

namespace bsc{

// operators
enum class IROpertion {
	// Unary operators
	UNARY_MINUS,	 // r = 0 - a
	LOGICAL_NOT,	 // r = a == 0
	BITWISE_NOT,	 // r = a ^ 0xFFFF/0xFFFFFFFF
	// Binary operators
	ADD,			 // r = a + b
	SUB,			 // r = a - b
	MUL,			 // r = a * b
	DIV,			 // r = a / b
	MOD,			 // r = a % b
	BITWISE_AND,	 // r = a & b
	BITWISE_OR,		 // r = a | b
	BITWISE_XOR,	 // r = a ^ b
	SHIFT_LEFT,		 // r = a << b
	SHIFT_RIGHT,	 // r = a >> b
	EQUAL,			 // r = a == b
	NOT_EQUAL,		 // r = a != b
	LESS,			 // r = a < b
	GREATER,		 // r = a > b
	LESS_EQUAL,		 // r = a <= b
	GREATER_EQUAL,	 // r = a >= b
	LOGICAL_AND,	 // r = a && b
	LOGICAL_OR,		 // r = a || b
	// Memory access operations
	VAR_INIT,		 // a = b
	PTR_LVAL,		 // [a:t] = b
	PTR_RVAL,		 // a = [b:t]
	LOAD_PTR,		 // a = &b
	// Type casting
	STATIC_CAST,	 // r = cast_to_type a
	REINTERPRET_CAST,// r = reinterpret_as_type a
	// Control flow
	CALL,			 // r = call name, no_of_args
	RETURN,			 // return a
	GOTO,			 // goto label
	GOTO_IF_TRUE,	 // if_true a goto label
	GOTO_IF_FALSE,	 // if_false a goto label
	// Declarations	 
	DECL_LABEL,		 // label:
	DECL_FN_ARG,	 // arg: a
	DECL_FN_PARAM,	 // param: a
	DECL_VAR,		 // local: int a
	DECL_ARRAY,		 // local_array: int a[10]
	DECL_FUNC,		 // func: name, return_type, no_of_params
	DECL_GLOBL		 // globl: name value
};



enum class IRARG {
	TEMP,
	VALUE,
	VARIABLE
};

class NAMERESOLVER {
public:
	static NAMERESOLVER& get();
	void clear();
	const std::string& getID(long long index) const;
	long long registerID(const std::string& name);
private:
	std::unordered_map<long long, std::string> map;
	std::unordered_map<std::string, long long> rmap;

	long long counter = 32;
	NAMERESOLVER() {}
	~NAMERESOLVER() {}
	NAMERESOLVER& operator=(const NAMERESOLVER&) = delete;
	NAMERESOLVER(const NAMERESOLVER&) = delete;
};

struct TAC_Temp {
	int index;
	TAC_Temp() : index(-1) {}
	explicit TAC_Temp(int i) : index(i) {}
};

struct TAC_ARG {
	Type type;
	IRARG argType;
	long long value;

	TAC_ARG() : type(Type::INT_t), argType(IRARG::TEMP), value(0) {}
	//TAC_ARG(Type type, IRARG argType, const std::string& name, TAC_Temp tmp, long long value) : type(type), argType(argType), name(name), tmp(tmp), value(value) {}
	void setAsVariable(const std::string& name, Type type);
	void setAsIRTemporary(TAC_Temp temp, Type type);
	void setAsConstant(long long value, Type type);

	static TAC_ARG getAsVariable(const std::string& name, Type type);
	static TAC_ARG getAsIRTemporary(TAC_Temp temp, Type type);
	static TAC_ARG getAsConstant(long long value, Type type);

	std::string get() const {
		switch (argType)
		{
		case bsc::IRARG::TEMP:
			return std::format("$t{}", value);
		case bsc::IRARG::VALUE:
			return std::to_string(value);
		case bsc::IRARG::VARIABLE:
			return NAMERESOLVER::get().getID(value);
		default:
			break;
		}
	}

	friend std::ostringstream& operator<<(std::ostringstream& os, const TAC_ARG& tmp) {
		os << tmp.get();
		return os;
	}
};


struct TAC {
	Type type;
	IROpertion oper;
	TAC_ARG arg1;
	TAC_ARG arg2;
	TAC_ARG arg3;

	TAC() : type(Type::INT_t), oper(IROpertion::ADD), arg1(TAC_ARG()), arg2(TAC_ARG()), arg3(TAC_ARG()) {}
	TAC(Type type, IROpertion oper, TAC_ARG arg1) : type(type), oper(oper), arg1(arg1), arg2(), arg3() {}
	TAC(Type type, IROpertion oper, TAC_ARG arg1, TAC_ARG arg2) : type(type), oper(oper), arg1(arg1), arg2(arg2), arg3() {}
	TAC(Type type, IROpertion oper, TAC_ARG arg1, TAC_ARG arg2, TAC_ARG arg3) : type(type), oper(oper), arg1(arg1), arg2(arg2), arg3(arg3) {}

	constexpr bool isUnary() const {
		return oper < IROpertion::ADD;
	}

	constexpr bool isBinary() const {
		return oper >= IROpertion::ADD && oper <= IROpertion::LOGICAL_OR;
	}

	constexpr bool isDeclaration() const {
		return oper > IROpertion::DECL_LABEL && oper <= IROpertion::DECL_FUNC;
	}

	constexpr bool isLabel() const {
		return oper == IROpertion::DECL_LABEL;
	}

	std::string to_string() const;

	// arg: operator argument
	static TAC IUnaryMinus(TAC_ARG arg);
	// arg: operator argument
	static TAC ILogicalNot(TAC_ARG arg);
	// arg: operator argument
	static TAC IBitwiseNot(TAC_ARG arg);

	// result = arg1 oper arg2
	static TAC IBinaryOp(TAC_ARG result, TAC_ARG arg1, TAC_ARG arg2, IROpertion oper);

	// arg1: variable, arg2: value
	static TAC IVariableDefinition(TAC_ARG arg1, TAC_ARG arg2, Type type);
	// arg1: pointer, arg2: rvalue ([arg1:type] = arg2)
	static TAC IPointerLValue(TAC_ARG arg1, TAC_ARG arg2, Type type);
	// arg1: lvalue, arg2: pointer (arg1 = [arg2:type])
	static TAC IPointerRValue(TAC_ARG arg1, TAC_ARG arg2, Type type);

	// arg1: casted value, arg2: value to cast, type: cast type
	static TAC IStaticCast(TAC_ARG arg1, TAC_ARG arg2, Type type);
	// arg1: casted value, arg2: value to cast, type: cast type
	static TAC IReinterpretCast(TAC_ARG arg1, TAC_ARG arg2, Type type);

	// arg1: destination, arg2: function name, arg3: no of arguments, type: return type
	static TAC IFunctionCall(TAC_ARG arg1, TAC_ARG arg2, TAC_ARG arg3, Type type);
	// arg1: return value, type: return type
	static TAC IReturn(TAC_ARG arg1, Type type);

	// arg1: label
	static TAC IGotoLabel(TAC_ARG arg1);
	// arg1: argument to check, arg2: label
	static TAC IGotoIfTrue(TAC_ARG arg1, TAC_ARG arg2);
	// arg1: argument to check, arg2: label
	static TAC IGotoIfFalse(TAC_ARG arg1, TAC_ARG arg2);
	
	// arg1: label
	static TAC IDeclareLabel(TAC_ARG arg1);
	// arg1: argument value, type: argument type
	static TAC IDeclareFunctionArgument(TAC_ARG arg1, Type type);
	// arg1: argument name, type: parameter type
	static TAC IDeclareFunctionParameter(TAC_ARG arg1, Type type);
	// arg1: variable name, type: variable type
	static TAC IDeclareVariable(TAC_ARG arg1, Type type);
	// arg1: array name, arg2: array size, type: array type
	static TAC IDeclareArray(TAC_ARG arg1, TAC_ARG arg2, Type type);
	// arg1: function name, arg2: no of parameters, type: return type
	static TAC IDeclareFunction(TAC_ARG arg1, TAC_ARG arg2, Type type);
};

}; // namespace bsc