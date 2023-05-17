#include "utils.h"

namespace SVM::Utils
{
	std::string top_stack_element()
	{
		std::string top_element = SVM::Globals::program_stack.top();
		SVM::Globals::program_stack.pop();
		return top_element;
	}
}