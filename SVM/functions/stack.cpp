#include "stack.h"
#include <iostream>

namespace SVM::stack
{
	void PUSH()
	{
		// element would already have been pushed onto the stack
		// nothing to do
	}
	void POP()
	{
		SVM::Globals::program_stack.pop();
	}
	void SSTORE()
	{
		// TODO awaiting storage provider and blockchain integration
	}
	void SLOAD()
	{
		// TODO awaiting storage provider and blockchain integration
	}
	void MSIZE()
	{
		SVM::Globals::program_stack.emplace(std::to_string(SVM::Globals::program_stack.size() * STD_STRING_SIZE));
	}
}