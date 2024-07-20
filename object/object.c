#include "object.h"

Object *init_object(object_type type) {
  Object *object = calloc(1, sizeof(Object));

  object->is_marked = false;
  object->next = NULL;
  object->type = type;
  if (type == DIGIT)
    object->value = INT_MIN;
  else {
    object->head = NULL;
    object->tail = NULL;
  }

  return object;
}

bool destroy_object(Object *object) {
  if (object == NULL)
    return false;

  if (object->type == OBJECT) {
    if (object->head != NULL) {
      destroy_object(object->head);
    }
    if (object->tail != NULL) {
      destroy_object(object->tail);
    }
  }

  free(object);

  return true;
}

bool destroy_object_recursive(Object *object) {
  if (object == NULL)
    return false;

  destroy_object_recursive(object->next);

  destroy_object(object);

  return true;
}

void add_object(Object *first, Object *new_object) {
  if (first == NULL)
    return;

  Object *current = first;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_object;
}

void print_object(Object *object) {
  if (object == NULL)
    return;

  if (object->type == DIGIT)
    printf("\nObject value: %f", object->value);
  else {
    printf("(");
    print_object(object->head);
    printf(", ");
    print_object(object->tail);
    printf(")");
  }
}

void mark_object(Object *object) {
  if (object == NULL)
    return;

  if (object->is_marked == true)
    return;

  if (object->type == OBJECT) {
    mark_object(object->head);
    mark_object(object->tail);
  }
}