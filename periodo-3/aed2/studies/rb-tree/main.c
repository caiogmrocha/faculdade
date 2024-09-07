#include <stdlib.h>
#include <stdio.h>
#include "modules/rbt/rbt.h"

int main () {
    rbtBootstrap();

    rbt *tree = NULL;

    rbtInsert(&tree, 30);
    rbtInsert(&tree, 35);
    rbtInsert(&tree, 40);
    rbtInsert(&tree, 38);
    rbtInsert(&tree, 45);
    rbtInsert(&tree, 50);

    rbtRemove(&tree, 30);

    rbtPostOrderTraversal(&tree, rbtFreeNode);

    return 0;
}