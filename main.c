#include <stdio.h>
#include <stdlib.h>

#include "object/object.h"
#include "stack/stack.h"
#include "tests/object-tests/object-test.h"
#include "tests/stack-tests/stack-test.h"
#include "tests/vm-tests/vm-test.h"
#include "vm/vm.h"

#define ENDLINE printf("\n");

void tests() {
  object_tests();
  stack_tests();
  vm_tests();
}

int main(int argc, const char **argv) {
  tests();

  ENDLINE;
}
