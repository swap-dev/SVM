#pragma once

#ifndef ASSEMBLY_PROCESSOR_H
#define ASSEMBLY_PROCESSOR_H

#include <cstdint>

constexpr uint8_t BYTECODE_SEPARATOR = 0x3B;

namespace SVM::BytecodeProcessor {
	struct OpcodeParseReturn {
		uint64_t opcode_id;
        uint64_t next_index;
	};

	/// <summary>
	/// gather opcode ID and push opcode parameters onto the stack
	/// </summary>
	/// <returns>opcode ID</returns>
	OpcodeParseReturn parse_next_opcode(const uint8_t* bytecode, uint64_t start_from, uint64_t bytecode_length);
}

#endif // !ASSEMBLY_PROCESSOR_H
