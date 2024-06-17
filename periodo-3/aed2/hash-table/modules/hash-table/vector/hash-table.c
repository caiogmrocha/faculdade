#include <stdio.h>

#include "hash-table.h"

void htvBootstrap(htv table) {
    for (int i = 0; i < HTV_TABLE_LENGTH; i++) {
        table[i] = HTV_NULL_VALUE;
    }
}

int htvHash(int key) {
    return key % HTV_TABLE_LENGTH;
}

void htvInsert(htv table, int value) {
    int idx = htvHash(value);

    while (table[idx] != HTV_NULL_VALUE) {
        idx = htvHash(idx + 1);
    }

    table[idx] = value;
}

void htvRemove(htv table, int value) {
    int idx = htvHash(value);

    while (table[idx] != value && table[idx] != HTV_NULL_VALUE) {
        idx = htvHash(idx + 1);
    }

    if (table[idx] == value) {
        table[idx] = 0;

        // printf("Elemento %i encontrado no índice %i\n", table[idx], idx);
    } else {
        printf("Elemento %i não encontrado no índice %i\n", value, idx);
    }
}

void htvTraversal(htv table, void cb(int value)) {
    for (int i = 0; i < HTV_TABLE_LENGTH; i++) {
        cb(table[i]);
    }
}