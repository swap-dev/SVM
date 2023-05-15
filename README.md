# SVM
Swap Virtual Machine bytecode interpreter.

## Available Virtual Registers

### NOTES:
* All registers have a datatype of UInt64 (`unsigned long long`)
* While you can use each register for any operation, some recommended uses are listed in the table below

|Register|Recommended Use|
|--------|---------------|
|GA|General purpose|
|GB|General purpose|
|GC|General purpose|
|GD|General purpose|
|GE|General purpose|
|GF|General purpose|
|CA|Loop counter|
|IA|Intermediate operation data storage|
|IB|Intermediate operation data storage|
|IC|Intermediate operation data storage|
|ID|Intermediate operation data storage|

## Supported Instructions

### NOTES:
* Unless otherwise noted, boolean results are pushed onto the stack as `true` or `false`
* Unless otherwise noted, math opcodes remove the two topmost stack elements and place the result onto the top of the stack
* Unless otherwise noted, logic opcodes (`LT`, `GT`, etc.) Pop the two topmost elements on the stack and emplace a boolean result on the top of the stack
* Bitwise opcodes support the following data types: `n`, `b`, standing for number and boolean
* All stack elements that undergo processing in the same opcode must be the same data type

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
|8|`ADD`|none|[Addition](https://en.wikipedia.org/wiki/Addition)|
|9|`SUB`|none|[Subtraction](https://en.wikipedia.org/wiki/Subtraction)|
|10|`MUL`|none|[Multiplication](https://en.wikipedia.org/wiki/Multiplication)|
|11|`DIV`|none|[Division](https://en.wikipedia.org/wiki/Division)|
|12|`MOD`|none|[Modulo](https://en.wikipedia.org/wiki/Addition)|
|13|`POW`|none|[Exponentiation](https://en.wikipedia.org/wiki/Modulo)|
|14|`STOP`|none|Halt program execution immediately|
|15|`JMP`|`<instruction_index>`|Jump to the specified opcode index, removing the `<instruction_index>` argument pushed to the stack in the process.|
|16|`JMPI`|`<instruction_index>`|Jump to the specified opcode index if the topmost element (before `<instruction_index>` is pushed onto the stack as a parameter) on the stack evaluates to `true`, removing the `<instruction_index>` argument pushed to the stack in the process.|
|17|`LT`|none|Less Than|
|18|`GT`|none|Greater Than|
|19|`EQ`|none|Equal To|
|20|`LOR`|none|Logical OR|
|21|`LNOT`|none|Logical NOT; Only checks the topmost element in the stack|
|22|`OR`|`<data_type>`|Bitwise OR|
|23|`NOT`|`<data_type>`|Bitwise NOT|
|24|`XOR`|`<data_type>`|Bitwise XOR|
|25|`SETREG`|`<register>`,`<value>`|Set register `<register>` to a value of `<value>`|
|26|`GETREG`|`<register>`|Get the value of the register `<register>`
|27|`INCREG`|`<register>`|Increment the value of the register `<register>` by one|
