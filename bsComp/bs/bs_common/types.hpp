#pragma once

#include <unordered_map>
#include <string>

namespace bsc {


	enum MACHINE_WD_SIZE {
		MWS_2 = 0,
		MWS_4 = 1
	};

	enum class Type {
		CHAR_t = 0,
		UCHAR_t = 1,
		INT_t = 2,
		UINT_t = 3
	};

	static constexpr Type SelectCommonType(Type left, Type right) {
		return std::max(left, right);
	}

	static constexpr  bool isSigned(Type type) {
		return type == Type::CHAR_t || type == Type::INT_t;
	}

	static constexpr  bool isUnsigned(Type type) {
		return type == Type::UCHAR_t || type == Type::UINT_t;
	}

	static constexpr  bool isInt(Type type) {
		return type == Type::UINT_t || type == Type::INT_t;
	}

	static  constexpr bool isChar(Type type) {
		return type == Type::CHAR_t || type == Type::UCHAR_t;
	}

	static constexpr Type getSignedType(Type type) {
		return isChar(type) ? Type::CHAR_t : Type::INT_t;
	}

	static constexpr Type getUnsignedType(Type type) {
		return isChar(type) ? Type::UCHAR_t : Type::UINT_t;
	}

	// Check if an implicit cast from 'from' to 'to' should generate a warning
	// Implicit cast can only occur in the up direction
	// For example, char -> uchar is fine, but uchar -> char is not
	// Therefore these are the only cases where a warning should be generated
	// signed to unsigned (char -> uchar or int -> uint)
	// higher size to lower size (int -> char)
	// Implicit casts from unsigned to signed will clamp the values
	static constexpr bool ShouldCastWarn(Type from, Type to) {
		return (isSigned(from) && isUnsigned(to)) || (isInt(from) && isChar(to));
	}

	static constexpr int getTypeSize(Type type) {
		if (isChar(type)) return 1;
		return 4;
	}

	static Type typeFromAlign(int align) {
		if (align == 1) return Type::CHAR_t;
		return Type::INT_t;
	}

	int cast(MACHINE_WD_SIZE mws, Type from, Type to, int value);
	long long staticCast(long long value, Type srcType, Type destType, int wordSize);
	long long reinterpretCast(long long value, Type srcType, Type destType, int wordSize);
	long long signExtend(long long value, int fromSize, int toSize);
	long long zeroExtend(long long value, int fromSize, int toSize);
	long long truncate(long long value, int fromSize, int toSize);

	extern std::unordered_map<std::string, Type> ptypeMap;
	extern std::unordered_map<Type, std::string> typeNames;

	std::string getTypeName(Type type);
};