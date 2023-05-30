#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#include <map>
#include <functional>
#include "flexible_stack.h"

namespace SVM::Globals
{
	inline uint64_t program_counter = 0;
	inline FlexibleStack program_stack;
	inline std::map<uint64_t, std::function<void()>> instructions_mapping;
	inline std::map<const char*, uint64_t> registers =
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
        { "ID", 0 }
    };
}

#endif // !GLOBALS_H
