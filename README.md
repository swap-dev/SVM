# SVM
Swap Virtual Machine bytecode interpreter.

## Documentation for Supported Instructions

|Bytecode Identifier|Assembly Symbol|Arguments|Description|
|-------------------|---------------|---------|-----------|
|0|`LOG`|`<message>`|Add a log entry to blockchain storage (in the future; currently prints to console)|
|1|`RETURN`|none|Halt code execution and return output data|
|2|`SELFDESTRUCT`|none|Halt execution and mark smart contract for destruction (***IRREVERSIBLE!*** Use with caution)|