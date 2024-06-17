#include <stdio.h>
#include <stdlib.h>
// #include "modules/hash-table/vector/hash-table.h"
#include "modules/hash-table/linked-list/hash-table.h"

void printTableElement(int value) {
    printf("%i\n", value);
}

int main() {
    printf("Hello World!\n");

    htll table;

    htllBootstrap(table);

    htllInsert(table, 35);
    htllInsert(table, 65);
    htllInsert(table, 29);
    htllInsert(table, 62);
    htllInsert(table, 89);
    htllInsert(table, 23);
    htllInsert(table, 94);
    htllInsert(table, 18);
    htllInsert(table, 31);
    htllInsert(table, 75);
    htllInsert(table, 59);
    htllInsert(table, 6);
    htllInsert(table, 78);
    htllInsert(table, 99);
    htllInsert(table, 42);
    
    // htllTraversal(table, printTableElement);

    // htllSearch(table, 6);
    htllRemove(table, 6);
    // htllSearch(table, 6);

    // htllTraversal(table, printTableElement);

    // htllRemove(table, 24);

    htllFree(table);

    return 0;
}