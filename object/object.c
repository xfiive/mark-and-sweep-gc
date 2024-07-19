#include "object.h"
#include <limits.h>

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
    if (object->head != NULL)
      free(object->head);
    if (object->tail != NULL)
      free(object->tail);
  }

  free(object);

  return true;
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