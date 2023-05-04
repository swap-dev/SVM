# SVM
Swap Virtual Machine bytecode interpreter.

## Documentation for Supported Instructions

|Bytecode Identifier|Opcode Symbol|Arguments|Description|
|-------------------|-------------|---------|-----------|
|0|`LOG`|`<message>`|Add a log entry to blockchain storage (in the future; currently prints to console)|
|1|`RETURN`|none|Halt code execution and return output data|
|2|`SELFDESTRUCT`|none|Halt execution and mark smart contract for destruction (***IRREVERSIBLE!*** Use with caution)|
|3|`PUSH`|`<element>`|Push an element onto the program stack|
|4|`POP`|none|Remove the top-most element from the program stack|
|5|`SSTORE`|`<id>`,`<element>`|Store an element with identifier `<id>` in blockchain storage|
|6|`SLOAD`|`<id>`|Get an element with identifier `<id>` from blockchain storage and emplace it onto the stack|
|7|`MSIZE`|none|Emplace the size of the stack (in bytes; calculated before this operation) onto the stack|