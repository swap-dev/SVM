#pragma once
#ifndef UTILS_H
#define UTILS_H

#include "globals.h"

namespace SVM::Utils
{
	template <typename T>
	inline T top_stack_element()
	{
		T top_element = SVM::Globals::program_stack.top<T>();
		SVM::Globals::program_stack.pop();
		return top_element;
	}
}

#endif // !UTILS_H
