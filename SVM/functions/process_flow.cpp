#include "process_flow.h"
#include <iostream>
#include <sstream> 

namespace SVM::process_flow
{
	void set_program_counter(size_t value)
	{
		// account for the program_counter++ at the end of the instruction loop
		SVM::Globals::program_counter = value - 1;
		SVM::Globals::program_stack.pop();
	}
	void STOP()
	{
		SVM::Globals::program_stack.emplace("INTERNAL_SVM_FUNCTION_STOP");
	}
	void JMP()
	{
		set_program_counter(std::stoull(SVM::Globals::program_stack.top()));
	}
	void JMPI()
	{
		std::string location = SVM::Globals::program_stack.top();
		SVM::Globals::program_stack.pop();

		bool condition_met;
		std::istringstream(SVM::Globals::program_stack.top()) >> std::boolalpha >> condition_met;

		if (condition_met)
		{
			set_program_counter(std::stoull(location));
		}
	}
}