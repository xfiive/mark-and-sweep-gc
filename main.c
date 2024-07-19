#include <stdlib.h>
#include <stdio.h>

#include "stack/stack.h"
#include "object/object.h"

int main(int argc, const char **argv) {

    Object *object = init_object(OBJECT);

    if (object != NULL)
        printf("\nObject is okay");
    else
        printf("\nObject is not okay");

    printf("\nResult of object destroying: %d\n", destroy_object(object));
}
