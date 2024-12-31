#include "x86_common.hpp"

std::string bsX86::Register::to_string() const
{
	switch (size)
	{
	case bsX86::REG_8:
		if (type < REG_R8) return std::format("{}l", getRegName());
		else return std::format("{}b", getRegName());
	case bsX86::REG_16:
		if (type < REG_ESI || type == REG_ECX || type == REG_EDX ) return std::format("{}x", getRegName());
		else if (type < REG_R8) return getRegName();
		else return std::format("{}w", getRegName());
	case bsX86::REG_32:
		if (type < REG_ESI) return std::format("e{}x", getRegName());
		else if (type < REG_R8) return std::format("e{}", getRegName());
		else return std::format("{}d", getRegName());
	case bsX86::REG_64:
		if (type < REG_ESI || type == REG_ECX || type == REG_EDX) return std::format("r{}x", getRegName());
		else if (type < REG_R8) return std::format("r{}", getRegName());
		else return getRegName();
	default:
		return "none";
	}
}

std::string bsX86::Register::getRegName() const
{
	switch (type)
	{
	case bsX86::REG_EAX:
		return "a";
	case bsX86::REG_EBX:
		return "b";
	case bsX86::REG_ECX:
		return "c";
	case bsX86::REG_EDX:
		return "d";
	case bsX86::REG_ESI:
		return "si";
	case bsX86::REG_EDI:
		return "di";
	case bsX86::REG_EBP:
		return "bp";
	case bsX86::REG_ESP:
		return "sp";
	case bsX86::REG_R8:
		return "r8";
	case bsX86::REG_R9:
		return "r9";
	case bsX86::REG_R10:
		return "r10";
	case bsX86::REG_R11:
		return "r11";
	case bsX86::REG_R12:
		return "r12";
	case bsX86::REG_R13:
		return "r13";
	case bsX86::REG_R14:
		return "r14";
	case bsX86::REG_R15:
		return "r15";
	default:
		return "none";
	}
}
