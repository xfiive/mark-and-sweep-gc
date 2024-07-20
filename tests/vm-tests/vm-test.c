#include "vm-test.h"

void vm_init_and_destroy_test() {
  VM *vm = init_vm();

  if (vm != NULL)
    printf("\nVM is okay");
  else
    printf("\nVM is not okay");

  printf("\nResult of vm destroying: %d\n", destroy_vm(vm));
}

void vm_tests() { vm_init_and_destroy_test(); }