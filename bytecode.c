#include <stdlib.h>

#include "bytecode.h"

void InitBytecode(bytecode_t* bc) {
  bc->count = 0;
  bc->capacity = 0;
  bc->code = NULL;
}

void WriteBytecode(bytecode_t* bc, u8 byte) {
  if (bc->capacity < bc->count + 1) {
    u32 oldCapacity = bc->capacity;
    bc->capacity = GROW_CAPACITY(oldCapacity);
    bc->code = GROW_ARRAY(u8, bc->code, oldCapacity, bc->capacity);
  }

  bc->code[bc->count] = byte;
  bc->count++;
}

void FreeBytecode(bytecode_t* bc) {
  FREE_ARRAY(u8, bc->code, bc->capacity);
  InitBytecode(bc);
}
