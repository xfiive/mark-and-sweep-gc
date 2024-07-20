#ifndef UNTITLED_VM_H
#define UNTITLED_VM_H

#include "../object/object.h"
#include "../stack/stack.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VM_OBJECTS 8

typedef struct {
  Stack *stack;

  Object *first;

  size_t current_objects_count;

  size_t max_object_count;
} VM;

VM *init_vm();

bool destroy_vm(VM *vm);

void gc(VM *vm);

Object *push_object(VM *vm);

void push_digit(VM *vm, double digit);

Object *push_pair(VM *vm);

#endif
