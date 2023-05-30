#include "bytecode_processor.h"
#include <iostream>
#include "globals.h"

namespace SVM::BytecodeProcessor {
	OpcodeParseReturn parse_next_opcode(const uint8_t* bytecode, uint64_t start_from, uint64_t bytecode_length)
	{
        if (start_from >= bytecode_length) return OpcodeParseReturn{0xFFFF, 0xFFFFFFFFFFFFFFFF};

		uint64_t instruction_stop = start_from;
        while (bytecode[instruction_stop] != BYTECODE_SEPARATOR) {
            if (instruction_stop == bytecode_length) break;
            instruction_stop++;
        }

        // parsed all instructions
        if (instruction_stop == start_from) return OpcodeParseReturn{0xFFFF, 0xFFFFFFFFFFFFFFFF};

        const uint16_t opcode = *reinterpret_cast<const uint16_t*>(bytecode + start_from);

        uint64_t pos_parsed = start_from + 2; // +2 for opcode uint16
        while (pos_parsed < instruction_stop)
        {
            const uint8_t* arg_offset = bytecode + pos_parsed;
            const uint8_t arg_size = *reinterpret_cast<const uint8_t*>(arg_offset);
            arg_offset++;

            if (bytecode[pos_parsed + 1] == '"')
            {
                SVM::Globals::program_stack.push_cstring(reinterpret_cast<const char*>(arg_offset + 1)); // +1 to avoid `"`
            }
            else
            {
                uint64_t val = 0;
                memcpy(&val, reinterpret_cast<const uint8_t*>(arg_offset), arg_size);
                SVM::Globals::program_stack.push<uint64_t>(val, 8);
            }

            pos_parsed += arg_size + 1; // +1 for arg_size byte;
        }

        return OpcodeParseReturn {opcode, instruction_stop + 1};
	}
}