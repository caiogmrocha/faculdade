#include <stdio.h>
#include <stdlib.h>
#include "modules/hash-table/vector/hash-table.h"

void printTableElement(int value) {
    printf("%i\n", value);
}

int main() {
    printf("Hello World!\n");

    htv table;

    htvBootstrap(table);

    htvInsert(table, 35);
    htvInsert(table, 65);
    htvInsert(table, 29);
    htvInsert(table, 62);
    htvInsert(table, 89);
    htvInsert(table, 23);
    htvInsert(table, 94);
    htvInsert(table, 18);
    htvInsert(table, 31);
    htvInsert(table, 75);
    htvInsert(table, 59);
    htvInsert(table, 6);
    htvInsert(table, 78);
    htvInsert(table, 99);
    htvInsert(table, 42);
    
    htvTraversal(table, printTableElement);

    htvSearch(table, 6);
    htvRemove(table, 6);
    htvSearch(table, 6);

    htvTraversal(table, printTableElement);

    htvRemove(table, 24);

    return 0;
}