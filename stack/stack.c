#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Stack *init_stack() {
  Stack *stack = calloc(1, sizeof(Stack));

  return stack;
}

bool destroy_stack(Stack *stack) {
  if (stack == NULL)
    return false;

  free(stack);

  return true;
}

void push(Stack *stack, Object *object) {
  stack->stack[stack->size++] = object;
}

Object *object(Stack *stack) { return stack->stack[--stack->size]; }

