#ifndef UNTITLED_VM_H
#define UNTITLED_VM_H

#include "../stack/stack.h"

#define MAX_VM_OBJECTS 8

typedef struct {
  Stack *stack;

  Object *first;

  size_t current_objects_count;

  size_t max_object_count;
} VM;

VM *init_vm();

bool destroy_vm(VM *vm);

#endif
