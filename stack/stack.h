#ifndef _STACK_H
#define _STACK_H

#include "../object/object.h"
#include <stddef.h>

#define MAX_STACK_SIZE 256
#define GC_START_COUNT 8

typedef struct {
  Object *stack[MAX_STACK_SIZE];
  size_t size;
} Stack;

#endif
