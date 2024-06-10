#include <stdlib.h>
#include <stdio.h>
#include "modules/rbt/rbt.h"

int main () {
    rbt *tree = NULL;

    rbtInsert(&tree, 25, NULL, NULL);
    rbtInsert(&tree, 30, NULL, NULL);
    rbtInsert(&tree, 20, NULL, NULL);
    rbtInsert(&tree, 15, NULL, NULL);
    rbtInsert(&tree, 10, NULL, NULL);

    // rbtRemove(&tree, 40, NULL);

    return 0;
}