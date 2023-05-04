#include "SVM.h"

unsigned short check_for_exit_condition()
{
	if (SVM::Globals::program_stack.empty()) return 0;

	const std::string stack_top = SVM::Globals::program_stack.top();
	if (stack_top.rfind("INTERNAL_SVM_FUNCTION_", 0) != 0) return 0;

	const std::string exit_type = stack_top.substr(22);

	if (exit_type == "RETURN") return 1;
	else if (exit_type == "SELFDESTRUCT") return 2;
	else return 65535;
}

int main()
{
	std::string bytecode = "0,Hello World!;4;3,test element";

	SVM::Globals::initialize_instruction_mappings();

	const tsl::ordered_map<unsigned long, std::vector<std::any>> user_instructions = SVM::BytecodeProcessor::bytecode_to_instruction_order(bytecode);

	for (const auto& instruction : user_instructions)
	{
		for (const auto& arg : instruction.second)
		{
			SVM::Globals::program_stack.emplace(std::any_cast<std::string>(arg));
		}
		SVM::Globals::instructions_mapping[instruction.first]();

		switch (check_for_exit_condition())
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

	std::cout << "\n\n";
	while (!SVM::Globals::program_stack.empty())
	{
		const std::string& element = SVM::Globals::program_stack.top();
		std::cout << element << "\n";
		SVM::Globals::program_stack.pop();
	}

	return 0;
}
