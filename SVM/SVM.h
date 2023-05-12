#pragma once
#ifndef SMV_H
#define SVM_H

#if (defined (_WIN32) || defined (_WIN64))
constexpr unsigned short REQUIRED_ARG_COUNT = 2;
#else
constexpr unsigned short REQUIRED_ARG_COUNT = 1;
#endif

#include <iostream>
#include <vector>
#include <any>
#include "bytecode_processor.h"
#include "globals.h"

#endif // !SMV_H