#include "vm.h"

VM *init_vm() {
  VM *vm = calloc(1, sizeof(VM));

  vm->current_objects_count = 0;
  vm->max_object_count = MAX_VM_OBJECTS;

  vm->first = NULL;
  vm->stack = init_stack();

  return vm;
}

void mark_all(VM *vm) {
  if (vm == NULL)
    return;

  for (size_t i = 0; i < vm->stack->size; i++) {
    mark_object(vm->stack->stack[i]);
  }
}

void mark_and_sweep(VM *vm) {
  Object **object = &vm->first;

  while (*object) {
    if (!(*object)->is_marked) {
      Object *unreachable_obj = *object;

      *object = unreachable_obj->next;
      free(unreachable_obj);

      vm->current_objects_count--;
    } else {
      (*object)->is_marked = false;
      object = &(*object)->next;
    }
  }
}

void gc(VM *vm) {
  size_t current_objects_count = vm->current_objects_count;

  mark_all(vm);
  mark_and_sweep(vm);

  vm->max_object_count =
      vm->current_objects_count * 2; // Actually there could be a better way of
                                     // re-allocation memory for that thing

  printf("\x1b[32mCollect %lu objects, %lu are still left.\n",
         current_objects_count - vm->current_objects_count,
         vm->current_objects_count);
}

Object *push_object(VM *vm) {
  if (vm->current_objects_count == vm->max_object_count) {
    gc(vm);
  }

  Object *object = init_object(DIGIT);

  object->next = vm->first;
  vm->first = object;
  object->is_marked = false;

  vm->current_objects_count++;

  return object;
}

void push_digit(VM *vm, double digit) {
  if (vm == NULL) {
    return;
  }

  Object *object = push_object(vm);

  object->value = digit;

  push(vm->stack, object);
}

Object *push_pair(VM *vm) {
  if (vm == NULL) {
    return NULL;
  }

  Object *object = push_object(vm);

  object->tail = pop(vm->stack);
  object->head = pop(vm->stack);

  push(vm->stack, object);
  return object;
}

bool destroy_vm(VM *vm) {
  if (vm == NULL)
    return false;

  vm->stack->size = 0;

  gc(vm);
  destroy_stack(vm->stack);

  free(vm);

  return true;
}