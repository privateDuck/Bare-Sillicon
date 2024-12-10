#pragma once
#include <sstream>

class ULiteral {
public:
    // Union containing the different types
    union {
        int i;
        unsigned int ui;
        char c;
        unsigned char uc;
    };

    // default constructor
    ULiteral() : i(0) {}

    // Constructor for each type
    //explicit ULiteral(int val) : i(val) {}
    //explicit ULiteral(unsigned int val) : ui(val) {}
    //explicit ULiteral(char val) : c(val) {}
    //explicit ULiteral(unsigned char val) : uc(val) {}

    // Overload +
    ULiteral operator+(const ULiteral& other) const {
        ULiteral result;
        result.i = this->i + other.i;
        return result;
    }

    // Overload -
    ULiteral operator-(const ULiteral& other) const {
        ULiteral result;
        result.i = this->i - other.i;
        return result;
    }

    ULiteral operator*(const ULiteral& other) const {
		ULiteral result;
		result.i = this->i * other.i;
		return result;
	}

    ULiteral operator/(const ULiteral& other) const {
        ULiteral result;
        result.i = this->i / other.i;
        return result;
    }

    ULiteral operator%(const ULiteral& other) const {
        ULiteral result;
        result.i = this->i % other.i;
        return result;
    }

    // Overload ==
    bool operator==(const ULiteral& other) const {
        return this->i == other.i;
    }

// Overload !=
bool operator!=(const ULiteral& other) const {
		return this->i != other.i;
	}

// Overload <
bool operator<(const ULiteral& other) const {
return this->i < other.i;
}

// Overload >
bool operator>(const ULiteral& other) const {
return this->i > other.i;
    }

	// Overload <=
	bool operator<=(const ULiteral& other) const {
return this->i <= other.i;
}

// Overload >=
bool operator>=(const ULiteral& other) const {
return this->i >= other.i;
}

// Overload 

    // Overload <<
    friend std::ostream& operator<<(std::ostream& os, const ULiteral& u) {
        os << u.i;
        return os;
    }

    int asInt() const { return i; }
    unsigned int asUnsignedInt() const { return ui; }
    char asChar() const { return c; }
    unsigned char asUnsignedChar() const { return uc; }
};