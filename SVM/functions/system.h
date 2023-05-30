#pragma once
#ifndef ASSEMBLY_FUNCTIONS_SYSTEM_H
#define ASSEMBLY_FUNCTIONS_SYSTEM_H

#include "base_include.h"
#include <iostream>

namespace SVM::system {
	inline void LOG()
    {
        if (SVM::Globals::program_stack.top_el_is_cstring())
        {
            std::cout << SVM::Globals::program_stack.top_cstring() << "\n";
            SVM::Globals::program_stack.pop();
            return;
        }

        switch (SVM::Globals::program_stack.top_el_size())
        {
            case 1:
                std::cout << SVM::Globals::program_stack.top<bool>() << "\n";
                break;
            case 8:
                std::cout << SVM::Globals::program_stack.top<uint64_t>() << "\n";
                break;
        }

        SVM::Globals::program_stack.pop();
    }

    inline void RETURN()
    {
        SVM::Globals::program_stack.push_cstring("INTERNAL_SVM_RETURN", 20);
    }

    inline void SELFDESTRUCT()
    {
        SVM::Globals::program_stack.push_cstring("INTERNAL_SVM_SELFDESTRUCT", 26);
    }
}

#endif // !ASSEMBLY_FUNCTIONS_SYSTEM_H