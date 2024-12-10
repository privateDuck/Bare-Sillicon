#pragma once
#include <format>
#include "symbols.hpp"
#include "../bs_IR/ir_common.hpp"

namespace bsc{

	

	struct CTMP {
		int value;
		Type type;
		std::string expr;

		CTMP() : value(-1), type(Type::UINT_t), expr(get()) {}
		explicit CTMP(int value) : value(value), type(Type::UINT_t), expr(get()) {}
		CTMP(int value, Type t) : value(value), type(t), expr(get()) {}
		CTMP(int value, Type t, const std::string& expr) : value(value), type(t), expr(expr) {}

		void load_symbol(const std::string& symbol, Type type) {
			this->type = type;
			expr = std::format("t{} = {}", value, symbol);
			//expr = std::format("t{} = load{} {}", value, type == Type::CHAR_t ? "b" : "w", symbol);
		}

		void loadw(const CTMP& ptr, bool is_signed = true) {
			type = is_signed ? Type::INT_t : Type::UINT_t;
			expr = std::format("t{} = loadw t{}", value, ptr.value);
		}
		void loadb(const CTMP& ptr, bool is_signed = true) {
			type = is_signed ? Type::CHAR_t : Type::UCHAR_t;
			expr = std::format("t{} = loadb t{}", value, ptr.value);
		}

		void store(const std::string& symbol) {
			expr = std::format("{} = t{}", symbol, value);
		}

		void loadptr(const std::string& symbol) {
			type = Type::UINT_t;
			expr = std::format("t{} = loadptr {}", value, symbol);
		}

		void storew(const CTMP& symbol) {
			expr = std::format("storew t{} -> t{}", value, symbol.value);
		}
		void storeb(const CTMP& symbol) {
			expr = std::format("storeb t{} -> t{}", value, symbol.value);
		}

		friend std::ostringstream& operator<<(std::ostringstream& os, const CTMP& tmp) {
			os << tmp.expr;
			return os;
		}

		std::string get() const { return std::format("t{}", value); }

		// Friend operator overloads for arithmetic and bitwise operations
		CTMP operator!() const;
		CTMP operator+() const;
		CTMP operator-() const;
		CTMP operator~() const;

		CTMP operator+(const CTMP& other) const;
		CTMP operator-(const CTMP& other) const;
		CTMP operator*(const CTMP& other) const;
		CTMP operator/(const CTMP& other) const;
		CTMP operator&(const CTMP& other) const;
		CTMP operator|(const CTMP& other) const;
		CTMP operator^(const CTMP& other) const;
		CTMP operator<<(const CTMP& other) const;
		CTMP operator>>(const CTMP& other) const;
		CTMP operator&&(const CTMP& other) const;
		CTMP operator||(const CTMP& other) const;
		CTMP operator==(const CTMP& other) const;
		CTMP operator!=(const CTMP& other) const;
		CTMP operator<(const CTMP& other) const;
		CTMP operator>(const CTMP& other) const;
		CTMP operator<=(const CTMP& other) const;
		CTMP operator>=(const CTMP& other) const;
		CTMP operator%(const CTMP& other) const;

		CTMP operator+(int rhs) const;
		CTMP operator-(int rhs) const;
		CTMP operator*(int rhs) const;
		CTMP operator/(int rhs) const;
		CTMP operator&(int rhs) const;
		CTMP operator|(int rhs) const;
		CTMP operator^(int rhs) const;
		CTMP operator<<(int rhs) const;
		CTMP operator>>(int rhs) const;
		CTMP operator&&(int rhs) const;
		CTMP operator||(int rhs) const;
		CTMP operator==(int rhs) const;
		CTMP operator!=(int rhs) const;
		CTMP operator<(int rhs) const;
		CTMP operator>(int rhs) const;
		CTMP operator<=(int rhs) const;
		CTMP operator>=(int rhs) const;
		CTMP operator%(int rhs) const;
		
		CTMP operator+(const std::string& other) const;
		CTMP operator-(const std::string& other) const;
		CTMP operator*(const std::string& other) const;
		CTMP operator/(const std::string& other) const;
		CTMP operator&(const std::string& other) const;
		CTMP operator|(const std::string& other) const;
		CTMP operator^(const std::string& other) const;
		CTMP operator<<(const std::string& other) const;
		CTMP operator>>(const std::string& other) const;
		CTMP operator&&(const std::string& other) const;
		CTMP operator||(const std::string& other) const;
		CTMP operator==(const std::string& other) const;
		CTMP operator!=(const std::string& other) const;
		CTMP operator<(const std::string& other) const;
		CTMP operator>(const std::string& other) const;
		CTMP operator<=(const std::string& other) const;
		CTMP operator>=(const std::string& other) const;
		CTMP operator%(const std::string& other) const;

		// Assign the resulting expression back to this object
		CTMP& operator=(const CTMP& other) {
			if (this != &other) {  // Avoid self-assignment
				this->expr = other.expr;
				this->value = other.value;
			}
			return *this;
		}
	};

	CTMP operator+(int lhs, const CTMP& rhs);
	CTMP operator-(int lhs, const CTMP& rhs);
	CTMP operator*(int lhs, const CTMP& rhs);
	CTMP operator/(int lhs, const CTMP& rhs);
	CTMP operator&(int lhs, const CTMP& rhs);
	CTMP operator|(int lhs, const CTMP& rhs);
	CTMP operator^(int lhs, const CTMP& rhs);
	CTMP operator<<(int lhs, const CTMP& rhs);
	CTMP operator>>(int lhs, const CTMP& rhs);
	CTMP operator&&(int lhs, const CTMP& rhs);
	CTMP operator||(int lhs, const CTMP& rhs);
	CTMP operator==(int lhs, const CTMP& rhs);
	CTMP operator!=(int lhs, const CTMP& rhs);
	CTMP operator<(int lhs, const CTMP& rhs);
	CTMP operator>(int lhs, const CTMP& rhs);
	CTMP operator<=(int lhs, const CTMP& rhs);
	CTMP operator>=(int lhs, const CTMP& rhs);
	CTMP operator%(int lhs, const CTMP& rhs);
};