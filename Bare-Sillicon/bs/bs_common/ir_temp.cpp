#include "ir_temp.hpp"

namespace bsc {

	/*std::ostringstream& operator<<(std::ostringstream& os, const _TMP& tmp) {
		os << tmp.expr;
		return os;
	}*/

	CTMP CTMP::operator!() const {
		return CTMP{ value, type, std::format("t{} = t{} == 0", value, value) };
	}
	CTMP CTMP::operator+() const {
		return *this;
	}
	CTMP CTMP::operator-() const {
		return CTMP{ value, isUnsigned(type) ? getSignedType(type) : type, std::format("t{} = 0 - t{}", value, value)};
	}
	CTMP CTMP::operator~() const {
		return CTMP{ value, type, std::format("t{} = not t{}", value, value) };
	}

	// _TMP to _TMP operator overloads for arithmetic and bitwise operations
	CTMP CTMP::operator+(const CTMP& other) const {
		return CTMP(value, SelectCommonType(type, other.type), std::format("t{} = t{} + t{}", value, value, other.value));
	}
	CTMP CTMP::operator-(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} - t{}", value, value, other.value) };
	}
	CTMP CTMP::operator*(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} * t{}", value, value, other.value) };
	}
	CTMP CTMP::operator/(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} / t{}", value, value, other.value) };
	}
	CTMP CTMP::operator&(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} & t{}", value, value, other.value) };
	}
	CTMP CTMP::operator|(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} | t{}", value, value, other.value) };
	}
	CTMP CTMP::operator^(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} ^ t{}", value, value, other.value) };
	}
	CTMP CTMP::operator<<(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} << t{}", value, value, other.value) };
	}
	CTMP CTMP::operator>>(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} >> t{}", value, value, other.value) };
	}
	CTMP CTMP::operator&&(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} && t{}", value, value, other.value) };
	}
	CTMP CTMP::operator||(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} || t{}", value, value, other.value) };
	}
	CTMP CTMP::operator==(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} == t{}", value, value, other.value) };
	}
	CTMP CTMP::operator!=(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} != t{}", value, value, other.value) };
	}
	CTMP CTMP::operator<(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} < t{}", value, value, other.value) };
	}
	CTMP CTMP::operator>(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} > t{}", value, value, other.value) };
	}
	CTMP CTMP::operator<=(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} <= t{}", value, value, other.value) };
	}
	CTMP CTMP::operator>=(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} >= t{}", value, value, other.value) };
	}
	CTMP CTMP::operator%(const CTMP& other) const {
		return CTMP{ value, SelectCommonType(type, other.type), std::format("t{} = t{} % t{}", value, value, other.value) };
	}


	// _TMP to int operator overloads for arithmetic and bitwise operations
	CTMP CTMP::operator+(int rhs) const {
		return CTMP(value, type, std::format("t{} = t{} + {}", value, value, rhs));
	}
	CTMP CTMP::operator-(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} - {}", value, value, rhs) };
	}
	CTMP CTMP::operator*(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} * {}", value, value, rhs) };
	}
	CTMP CTMP::operator/(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} / {}", value, value, rhs) };
	}
	CTMP CTMP::operator&(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} & {}", value, value, rhs) };
	}
	CTMP CTMP::operator|(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} | {}", value, value, rhs) };
	}
	CTMP CTMP::operator^(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} ^ {}", value, value, rhs) };
	}
	CTMP CTMP::operator<<(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} << {}", value, value, rhs) };
	}
	CTMP CTMP::operator>>(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} >> {}", value, value, rhs) };
	}
	CTMP CTMP::operator&&(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} && {}", value, value, rhs) };
	}
	CTMP CTMP::operator||(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} || {}", value, value, rhs) };
	}
	CTMP CTMP::operator==(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} == {}", value, value, rhs) };
	}
	CTMP CTMP::operator!=(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} != {}", value, value, rhs) };
	}
	CTMP CTMP::operator<(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} < {}", value, value, rhs) };
	}
	CTMP CTMP::operator>(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} > {}", value, value, rhs) };
	}
	CTMP CTMP::operator<=(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} <= {}", value, value, rhs) };
	}
	CTMP CTMP::operator>=(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} >= {}", value, value, rhs) };
	}
	CTMP CTMP::operator%(int rhs) const {
		return CTMP{ value, type, std::format("t{} = t{} % {}", value, value, rhs) };
	}


	CTMP CTMP::operator+(const std::string& other) const {
		return CTMP(value, type, std::format("t{} = t{} + {}", value, value, other));
	}
	CTMP CTMP::operator-(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} - {}", value, value, other) };
	}
	CTMP CTMP::operator*(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} * {}", value, value, other) };
	}
	CTMP CTMP::operator/(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} / {}", value, value, other) };
	}
	CTMP CTMP::operator&(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} & {}", value, value, other) };
	}
	CTMP CTMP::operator|(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} | {}", value, value, other) };
	}
	CTMP CTMP::operator^(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} ^ {}", value, value, other) };
	}
	CTMP CTMP::operator<<(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} << {}", value, value, other) };
	}
	CTMP CTMP::operator>>(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} >> {}", value, value, other) };
	}
	CTMP CTMP::operator&&(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} && {}", value, value, other) };
	}
	CTMP CTMP::operator||(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} || {}", value, value, other) };
	}
	CTMP CTMP::operator==(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} == {}", value, value, other) };
	}
	CTMP CTMP::operator!=(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} != {}", value, value, other) };
	}
	CTMP CTMP::operator<(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} < {}", value, value, other) };
	}
	CTMP CTMP::operator>(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} > {}", value, value, other) };
	}
	CTMP CTMP::operator<=(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} <= {}", value, value, other) };
	}
	CTMP CTMP::operator>=(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} >= {}", value, value, other) };
	}
	CTMP CTMP::operator%(const std::string& other) const {
		return CTMP{ value, type, std::format("t{} = t{} % {}", value, value, other) };
	}


	// int to _TMP operator overloads for arithmetic and bitwise operations
	CTMP operator+(int rhs, const CTMP& tmp) {
		return CTMP(tmp.value, tmp.type, std::format("t{} = {} + t{}", tmp.value, rhs, tmp.value));
	}
	CTMP operator-(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} - t{}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator*(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} * t{}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator/(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} / t{}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator&(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} & t{}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator|(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} | t{}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator^(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} ^ t{}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator<<(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} << t {}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator>>(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} >> t {}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator&&(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} && t {}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator||(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} || t {}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator==(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} == t {}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator!=(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} != t {}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator<(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} < t{}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator>(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} > t{}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator<=(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} <=t {}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator>=(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} >=t {}", tmp.value, rhs, tmp.value) };
	}
	CTMP operator%(int rhs, const CTMP& tmp) {
		return CTMP{ tmp.value, tmp.type, std::format("t{} = {} % t{}", tmp.value, rhs, tmp.value) };
	}

} // namespace bsc