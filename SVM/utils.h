#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "globals.h"

namespace SVM::Utils
{
    extern bool strings_are_equal(const char* str1, const char* str2);
    extern void initialize_instruction_mappings();
}

#endif // !UTILS_H
