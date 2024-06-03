#include <stdlib.h>
#include <stdio.h>
#include "modules/rbt/rbt.h"

int main () {
    rbt *tree = NULL;

    rbtInsert(&tree, 20, NULL);
    rbtInsert(&tree, 10, NULL);
    rbtInsert(&tree, 30, NULL);
    rbtInsert(&tree, 15, NULL);

    return 0;
}