# SVM
Swap Virtual Machine bytecode interpreter.

## Documentation for Supported Instructions

### NOTES:
* Unless otherwise noted, boolean results are pushed onto the stack as `true` or `false`
* Unless otherwise noted, math opcodes remove the two topmost stack elements and place the result onto the top of the stack
* Unless otherwise noted, logic opcodes (`LT`, `GT`, etc.) Pop the two topmost elements on the stack and emplace a boolean result on the top of the stack

|Bytecode Identifier|Opcode Symbol|Arguments|Description|
|-------------------|-------------|---------|-----------|
|0|`LOG`|none|Add a log entry to blockchain storage (in the future; currently prints to console)|
|1|`RETURN`|none|Halt code execution and return output data|
|2|`SELFDESTRUCT`|none|Halt execution and mark smart contract for destruction (***IRREVERSIBLE!*** Use with caution)|
|3|`PUSH`|`<element>`|Push an element onto the program stack|
|4|`POP`|none|Remove the top-most element from the program stack|
|5|`SSTORE`|`<id>`,`<element>`|Store an element with identifier `<id>` in blockchain storage|
|6|`SLOAD`|`<id>`|Get an element with identifier `<id>` from blockchain storage and emplace it onto the stack|
|7|`MSIZE`|none|Emplace the size of the stack (in bytes; calculated before this operation) onto the stack|
|8|`ADD`|none|[Addition](https://en.wikipedia.org/wiki/Addition) (See Notes)|
|9|`SUB`|none|[Subtraction](https://en.wikipedia.org/wiki/Subtraction) (See Notes)|
|10|`MUL`|none|[Multiplication](https://en.wikipedia.org/wiki/Multiplication) (See Notes)|
|11|`DIV`|none|[Division](https://en.wikipedia.org/wiki/Division) (See Notes)|
|12|`MOD`|none|[Modulo](https://en.wikipedia.org/wiki/Addition) (See Notes)|
|13|`POW`|none|[Exponentiation](https://en.wikipedia.org/wiki/Modulo)|
|14|`STOP`|none|Halt program execution immediately|
|15|`JMP`|`<instruction_index>`|Jump to the specified opcode index, removing the `<instruction_index>` argument pushed to the stack in the process.|
|16|`JMPI`|`<instruction_index>`|Jump to the specified opcode index if the topmost element (before `<instruction_index>` is pushed onto the stack as a parameter) on the stack evaluates to `true`, removing the `<instruction_index>` argument pushed to the stack in the process.|
|17|`LT`|none|Less Than (See Notes)|
|18|`GT`|none|Greater Than (See Notes)|
|19|`EQ`|none|Equal To (See Notes)|
|20|`LOR`|none|Logical OR (See Notes)|
|21|`LNOT`|none|Logical NOT (See Notes)|
|22|`OR`|none|Bitwise OR (See Notes)|
|23|`NOT`|none|Bitwise NOT (See Notes)|
|24|`XOR`|none|Bitwise XOR (See Notes)|