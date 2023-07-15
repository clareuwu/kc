#include <stdio.h>

#include "debug.h"
#include "value.h"

void DisassembleBytecode(bytecode_t *bc, const char *name) {
  printf("== %s ==\n", name);

  for (i32 offset = 0; offset < bc->count;) {
    offset = DisassembleInstruction(bc, offset);
  }
}

static int ConstantInstruction(const char* name, bytecode_t* bc, int offset) {
  u8 constant = bc->code[offset + 1];
  printf("%-16s %4d '", name, constant);
  PrintValue(bc->constants.values[constant]);
  printf("'\n");
  return offset + 2;
}

static int SimpleInstruction(const char* name, i32 offset) {
  printf("%s\n", name);
  return offset + 1;
}

i32 DisassembleInstruction(bytecode_t *bc, i32 offset) {
  printf("%04d ", offset);

  if (offset > 0 && bc->lines[offset] == bc->lines[offset - 1]) {
    printf("   | ");
  } else {
    printf("%4d ", bc->lines[offset]);
  }
  u8 instruction = bc->code[offset];
  switch (instruction) {
    case CONSTANT: return ConstantInstruction("CONSTANT", bc, offset);
    case RET: return SimpleInstruction("RET", offset);
    default:
      printf("Unknown opcode %d\n", instruction);
      return offset + 1;
  }
}
