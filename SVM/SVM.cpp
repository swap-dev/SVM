#include "SVM.h"
#include <sys/stat.h>

//uint16_t check_for_exit_condition()
//{
//	if (SVM::Globals::program_stack.empty()) return 0;
//
//	const auto& stack_top = SVM::Globals::program_stack.top();
//	if (!std::holds_alternative<std::string>(stack_top)) return 0;
//
//	const std::string string_el = std::get<std::string>(stack_top);
//	if (string_el.rfind("INTERNAL_SVM_FUNCTION_", 0) != 0) return 0;
//
//	const std::string exit_type = string_el.substr(22);
//
//	if (exit_type == "RETURN") return 1;
//	else if (exit_type == "SELFDESTRUCT") return 2;
//	else if (exit_type == "STOP") return 3;
//	else return 65535;
//}

inline long bytecode_file_size(const char* file_location)
{
    struct stat stat_buf{};
    int rc = stat(file_location, &stat_buf);
    return rc == 0 ? stat_buf.st_size : 0;
}

int main(int argc, char* argv[])
{
	//if (argc < REQUIRED_ARG_COUNT)
	//{
	//	std::cout << "Please specify the bytecode file location as a program argument." << "\n";
	//	return 0;
	//}

    const char* file_location = R"(C:/Users/antonios/Desktop/repos/SVM/SVM/example.svb)";

	std::ifstream bytecode_file(file_location/*argv[0 + REQUIRED_ARG_COUNT - 1]*/, std::ios::in | std::ios::binary);

    const long file_size = bytecode_file_size(file_location);
    if (file_size < 1)
    {
        std::cout << "Failed to get size of bytecode file";
        return 1;
    }

	auto* bytecode = new uint8_t[file_size];
	bytecode_file.read(reinterpret_cast<char*>(bytecode), file_size);
	bytecode_file.close();

	SVM::Utils::initialize_instruction_mappings();

    while (SVM::Globals::program_counter < file_size)
    {
        const SVM::BytecodeProcessor::OpcodeParseReturn parser_return = SVM::BytecodeProcessor::parse_next_opcode(bytecode, SVM::Globals::program_counter, file_size);

        // done executing all instructions
        if (parser_return.opcode_id == 0xFFFF)
            break;

        SVM::Globals::program_counter = parser_return.next_index;
        SVM::Globals::instructions_mapping[parser_return.opcode_id]();

        //	// TODO blockchain integration for exit codes
        //	switch (check_for_exit_condition())
        //	{
        //	case 0:
        //		break;
        //	case 1:
        //		std::cout << "Registered RETURN" << "\n";
        //		return 0;
        //	case 2:
        //		std::cout << "Queueing contract for deletion (SELFDESTRUCT)" << "\n";
        //		return 0;
        //	case 3:
        //		std::cout << "Registered STOP" << "\n";
        //		return 0;
        //	default:
        //		std::cout << "Invalid check_for_exit_condition return code" << "\n";
        //		break;
        //	}
    }

	return 0;
}
