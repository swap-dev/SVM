#include "globals.h"

namespace SVM::Globals
{
	void initialize_instruction_mappings()
	{
		instructions_mapping[0UL] = SVM::system::LOG;
		instructions_mapping[1UL] = SVM::system::RETURN;
		instructions_mapping[2UL] = SVM::system::SELFDESTRUCT;
	}
}
