#pragma once
#ifndef FUNCTIONS_MATH_H
#define FUNCTIONS_MATH_H

#include "base_include.h"
#include <cmath>

namespace SVM::math
{
    inline uint64_t next_number()
    {
        const auto num = SVM::Globals::program_stack.top<uint64_t>();
        SVM::Globals::program_stack.pop();
        return num;
    }

	inline void ADD()
    {
        SVM::Globals::program_stack.push<uint64_t>(next_number() + next_number(), 8);
    }

	inline void SUB()
    {
        const uint64_t num1 = next_number();
        const uint64_t num2 = next_number();
        SVM::Globals::program_stack.push<uint64_t>(num1 - num2, 8);
    }

	inline void MUL()
    {
        SVM::Globals::program_stack.push<uint64_t>(next_number() * next_number(), 8);
    }

	inline void DIV()
    {
        const uint64_t num1 = next_number();
        const uint64_t num2 = next_number();
        SVM::Globals::program_stack.push<uint64_t>(num1 / num2, 8);
    }

	inline void MOD()
    {
        const uint64_t num1 = next_number();
        const uint64_t num2 = next_number();
        SVM::Globals::program_stack.push<uint64_t>(num1 % num2, 8);
    }

	inline void POW()
    {
        const uint64_t number = next_number();
        const uint64_t power = next_number();
        SVM::Globals::program_stack.push<uint64_t>(static_cast<uint64_t>(pow(number, power)), 8);
    }
}

#endif // !FUNCTIONS_MATH_H
