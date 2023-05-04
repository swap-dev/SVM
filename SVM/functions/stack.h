#pragma once
#ifndef FUNCTIONS_STACK_H
#define FUNCTIONS_STACK_H

#include "../globals.h"
#include <string>

namespace SVM::stack
{
	constexpr unsigned long long STD_STRING_SIZE = sizeof(std::string);

	void PUSH();
	void POP();
	void SSTORE();
	void SLOAD();
	void MSIZE();
}

#endif // !FUNCTIONS_STACK_H
