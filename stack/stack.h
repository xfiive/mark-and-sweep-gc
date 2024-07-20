#ifndef _STACK_H
#define _STACK_H

#include "../object/object.h"
#include <stddef.h>

#define MAX_STACK_SIZE 256

typedef struct {
  Object *stack[MAX_STACK_SIZE];
  size_t size;
} Stack;

Stack *init_stack();

bool destroy_stack(Stack *stack);

void push(Stack *stack, Object *object);

Object *pop(Stack *stack);

#endif
