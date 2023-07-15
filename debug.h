#ifndef kc_debug
#define kc_debug

#include "bytecode.h"

void DisassembleBytecode(bytecode_t* bc, const char* name);
i32 DisassembleInstruction(bytecode_t* bc, i32 offset);

#endif
