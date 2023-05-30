#pragma once
#ifndef FUNCTIONS_PROCESS_FLOW_H
#define FUNCTIONS_PROCESS_FLOW_H

#include "base_include.h"

namespace SVM::process_flow
{
    template <typename T>
    inline T top_stack_element()
    {
        T el = SVM::Globals::program_stack.top<T>();
        SVM::Globals::program_stack.pop();
        return el;
    }

    inline void set_program_counter(uint64_t value)
    {
        SVM::Globals::program_counter = value;
    }

	inline void STOP()
    {
        SVM::Globals::program_stack.push_cstring("INTERNAL_SVM_STOP", 27);
    }

    inline void JMP()
    {
        set_program_counter(static_cast<size_t>(top_stack_element<uint64_t>()));
    }

    inline void JMPI()
    {
        const auto location = static_cast<size_t>(top_stack_element<uint64_t>());
        if (top_stack_element<bool>())
            set_program_counter(location);
    }
}

#endif // !FUNCTIONS_PROCESS_FLOW_H
