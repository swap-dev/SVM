#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <map>
#include "flexible_stack.h"
#include <functional>
#include <string>
#include "functions/all.h"

namespace SVM::Globals
{
	inline size_t program_counter = 0;
	inline FlexibleStack program_stack;
	inline std::map<unsigned long long, std::function<void()>> instructions_mapping;
	inline std::map<std::string, unsigned long long> registers = 
	{
		{ "GA", 0 },
		{ "GB", 0 },
		{ "GC", 0 },
		{ "GD", 0 },
		{ "GE", 0 },
		{ "GF", 0 },
		{ "CA", 0 },
		{ "IA", 0 },
		{ "IB", 0 },
		{ "IC", 0 },
		{ "ID", 0 },

	};

	void initialize_instruction_mappings();
}

#endif // !GLOBALS_H
