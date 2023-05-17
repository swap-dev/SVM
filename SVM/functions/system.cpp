#include <iostream>
#include "system.h"

namespace SVM::system {
	void LOG() {
		std::cout << SVM::Utils::top_stack_element() << "\n";
	}

	void RETURN()
	{
		SVM::Globals::program_stack.emplace("INTERNAL_SVM_FUNCTION_RETURN");
	}

	void SELFDESTRUCT()
	{
		SVM::Globals::program_stack.emplace("INTERNAL_SVM_FUNCTION_SELFDESTRUCT");
	}
}