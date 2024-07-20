#include "vm.h"
#include <stdbool.h>
#include <stdlib.h>

VM *init_vm() {
  VM *vm = calloc(1, sizeof(VM));

  vm->current_objects_count = 0;
  vm->max_object_count = MAX_VM_OBJECTS;

  vm->first = NULL;
  vm->stack = init_stack();

  return vm;
}

bool destroy_vm(VM *vm) {
  if (vm == NULL)
    return false;

  destroy_stack(vm->stack);

  destroy_object_recursive(vm->first);

  free(vm);

  return true;
}