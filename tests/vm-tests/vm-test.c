#include "vm-test.h"

void vm_init_and_destroy_test() {
  puts("Starting 'vm_init_and_destroy_test' test.");

  VM *vm = init_vm();

  if (vm != NULL)
    printf("\nVM is okay");
  else
    printf("\nVM is not okay");

  printf("\nResult of vm destroying: %d\n", destroy_vm(vm));

  puts("Finishing 'vm_init_and_destroy_test' test.");
}

void vm_push_digits_test() {
  puts("Starting 'vm_push_digits_test' test.");

  puts("\nObjects on the stack are correclt preserved.");

  VM *vm = init_vm();

  push_digit(vm, 1.0);
  push_digit(vm, 2.0);
  push_digit(vm, 3.0);

  gc(vm);
  destroy_vm(vm);

  puts("Finishing 'vm_push_digits_test' test.");
}

void vm_collect_unreached_objects() {
  puts("Starting 'vm_collect_unreached_objects' test.");

  puts("\nGC collects unreached objects.");

  VM *vm = init_vm();

  push_digit(vm, 1.0);
  push_digit(vm, 2.0);
  push_digit(vm, 3.0);
  pop(vm->stack);
  pop(vm->stack);

  gc(vm);
  destroy_vm(vm);

  puts("Finishing 'vm_collect_unreached_objects' test.");
}

void vm_reach_nested_objects() {
  puts("Starting 'vm_reach_nested_objects' test.");

  puts("\nGC reaches nested objects.");

  VM *vm = init_vm();

  push_digit(vm, 1.0);
  push_digit(vm, 2.0);
  push_pair(vm);
  push_digit(vm, 3.0);
  push_digit(vm, 4.0);
  push_pair(vm);
  push_pair(vm);

  gc(vm);
  destroy_vm(vm);

  puts("Finishing 'vm_reach_nested_objects' test.");
}

void vm_tests() {
  vm_init_and_destroy_test();
  vm_push_digits_test();
  vm_collect_unreached_objects();
  vm_reach_nested_objects();
}