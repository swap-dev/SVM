# SVM
Swap Virtual Machine bytecode interpreter.

## Documentation for Supported Instructions

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
|8|`ADD`|none|Pop the top two elements on the stack and emplace the resulting sum onto the top of the stack|
|9|`SUB`|none|Pop the top two elements on the stack and emplace the resulting difference onto the top of the stack|
|10|`MUL`|none|Pop the top two elements on the stack and emplace the resulting product onto the top of the stack|
|11|`DIV`|none|Pop the top two elements on the stack and emplace the resulting quotient onto the top of the stack|
|12|`MOD`|none|Pop the top two elements on the stack and emplace the resulting remainder from the two elements' quotient onto the top of the stack|
|13|`POW`|none|Pop the top two elements on the stack. Raise the topmost element to the power of the second element as a number and emplace the result onto the top of the stack|