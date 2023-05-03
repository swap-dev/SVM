#include "SVM.h"

unsigned short check_for_exit_condition(std::stack<std::string>& program_stack)
{
	const std::string stack_top = program_stack.top();
	if (stack_top.rfind("INTERNAL_SVM_FUNCTION_", 0) != 0) return 0;

	const std::string exit_type = stack_top.substr(22);

	if (exit_type == "RETURN") return 1;
	else if (exit_type == "SELFDESTRUCT") return 2;
	else return 65535;
}

int main()
{
	std::string bytecode = "0,Hello World!;1";

	SVM::Globals::initialize_instruction_mappings();

	const std::map<unsigned long, std::vector<std::any>> user_instructions = SVM::BytecodeProcessor::bytecode_to_instruction_order(bytecode);

	for (const auto& instruction : user_instructions)
	{
		for (const auto& arg : instruction.second)
		{
			SVM::Globals::program_stack.emplace(std::any_cast<std::string>(arg));
			std::cout << "stack size: " << SVM::Globals::program_stack.size() << "\n";
		}

		std::cout << "instruction ID: " << instruction.first << "\n";

		SVM::Globals::instructions_mapping[instruction.first]();

		switch (check_for_exit_condition(SVM::Globals::program_stack))
		{
		case 0:
			break;
		// TODO blockchain integration for RETURN and SELFDESTRUCT
		case 1:
			std::cout << "Registered RETURN" << "\n";
			return 0;
		case 2:
			std::cout << "Queueing contract for deletion (SELFDESTRUCT)" << "\n";
			return 0;
		default:
			std::cout << "Invalid check_for_exit_condition return code" << "\n";
			break;
		}
	}

	return 0;
}
