#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/stack.h"

int main() {
    struct LinkedListNode *stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    pop(&stack);
    pop(&stack);

    struct LinkedListNode *iterator = stack;

    while (iterator != NULL) {
        printf("%d\n", iterator->value);
        iterator = iterator->next;
    }

    return 0;
}