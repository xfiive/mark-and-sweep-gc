#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H

#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    DIGIT,
    OBJECT
} object_type;

typedef struct stack_object {
    bool is_marked;

    object_type type;

    struct stack_object *next;

    union {
        double value;

        struct {
            struct stack_object *head;
            struct stack_object *tail;
        };
    };
} Object;

Object *init_object(object_type type);

bool destroy_object(Object *object);

void mark_object(Object *object);

#endif
