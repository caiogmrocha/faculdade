#include <stdio.h>

#include "modules/avl.h"

int main() {
    printf("Hello World!\n");

    avl *tree = NULL;

    avlInsert(&tree, 30);
    avlInsert(&tree, 20);
    avlInsert(&tree, 35);
    avlInsert(&tree, 33);
    avlInsert(&tree, 36);

    avlRotateLeft(&tree);

    // avlRemove(&tree, 30);
    avlRemove(&tree, 30);

    printf("Value: %i\n", tree->value);

    return 0;
}