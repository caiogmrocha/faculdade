#include <stdio.h>

#include "modules/avl.h"

int main() {
    printf("Hello World!\n");

    avl *tree = NULL;

    avlInsert(&tree, 30, 0);
    avlInsert(&tree, 20, 0);
    avlInsert(&tree, 35, 0);
    avlInsert(&tree, 33, 0);
    avlInsert(&tree, 36, 0);
    avlInsert(&tree, 37, 0);

    printf("Value: %i\n", tree->value);

    return 0;
}