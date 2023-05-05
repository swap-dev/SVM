#include "globals.h"

namespace SVM::Globals
{
	void initialize_instruction_mappings()
	{
		instructions_mapping[0] = SVM::system::LOG;
		instructions_mapping[1] = SVM::system::RETURN;
		instructions_mapping[2] = SVM::system::SELFDESTRUCT;
		instructions_mapping[3] = SVM::stack::PUSH;
		instructions_mapping[4] = SVM::stack::POP;
		instructions_mapping[5] = SVM::stack::SSTORE;
		instructions_mapping[6] = SVM::stack::SLOAD;
		instructions_mapping[7] = SVM::stack::MSIZE;
		instructions_mapping[8] = SVM::math::ADD;
		instructions_mapping[9] = SVM::math::SUB;
		instructions_mapping[10] = SVM::math::MUL;
		instructions_mapping[11] = SVM::math::DIV;
		instructions_mapping[12] = SVM::math::MOD;
		instructions_mapping[13] = SVM::math::POW;
	}
}
