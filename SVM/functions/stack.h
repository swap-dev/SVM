#pragma once
#ifndef FUNCTIONS_STACK_H
#define FUNCTIONS_STACK_H

#include "../globals.h"

namespace SVM::stack
{
	inline void PUSH()
    {
        // element would already have been pushed onto the stack
        // nothing to do
    }

    inline void POP()
    {
        SVM::Globals::program_stack.pop();
    }

    inline void SSTORE()
    {
        // TODO awaiting storage provider and blockchain integration
    }

    inline void SLOAD()
    {
        // TODO awaiting storage provider and blockchain integration
    }

    inline void MSIZE()
    {
        SVM::Globals::program_stack.push<uint64_t>(SVM::Globals::program_stack.size(), 8);
    }
}

#endif // !FUNCTIONS_STACK_H
