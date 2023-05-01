#include "SVM.h"

int main()
{
	std::stack<std::string> program_stack;

	std::map<unsigned long, std::function<void(std::stack<std::string>&)>> instructions_mapping;
	SVM::system::append_functions(instructions_mapping);

	std::string bytecode = "0,Hello World!";

	const std::map<unsigned long, std::vector<std::any>> user_instructions = SVM::BytecodeProcessor::bytecode_to_instruction_order(bytecode);

	for (const auto& instruction : user_instructions)
	{
		for (const auto& arg : instruction.second)
		{
			program_stack.push(std::any_cast<std::string>(arg));
		}

		instructions_mapping[instruction.first](program_stack);
	}

	return 0;
}
