#include <iostream>
#include "system.h"

namespace SVM::system {
	void log(std::stack<std::string>& program_stack) {
		std::cout << program_stack.top() << "\n";
		program_stack.pop();
	}

	void append_functions(std::map<unsigned long, std::function<void(std::stack<std::string>&)>>& existing_functions) {
		existing_functions[0UL] = log;
	}
}