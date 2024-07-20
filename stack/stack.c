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

Object *pop(Stack *stack) { return stack->stack[--stack->size]; }

void print_stack_objects(Stack *stack) {
  if (stack == NULL)
    return;

  for (size_t i = 0; i < stack->size; i++) {
    print_object(stack->stack[i]);
  }
}
