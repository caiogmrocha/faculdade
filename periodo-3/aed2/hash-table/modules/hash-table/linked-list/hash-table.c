#include <stdlib.h>

#include "linked-list.h"
#include "hash-table.h"

void htllBootstrap(htll table) {
    for (int i = 0; i < HTLL_TABLE_LENGTH; i++) {
        table[i] = NULL; 
    }
}

int htllHash(int key) {
    return key % HTLL_TABLE_LENGTH;
}

void htllInsert(htll table, int value) {
    int idx = htllHash(value);

    while (table[idx] != HTLL_NULL_VALUE) {
        idx = htllHash(idx + 1);
    }

    llInsert(&table[idx], value);
}

void htllFree(htll table) {
    for (int i = 0; i < HTLL_TABLE_LENGTH; i++) {
        ll *iterator = table[i];

        if (iterator != NULL) {
            while (iterator->next != NULL) {
                ll *cur = iterator;

                iterator = iterator->next;

                free(cur);
            }
        }
    }
}