#include <stdlib.h>

#include "linked-list.h"

ll *llFactory(int value) {
    ll *node = (ll *) malloc(sizeof(ll));

    node->next = NULL;
    node->value = value;

    return node;
}

void llInsert(ll **list, int value) {
    ll *temp = *list;

    *list = llFactory(value);

    (*list)->next = temp;
}