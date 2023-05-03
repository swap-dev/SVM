#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <any>
#include <map>
#include <stack>
#include <functional>
#include "functions/all.h"

namespace SVM::Globals
{
	inline std::stack<std::string> program_stack;
	inline std::map<unsigned long, std::function<void()>> instructions_mapping;

	void initialize_instruction_mappings();
}

#endif // !GLOBALS_H
