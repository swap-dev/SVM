#pragma once
#ifndef ASSEMBLY_FUNCTIONS_SYSTEM_H
#define ASSEMBLY_FUNCTIONS_SYSTEM_H

#include "base_include.h"

namespace SVM::system {
	void LOG(std::stack<std::string>& program_stack);
	void RETURN(std::stack<std::string>& program_stack);
	void SELFDESTRUCT(std::stack<std::string>& program_stack);

	void append_functions(std::map<unsigned long, std::function<void(std::stack<std::string>&)>>& existing_functions);
}

#endif // !ASSEMBLY_FUNCTIONS_SYSTEM