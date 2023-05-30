#pragma once
#ifndef FUNCTIONS_REGISTERS_H
#define FUNCTIONS_REGISTERS_H

#include "base_include.h"

namespace SVM::registers
{
    template <typename T>
    inline T top_stack_element()
    {
        T el = SVM::Globals::program_stack.top<T>();
        SVM::Globals::program_stack.pop();
        return el;
    }

	inline void SETREG()
    {
        auto value = top_stack_element<unsigned long long>();
        SVM::Globals::registers[SVM::Globals::program_stack.top_cstring()] = value;
        SVM::Globals::program_stack.pop();
    }

	inline void GETREG()
    {
        const char* target_register = SVM::Globals::program_stack.top_cstring();
        SVM::Globals::program_stack.pop();
        SVM::Globals::program_stack.push<unsigned long long>(SVM::Globals::registers[target_register], 8);
    }

	inline void INCREG()
    {
        SVM::Globals::registers[SVM::Globals::program_stack.top_cstring()]++;
        SVM::Globals::program_stack.pop();
    }
}

#endif // !FUNCTIONS_REGISTERS_H
