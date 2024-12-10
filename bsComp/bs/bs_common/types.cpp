#include "types.hpp"
#include <limits>
#include <stdexcept>


namespace bsc {

    // Contains bit masks required for type casts
    // 0 - MACHINE WORD SIZE 2 bytes
    // 1 - MACHINE WORD SIZE 4 bytes
    static constexpr long long HIGH_MASK[2] = {
        0x00007FFF, // 0
        0x7FFFFFFF, // 1
    };

    // Shift masks
    static constexpr long long INT_SIGN_SHIFT_MASK[2] = {
        16,
        0
    };

    static constexpr long long SIGN_BIT = 0x80000000;

    std::unordered_map<std::string, Type> ptypeMap = {
        {"byte", Type::CHAR_t},
        {"char", Type::CHAR_t},
        {"ubyte", Type::UCHAR_t},
        {"sbyte", Type::CHAR_t},
        {"uchar", Type::UCHAR_t},
        {"int", Type::INT_t},
        {"uint", Type::UINT_t},
        {"sb", Type::CHAR_t},
        {"ub", Type::UCHAR_t},
        {"sw", Type::INT_t},
        {"uw", Type::UINT_t},
        {"si", Type::INT_t},
		{"ui", Type::UINT_t},
        {"1s", Type::CHAR_t},
        {"1u", Type::UCHAR_t},
		{"2s", Type::INT_t},
		{"2u", Type::UINT_t},
		{"4s", Type::INT_t},
		{"4u", Type::UINT_t}
    };

    std::unordered_map<Type, std::string> typeNames = {
        {Type::CHAR_t, "char"},
        {Type::UCHAR_t, "uchar"},
        {Type::INT_t, "int"},
        {Type::UINT_t, "uint"}
    };

    long long staticCast(long long value, Type srcType, Type destType, int wordSize) {
        // Determine the word size limits
        if (wordSize != 2 && wordSize != 4) {
            throw std::invalid_argument("Invalid word size. Must be 2 or 4 bytes.");
        }

        long long minLimit, maxLimit;

        switch (destType) {
        case Type::CHAR_t:
            minLimit = std::numeric_limits<signed char>::min();
            maxLimit = std::numeric_limits<signed char>::max();
            break;
        case Type::UCHAR_t:
            minLimit = 0;
            maxLimit = std::numeric_limits<unsigned char>::max();
            break;
        case Type::INT_t:
            if (wordSize == 2) {
                minLimit = std::numeric_limits<int16_t>::min();
                maxLimit = std::numeric_limits<int16_t>::max();
            }
            else {
                minLimit = std::numeric_limits<int32_t>::min();
                maxLimit = std::numeric_limits<int32_t>::max();
            }
            break;
        case Type::UINT_t:
            if (wordSize == 2) {
                minLimit = 0;
                maxLimit = std::numeric_limits<uint16_t>::max();
            }
            else {
                minLimit = 0;
                maxLimit = std::numeric_limits<uint32_t>::max();
            }
            break;
        default:
            throw std::invalid_argument("Invalid destination type.");
        }

        // Check if the value is within bounds
        /*if (value < minLimit || value > maxLimit) {
            throw std::out_of_range("Value out of range for the destination type.");
        }*/
        value = std::max(minLimit, std::min(maxLimit, value));

        // Perform the cast
        return value; // The cast is effectively implicit after the checks.
    }

    long long reinterpretCast(long long value, Type srcType, Type destType, int wordSize) {
        // Ensure the word size is valid
        if (wordSize != 2 && wordSize != 4) {
            throw std::invalid_argument("Invalid word size. Must be 2 or 4 bytes.");
        }

        if (srcType == destType) {
			return value;
		}

        if (isInt(srcType) && isChar(destType)) {
			return value & 0xFF;
		}

        if (isChar(srcType) && isInt(destType)) {
            return value & 0xFF;
        }

        if (isSigned(srcType) && isUnsigned(destType)) {
            unsigned long long sign = value < 0 ? std::numeric_limits<unsigned long long>::max() : 0;
            sign &= wordSize == 2 ? 0x8000 : 0x80000000;
            unsigned long long tmp = (value & 0xFFFF) | sign;
            return tmp | sign;
		}

        if (isUnsigned(srcType) && isSigned(destType)) {
            return value & (wordSize == 2 ? 0x7FFF : 0x7FFFFFFF);
        }

        // Perform the reinterpretation (bit preservation)
        // Mask based on the word size
        long long sign = value & 0x8000000000000000;
        sign >>= wordSize == 2 ? 47 : 31; // Shift the sign bit to the correct position
        if (wordSize == 2) {
            value &= 0xFFFFll; // Preserve only 16 bits
        }
        else {
            value &= 0xFFFFFFFFll; // Preserve only 32 bits
        }

        // Return the raw bits without modification
        return value;
    }


    std::string getTypeName(Type type)
    {
        return typeNames[type];
    }

}; // namespace bsc