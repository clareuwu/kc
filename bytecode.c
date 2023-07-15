#include <stdlib.h>

#include "bytecode.h"

void InitBytecode(bytecode_t* bc) {
  bc->count = 0;
  bc->capacity = 0;
  bc->code = NULL;
  bc->lines = NULL;
  InitValueArray(&bc->constants);
}

void WriteBytecode(bytecode_t* bc, u8 byte, u32 line) {
  if (bc->capacity < bc->count + 1) {
    u32 oldCapacity = bc->capacity;
    bc->capacity = GROW_CAPACITY(oldCapacity);
    bc->code = GROW_ARRAY(u8, bc->code, oldCapacity, bc->capacity);
    bc->lines = GROW_ARRAY(u32, bc->lines, oldCapacity, bc->capacity);
  }

  bc->code[bc->count] = byte;
  bc->lines[bc->count] = line;
  bc->count++;
}

void FreeBytecode(bytecode_t* bc) {
  FREE_ARRAY(u8, bc->code, bc->capacity);
  FREE_ARRAY(u32, bc->lines, bc->capacity);
  FreeValueArray(&bc->constants);
  InitBytecode(bc);
}

i32 AddConstant(bytecode_t *bc, value_t val) {
  WriteValueArray(&bc->constants, val);
  return bc->constants.count - 1;
}
