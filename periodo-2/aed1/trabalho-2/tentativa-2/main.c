#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/linkedlist.h"

int main() {
    struct LinkedListNode *list = NULL;

    addFirst(&list, 1);
    addFirst(&list, 2);
    addFirst(&list, 3);
    addFirst(&list, 4);
    addFirst(&list, 5);
    addFirst(&list, 6);

    struct LinkedListNode *iterator = list;

    while (iterator != NULL) {
        printf("%d\n", iterator->value);
        iterator = iterator->next;
    }

    return 0;
}