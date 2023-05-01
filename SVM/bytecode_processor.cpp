#include "bytecode_processor.h"

namespace SVM::BytecodeProcessor {
	std::map<unsigned long, std::vector<std::any>> bytecode_to_instruction_order(std::string bytecode) {
		std::map<unsigned long, std::vector<std::any>> ret;

		size_t pos = 0;
		std::string instruction;
		const auto instructions = string_split(bytecode, BYTECODE_SEPARATOR);

		for (const std::any& el : instructions)
		{
			const std::string instruction = std::any_cast<const std::string>(el);
			const size_t first_comma_location = instruction.find(ARG_SEPARATOR);

			std::vector<std::any> args;

			if (first_comma_location != std::string::npos)
			{
				args = arg_string_to_arg_vector(instruction.substr(first_comma_location + 1));
			}

			ret[std::stoul(instruction.substr(0, first_comma_location))] = args;
		}

		return ret;
	}

	std::vector<std::any> arg_string_to_arg_vector(std::string args)
	{
		return string_split(args, ARG_SEPARATOR);
	}

	std::vector<std::any> string_split(std::string target, const std::string separator)
	{
		std::vector<std::any> ret;

		size_t pos = 0;
		std::string element;
		while ((pos = target.find(separator)) != std::string::npos) {
			element = target.substr(0, pos);
			ret.push_back(element);
			target.erase(0, pos + std::string(separator).length());
		}

		// store the last remaining arg (if it exists)
		if (target.length() > 0)
		{
			ret.push_back(target);
		}

		return ret;
	}
}