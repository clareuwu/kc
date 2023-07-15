#include <stdio.h>

#include "memory.h"
#include "value.h"

void InitValueArray(value_array_t *arr) {
  arr->values = NULL;
  arr->capacity = 0;
  arr->count = 0;
}

void WriteValueArray(value_array_t *arr, value_t val) {
  if (arr->capacity < arr->count + 1) {
    u32 oldCapacity = arr->capacity;
    arr->capacity = GROW_CAPACITY(oldCapacity);
    arr->values = GROW_ARRAY(value_t, arr->values, oldCapacity, arr->capacity);
  }

  arr->values[arr->count] = val;
  arr->count++;
}

void FreeValueArray(value_array_t *arr) {
  FREE_ARRAY(value_t, arr->values, arr->capacity);
  InitValueArray(arr);
}

void PrintValue(value_t val) {
  printf("%g", val);
}
