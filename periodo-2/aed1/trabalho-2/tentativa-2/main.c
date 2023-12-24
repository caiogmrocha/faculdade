#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/linkedlist.h"

int main() {
    struct LinkedListNode *list = NULL;

    addLast(&list, 1);
    addLast(&list, 2);
    addLast(&list, 3);
    addLast(&list, 4);
    addLast(&list, 5);
    addLast(&list, 6);
    removeLast(&list);
    removeLast(&list);
    removeLast(&list);

    struct LinkedListNode *iterator = list;

    while (iterator != NULL) {
        printf("%d\n", iterator->value);
        iterator = iterator->next;
    }

    return 0;
}