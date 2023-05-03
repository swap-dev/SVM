#include <iostream>
#include "system.h"

namespace SVM::system {
	void LOG() {
		std::cout << SVM::Globals::program_stack.top() << "\n";
	}

	void RETURN()
	{
		SVM::Globals::program_stack.push("INTERNAL_SVM_FUNCTION_RETURN");
	}

	void SELFDESTRUCT()
	{
		SVM::Globals::program_stack.push("INTERNAL_SVM_FUNCTION_SELFDESTRUCT");
	}
}