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
		instructions_mapping[14] = SVM::process_flow::STOP;
		instructions_mapping[15] = SVM::process_flow::JMP;
		instructions_mapping[16] = SVM::process_flow::JMPI;
		instructions_mapping[17] = SVM::logic::LT;
		instructions_mapping[18] = SVM::logic::GT;
		instructions_mapping[19] = SVM::logic::EQ;
		instructions_mapping[20] = SVM::logic::LOR;
		instructions_mapping[21] = SVM::logic::LNOT;
		instructions_mapping[22] = SVM::logic::OR;
		instructions_mapping[23] = SVM::logic::NOT;
		instructions_mapping[24] = SVM::logic::XOR;
		instructions_mapping[25] = SVM::registers::SETREG;
		instructions_mapping[26] = SVM::registers::GETREG;
		instructions_mapping[27] = SVM::registers::INCREG;
	}
}
