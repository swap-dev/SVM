#pragma once
#ifndef SMV_H
#define SVM_H

#include <iostream>
#include <fstream>
#include <vector>
#include "bytecode_processor.h"
#include "globals.h"
#include "utils.h"

#if (defined (_WIN32) || defined (_WIN64))
constexpr uint8_t REQUIRED_ARG_COUNT = 2;
#else
constexpr uint8_t REQUIRED_ARG_COUNT = 1;
#endif

#endif // !SMV_H