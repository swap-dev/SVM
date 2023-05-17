#include "registers.h"

namespace SVM::registers
{
	void SETREG()
	{
		unsigned long long value = std::stoull(SVM::Utils::top_stack_element());
		std::string reg = SVM::Utils::top_stack_element();
		SVM::Globals::registers[reg] = value;
	}
	void GETREG()
	{
		SVM::Globals::program_stack.push(std::to_string(SVM::Globals::registers[SVM::Utils::top_stack_element()]));
	}
	void INCREG()
	{
		SVM::Globals::registers[SVM::Utils::top_stack_element()]++;
	}
}
