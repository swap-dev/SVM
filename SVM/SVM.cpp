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

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please input your bytecode as a program argument." << "\n";
		return 0;
	}

	std::string bytecode = std::string(argv[1]);

	SVM::Globals::initialize_instruction_mappings();

	const std::vector<std::map<unsigned long, std::vector<std::any>>> user_instructions = SVM::BytecodeProcessor::bytecode_to_instruction_order(bytecode);

	while (SVM::Globals::program_counter < user_instructions.size())
	{
		const auto instruction = user_instructions[SVM::Globals::program_counter].begin();
		for (const auto& arg : instruction->second)
		{
			SVM::Globals::program_stack.emplace(std::any_cast<std::string>(arg));
		}

		SVM::Globals::instructions_mapping[instruction->first]();

		// TODO blockchain integration for exit codes
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
		
		SVM::Globals::program_counter++;
	}

	return 0;
}
