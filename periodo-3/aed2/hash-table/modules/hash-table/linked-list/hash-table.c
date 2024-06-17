#include <stdlib.h>
#include <stdio.h>

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

    int valueHasBeenFound = llSearch(table[idx], value);

    while (!valueHasBeenFound && table[idx] != NULL) {
        idx = htllHash(idx + 1);
    }

    if (valueHasBeenFound) {
        llRemove(&table[idx], value);

        // printf("Elemento %i encontrado no índice %i\n", value, idx);
    } else {
        // printf("Elemento %i não encontrado no índice %i\n", value, idx);
    }
}

int htllSearch(htll table, int value) {
    int idx = htllHash(value);

    int valueHasBeenFound = llSearch(table[idx], value);

    while (!valueHasBeenFound && table[idx] != NULL) {
        idx = htllHash(idx + 1);
    }

    if (valueHasBeenFound) {
        printf("Elemento %i encontrado no índice %i\n", value, idx);

        return valueHasBeenFound;
    } else {
        printf("Elemento %i não encontrado no índice %i\n", value, idx);

        return HTLL_NULL_VALUE;
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