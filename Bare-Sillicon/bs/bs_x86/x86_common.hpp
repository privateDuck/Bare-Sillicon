#pragma once

#include <string>
#include <format>
#include <sstream>

namespace bsX86
{

	enum RegType
	{
		REG_EAX,
		REG_EBX,
		REG_ECX,
		REG_EDX,
		REG_ESI,
		REG_EDI,
		REG_EBP,
		REG_ESP,
		REG_R8,
		REG_R9,
		REG_R10,
		REG_R11,
		REG_R12,
		REG_R13,
		REG_R14,
		REG_R15
	};

	enum RegSize
	{
		REG_8,
		REG_16,
		REG_32,
		REG_64
	};

	enum Instr_Arg_Type
	{
		REGISTER,
		IMMEDIATE,
		LABEL,
		POINTER,
		POINTER_WOFFSET
	};

	static std::string getPtrType(RegSize size)
	{
		switch (size)
		{
		case REG_8:
			return "BYTE PTR";
		case REG_16:
			return "WORD PTR";
		case REG_32:
			return "DWORD PTR";
		case REG_64:
			return "QWORD PTR";
		default:
			return "DWORD PTR";
		}
	}

	struct Register {
		RegType type;
		RegSize size;

		Register() : type(REG_EAX), size(REG_32) {}
		Register(RegType type, RegSize size) : type(type), size(size) {}

		std::string to_string() const;

		friend std::ostringstream& operator<<(std::ostringstream& os, const Register& tmp) {
			os << tmp.to_string();
			return os;
		}
	private:
		std::string getRegName() const;
	};

	struct INSTR_ARG {
		Instr_Arg_Type type;
		Register reg;
		long long imm;
		std::string label;
		int offset;

		INSTR_ARG() : type(REGISTER), reg(), imm(0), label(""), offset(0) {}

		void setAsRegister(Register reg) {
			type = REGISTER;
			this->reg = reg;
		}

		void setAsImmediate(long long imm) {
			type = IMMEDIATE;
			this->imm = imm;
		}

		void setAsLabel(const std::string& label) {
			type = LABEL;
			this->label = label;
		}

		void setAsPointer(Register reg) {
			type = POINTER;
			this->reg = reg;
		}

		void setAsPointerOffset(Register reg, int off) {
			type = POINTER_WOFFSET;
			this->reg = reg;
			offset = off;
		}

		friend std::ostringstream& operator<<(std::ostringstream& os, const INSTR_ARG& tmp) {
			os << tmp.get();
			return os;
		}

		std::string get() const {
			switch (type)
			{
			case REGISTER:
				return reg.to_string();
			case IMMEDIATE:
				return std::to_string(imm);
			case LABEL:
				return label;
			case POINTER:
				return std::format("[{}]", reg.to_string());
			case POINTER_WOFFSET:
			{
				std::string ptr_type = getPtrType(reg.size);
				if (offset == 0)
					return std::format("{} [{}]", ptr_type, reg.to_string());
				else if (offset < 0)
					return std::format("{} [{}{}]", ptr_type, reg.to_string(), offset);
				else
					return std::format("{} [{}+{}]", ptr_type, reg.to_string(), offset);
			}
			default:
				break;
			}
		}
	};

};