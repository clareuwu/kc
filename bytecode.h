#ifndef kc_bytecode
#define kc_bytecode

#include "common.h"

typedef enum {
  RET,
} OpCode;

typedef struct {
  u32 count;
  u32 capacity;
  u8* code;
} bytecode_t;

void InitBytecode(bytecode_t* bc);
void WriteBytecode(bytecode_t* bc, u8 byte);

#endif
