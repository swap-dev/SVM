#include <iostream>
#include "system.h"

namespace SVM::system {
	void LOG(std::stack<std::string>& program_stack) {
		std::cout << program_stack.top() << "\n";
	}

	void RETURN(std::stack<std::string>& program_stack)
	{
		program_stack.push("INTERNAL_SVM_FUNCTION_RETURN");
	}

	void SELFDESTRUCT(std::stack<std::string>& program_stack)
	{
		program_stack.push("INTERNAL_SVM_FUNCTION_SELFDESTRUCT");
	}

	void append_functions(std::map<unsigned long, std::function<void(std::stack<std::string>&)>>& existing_functions) {
		existing_functions[0UL] = LOG;
		existing_functions[1UL] = RETURN;
		existing_functions[2UL] = SELFDESTRUCT;
	}
}