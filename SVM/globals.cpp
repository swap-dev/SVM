#include "globals.h"

namespace SVM::Globals
{
	void initialize_instruction_mappings()
	{
		instructions_mapping[0UL] = SVM::system::LOG;
		instructions_mapping[1UL] = SVM::system::RETURN;
		instructions_mapping[2UL] = SVM::system::SELFDESTRUCT;
		instructions_mapping[3UL] = SVM::stack::PUSH;
		instructions_mapping[4UL] = SVM::stack::POP;
		instructions_mapping[5UL] = SVM::stack::SSTORE;
		instructions_mapping[6UL] = SVM::stack::SLOAD;
		instructions_mapping[7UL] = SVM::stack::MSIZE;
	}
}
