#include <stdlib.h>
#include <stdio.h>
#include "modules/rbt/rbt.h"

int main () {
    rbtBootstrap();

    rbt *tree = NULL;

    rbtInsert(&tree, 25);
    // rbtInsert(&tree, 30);
    // rbtInsert(&tree, 20);
    // rbtInsert(&tree, 15);
    // rbtInsert(&tree, 17);
    // rbtInsert(&tree, 35);
    // rbtInsert(&tree, 32);

    rbtRemove(&tree, 25, NULL);

    rbtPostOrderTraversal(&tree, rbtFreeNode);

    return 0;
}