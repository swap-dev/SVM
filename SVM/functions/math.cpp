#include "math.h"
#include <cmath>

namespace SVM::math
{
	long double next_number()
	{
		long double next_number = std::stold(SVM::Globals::program_stack.top());
		SVM::Globals::program_stack.pop();
		return next_number;
	}

	void ADD()
	{
		SVM::Globals::program_stack.emplace(std::to_string(next_number() + next_number()));
	}
	void SUB()
	{
		SVM::Globals::program_stack.emplace(std::to_string(next_number() - next_number()));
	}
	void MUL()
	{
		SVM::Globals::program_stack.emplace(std::to_string(next_number() * next_number()));
	}
	void DIV()
	{
		SVM::Globals::program_stack.emplace(std::to_string(next_number() / next_number()));
	}
	void MOD()
	{
		long double num1 = next_number();
		long double num2 = next_number();
		SVM::Globals::program_stack.emplace(std::to_string(fmodl(num1, num2)));
	}
	void POW()
	{
		long double number = next_number();
		long double power = next_number();
		SVM::Globals::program_stack.emplace(std::to_string(pow(number, power)));
	}
}