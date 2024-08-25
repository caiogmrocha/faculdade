#include <stdio.h>

#include "modules/avl.h"

int main() {
    printf("Hello World!\n");

    avl *tree = NULL;
    short grew = 0;
    short shrank = 0;

    avlInsert(&tree, 30, &grew);
    avlInsert(&tree, 20, &grew);
    avlInsert(&tree, 35, &grew);
    avlInsert(&tree, 33, &grew);
    avlInsert(&tree, 36, &grew);
    avlInsert(&tree, 15, &grew);
    avlInsert(&tree, 37, &grew);

    avlRemove(&tree, 30, &shrank);

    printf("Value: %i\n", tree->value);

    return 0;
}