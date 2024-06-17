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

    while (table[idx] != NULL) {
        idx = htllHash(idx + 1);
    }

    llInsert(&table[idx], value);
}

void htllRemove(htll table, int value) {
    int idx = htllHash(value);

    while (!llSearch(table[idx], value) && table[idx] != NULL) {
        idx = htllHash(idx + 1);
    }

    if (llSearch(table[idx], value)) {
        llRemove(&table[idx], value);

        // printf("Elemento %i encontrado no índice %i\n", table[idx], idx);
    } else {
        // printf("Elemento %i não encontrado no índice %i\n", value, idx);
    }
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