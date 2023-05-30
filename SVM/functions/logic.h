#pragma once
#ifndef LOGIC_H
#define LOGIC_H

#include "base_include.h"
#include "../globals.h"
#include "../utils.h"

namespace SVM::logic
{
    template <typename T>
    inline T top_stack_element()
    {
        T el = SVM::Globals::program_stack.top<T>();
        SVM::Globals::program_stack.pop();
        return el;
    }

	inline void LT()
    {
        const auto num1 = top_stack_element<uint64_t>();
        const auto num2 = top_stack_element<uint64_t>();

        SVM::Globals::program_stack.push<bool>(num1 < num2, 1);
    }

	inline void GT()
    {
        const auto num1 = top_stack_element<uint64_t>();
        const auto num2 = top_stack_element<uint64_t>();

        SVM::Globals::program_stack.push<bool>(num1 > num2, 1);
    }

	inline void EQ()
    {
        SVM::Globals::program_stack.push<bool>(top_stack_element<uint64_t>() == top_stack_element<uint64_t>(), 1);
    }

	inline void OR()
    {
        const int8_t data_type = SVM::Globals::program_stack.top_cstring()[0];

        if (data_type == 'n')
        {
            const auto num1 = top_stack_element<uint64_t>();
            const auto num2 = top_stack_element<uint64_t>();

            SVM::Globals::program_stack.push<uint64_t>(num1 | num2, 8);
        }
        else if (data_type == 'b')
        {
            const auto bool1 = top_stack_element<bool>();
            const auto bool2 = top_stack_element<bool>();

            SVM::Globals::program_stack.push<bool>(static_cast<bool>(bool1 | bool2), 1);
        }
    }

	inline void NOT()
    {
        const int8_t data_type = SVM::Globals::program_stack.top_cstring()[0];

        if (data_type == 'n')
        {
            SVM::Globals::program_stack.push<uint64_t>(~(top_stack_element<uint64_t>()), 8);
        }
        else if (data_type == 'b')
        {
            SVM::Globals::program_stack.push<bool>(!(top_stack_element<bool>()), 1);
        }
    }

	inline void LOR()
    {
/*		const std::string element1 = next_element();
		const std::string element2 = next_element();

		SVM::Globals::program_stack.push((element1 != std::string("") || element2 != std::string("")) ? "true" : "false");*/
    }

	inline void LNOT()
    {
        /*(next_element() == std::string("")) ? SVM::Globals::program_stack.push("true") : SVM::Globals::program_stack.push("false");*/
    }

	inline void XOR()
    {
        const int8_t data_type = SVM::Globals::program_stack.top_cstring()[0];

        if (data_type == 'n')
        {
            const auto num1 = top_stack_element<uint64_t>();
            const auto num2 = top_stack_element<uint64_t>();

            SVM::Globals::program_stack.push<uint64_t>(num1 ^ num2, 8);
        }
        else if (data_type == 'b')
        {
            const auto bool1 = top_stack_element<bool>();
            const auto bool2 = top_stack_element<bool>();

            SVM::Globals::program_stack.push((bool1 ^ bool2) ? "true" : "false");
        }
    }
}

#endif // !LOGIC_H
