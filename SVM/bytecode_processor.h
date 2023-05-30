#pragma once

#ifndef ASSEMBLY_PROCESSOR_H
#define ASSEMBLY_PROCESSOR_H

constexpr char BYTECODE_SEPARATOR = 0x3B;
//constexpr char ARG_SEPARATOR = 0x2C;

#include <cstdint>

namespace SVM::BytecodeProcessor {
	struct OpcodeParseReturn {
		uint64_t opcode_id;
        uint64_t next_index;
	};

	/// <summary>
	/// gather opcode ID and push opcode parameters onto the stack
	/// </summary>
	/// <returns>opcode ID</returns>
	OpcodeParseReturn parse_next_opcode(const unsigned char* bytecode, unsigned long long start_from, unsigned long long bytecode_length);
}

#endif // !ASSEMBLY_PROCESSOR_H
