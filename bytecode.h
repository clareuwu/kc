#ifndef kc_bytecode
#define kc_bytecode

#include "common.h"
#include "value.h"
#include "memory.h"

typedef enum {
  CONSTANT,
  RET,
} op_code_t;

typedef struct {
  u32 count;
  u32 capacity;
  u8* code;
  u32* lines;
  value_array_t constants;
} bytecode_t;

void InitBytecode(bytecode_t* bc);
void WriteBytecode(bytecode_t* bc, u8 byte, u32 line);
void FreeBytecode(bytecode_t* bc);
i32  AddConstant(bytecode_t* bc, value_t val);

#endif
