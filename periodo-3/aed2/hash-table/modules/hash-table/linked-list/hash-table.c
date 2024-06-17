#include "hash-table.h"

void htllBootstrap(htll table) {
    for (int i = 0; i < HTLL_TABLE_LENGTH; i++) {
        table[i] = 0;
    }
}