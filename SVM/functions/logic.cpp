#include "logic.h"

namespace SVM::logic
{
	std::string next_element()
	{
		return SVM::Utils::top_stack_element();
	}

	void LT()
	{
		const long double num1 = std::stold(next_element());
		const long double num2 = std::stold(next_element());

		SVM::Globals::program_stack.push((num1 < num2) ? "true" : "false");
	}
	void GT()
	{
		const long double num1 = std::stold(next_element());
		const long double num2 = std::stold(next_element());

		SVM::Globals::program_stack.push((num1 > num2) ? "true" : "false");
	}
	void EQ()
	{
		SVM::Globals::program_stack.push((next_element() == next_element()) ? "true" : "false");
	}
	void OR()
	{
		const std::string data_type = next_element();
		const std::string el1 = next_element();
		const std::string el2 = next_element();

		if (data_type == "n")
		{
			const unsigned long long num1 = std::stoull(el1);
			const unsigned long long num2 = std::stoull(el2);

			SVM::Globals::program_stack.push(std::to_string(num1 | num2));
		}
		else if (data_type == "b")
		{
			const bool bool1 = el1 == "true" ? true : false;
			const bool bool2 = el2 == "true" ? true : false;

			SVM::Globals::program_stack.push((bool1 | bool2) ? "true" : "false");
		}
	}
	void NOT()
	{
		const std::string data_type = next_element();
		const std::string el1 = next_element();

		if (data_type == "n")
		{
			const unsigned long long num1 = std::stoull(el1);

			SVM::Globals::program_stack.push(std::to_string(~num1));
		}
		else if (data_type == "b")
		{
			SVM::Globals::program_stack.push(el1 == "true" ? "false" : "true");
		}
	}
	void LOR()
	{
		const std::string element1 = next_element();
		const std::string element2 = next_element();

		SVM::Globals::program_stack.push((element1 != std::string("") || element2 != std::string("")) ? "true" : "false");
	}
	void LNOT()
	{
		(next_element() == std::string("")) ? SVM::Globals::program_stack.push("true") : SVM::Globals::program_stack.push("false");
	}
	void XOR()
	{
		const std::string data_type = next_element();
		const std::string el1 = next_element();
		const std::string el2 = next_element();

		if (data_type == "n")
		{
			const unsigned long long num1 = std::stoull(el1);
			const unsigned long long num2 = std::stoull(el2);

			SVM::Globals::program_stack.push(std::to_string(num1 ^ num2));
		}
		else if (data_type == "b")
		{
			const bool bool1 = el1 == "true" ? true : false;
			const bool bool2 = el2 == "true" ? true : false;

			SVM::Globals::program_stack.push((bool1 ^ bool2) ? "true" : "false");
		}
	}
}