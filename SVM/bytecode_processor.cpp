#include "bytecode_processor.h"

namespace SVM::BytecodeProcessor {
	std::vector<std::map<unsigned long long, std::vector<std::string>>> bytecode_to_instruction_order(std::string& bytecode) {
		std::vector<std::map<unsigned long long, std::vector<std::string>>> ret;

		ptrdiff_t instruction_count = std::count(bytecode.begin(), bytecode.end(), BYTECODE_SEPARATOR);
		ret.reserve(instruction_count);

		const auto instructions = string_split(bytecode, BYTECODE_SEPARATOR, instruction_count);
		for (const std::string& instruction : instructions)
		{
			ptrdiff_t argument_count = std::count(instruction.begin(), instruction.end(), ARG_SEPARATOR);
			const size_t first_comma_location = instruction.find(ARG_SEPARATOR);

			std::vector<std::string> args;

			if (first_comma_location != std::string::npos)
			{
				std::string next = instruction.substr(first_comma_location + 1);
				args = arg_string_to_arg_vector(next, argument_count);
			}
			ret.emplace_back(std::map<unsigned long long, std::vector<std::string>>{ { std::stoull(instruction.substr(0, first_comma_location)), args } });
		}

		return ret;
	}

	std::vector<std::string> arg_string_to_arg_vector(std::string& args, ptrdiff_t& expected_count)
	{
		return string_split(args, ARG_SEPARATOR, expected_count);
	}

	std::vector<std::string> string_split(std::string& target, const char separator, ptrdiff_t& expected_count)
	{
		std::vector<std::string> ret;
		if (expected_count != -1) ret.reserve(expected_count);

		size_t pos = 0;
		while ((pos = target.find(separator)) != std::string::npos) {
			ret.emplace_back(target.substr(0, pos));
			target.erase(0, pos + 1); // (pos + 1) accounts for the length of the bytecode separator
		}
		// store the last remaining arg (if it exists)
		if (target.length() > 0) ret.emplace_back(target);

		return ret;
	}
}