#ifndef kc_value
#define kc_value

#include "common.h"

typedef double value_t;

typedef struct {
  u32 capacity;
  u32 count;
  value_t* values;
} value_array_t;

void InitValueArray(value_array_t* arr);
void WriteValueArray(value_array_t* arr, value_t val);
void FreeValueArray(value_array_t* arr);
void PrintValue(value_t val);

#endif
