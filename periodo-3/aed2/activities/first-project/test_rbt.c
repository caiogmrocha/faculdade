#include <stdio.h>

#include "modules/rbt.h"

int main() {
    rbtBootstrap();

    rbt *tree = NULL;

    rbtInsert(&tree, 30);
    rbtInsert(&tree, 20);
    rbtInsert(&tree, 35);
    rbtInsert(&tree, 33);
    rbtInsert(&tree, 36);
    rbtInsert(&tree, 15);
    rbtInsert(&tree, 37);

    rbtRemove(&tree, 33);

    rbtPostOrderTraversal(&tree, rbtFreeNode);

    printf("Hello World!\n");

    return 0;
}