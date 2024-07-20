#include "object-test.h"

void object_init_and_destroy_test() {
  puts("Starting 'object_init_and_destroy_test' test.");

  Object *object = init_object(OBJECT);

  if (object != NULL)
    printf("\nObject is okay");
  else
    printf("\nObject is not okay");

  printf("\nResult of object destroying: %d\n", destroy_object(object));

  puts("Finishing 'object_init_and_destroy_test' test.");
}

void object_add_and_free() {
  puts("Starting 'object_add_and_free' test.");

  Object *object = init_object(OBJECT);
  add_object(object, init_object(OBJECT));
  add_object(object, init_object(OBJECT));

  destroy_object_recursive(object);

  puts("Finishing 'object_add_and_free' test.");
}

void object_tests() {
  object_init_and_destroy_test();
  object_add_and_free();
}