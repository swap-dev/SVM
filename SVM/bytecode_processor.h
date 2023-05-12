#pragma once

#ifndef ASSEMBLY_PROCESSOR_H
#define ASSEMBLY_PROCESSOR_H

constexpr const char* BYTECODE_SEPARATOR = ";";
constexpr const char* ARG_SEPARATOR = ",";

#include <map>
#include <any>
#include <string>
#include <vector>

namespace SVM::BytecodeProcessor {
	std::vector<std::map<unsigned long long, std::vector<std::any>>> bytecode_to_instruction_order(std::string bytecode);
	std::vector<std::any> arg_string_to_arg_vector(std::string args);

	std::vector<std::any> string_split(std::string target, const std::string separator);
}

#endif // !ASSEMBLY_PROCESSOR_H
