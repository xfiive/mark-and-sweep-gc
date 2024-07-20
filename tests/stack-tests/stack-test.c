#include "stack-test.h"

void stack_init_and_destroy_test() {
  puts("Starting 'stack_init_and_destroy_test' test.");

  Stack *stack = init_stack();

  if (stack != NULL)
    printf("\nStack is okay");
  else
    printf("\nStack is not okay");

  printf("\nResult of stack destroying: %d\n", destroy_stack(stack));

  puts("Finishing 'stack_init_and_destroy_test' test.");
}

// void stack_push_and_pop_test() { Stack *stack = init_stack(); }

void stack_tests() { stack_init_and_destroy_test(); }