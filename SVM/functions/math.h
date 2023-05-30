#pragma once
#ifndef FUNCTIONS_MATH_H
#define FUNCTIONS_MATH_H

#include "base_include.h"
#include <cmath>

namespace SVM::math
{
    inline unsigned long long next_number()
    {
        const auto num = SVM::Globals::program_stack.top<unsigned long long>();
        SVM::Globals::program_stack.pop();
        return num;
    }

	inline void ADD()
    {
        SVM::Globals::program_stack.push<unsigned long long>(next_number() + next_number(), 8);
    }

	inline void SUB()
    {
        const unsigned long long num1 = next_number();
        const unsigned long long num2 = next_number();
        SVM::Globals::program_stack.push<unsigned long long>(num1 - num2, 8);
    }

	inline void MUL()
    {
        SVM::Globals::program_stack.push<unsigned long long>(next_number() * next_number(), 8);
    }

	inline void DIV()
    {
        const unsigned long long num1 = next_number();
        const unsigned long long num2 = next_number();
        SVM::Globals::program_stack.push<unsigned long long>(num1 / num2, 8);
    }

	inline void MOD()
    {
        const unsigned long long num1 = next_number();
        const unsigned long long num2 = next_number();
        SVM::Globals::program_stack.push<unsigned long long>(num1 % num2, 8);
    }

	inline void POW()
    {
        const unsigned long long number = next_number();
        const unsigned long long power = next_number();
        SVM::Globals::program_stack.push<unsigned long long>(static_cast<unsigned long long>(pow(number, power)), 8);
    }
}

#endif // !FUNCTIONS_MATH_H
