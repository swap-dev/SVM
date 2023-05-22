#pragma once

#ifndef ASSEMBLY_PROCESSOR_H
#define ASSEMBLY_PROCESSOR_H

constexpr char BYTECODE_SEPARATOR = ';';
constexpr char ARG_SEPARATOR = ',';

#include <map>
#include <string>
#include <vector>

namespace SVM::BytecodeProcessor {
	std::vector<std::map<unsigned long long, std::vector<std::string>>> bytecode_to_instruction_order(std::string& bytecode);
	std::vector<std::string> arg_string_to_arg_vector(std::string& args, ptrdiff_t& expected_count);

	std::vector<std::string> string_split(std::string& target, const char, ptrdiff_t& expected_count);
}

#endif // !ASSEMBLY_PROCESSOR_H
