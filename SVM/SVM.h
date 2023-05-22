#pragma once
#ifndef SMV_H
#define SVM_H

#if (defined (_WIN32) || defined (_WIN64))
constexpr unsigned char REQUIRED_ARG_COUNT = 2;
#else
constexpr unsigned char REQUIRED_ARG_COUNT = 1;
#endif

#include <iostream>
#include <vector>
//#include "bytecode_processor.h"
#include "globals.h"
#include "flexible_stack.h"

#endif // !SMV_H