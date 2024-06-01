#include <stdlib.h>
#include <stdio.h>
#include "modules/rbt/rbt.h"

int main () {
    rbt *tree = NULL;

    rbtInsert(&tree, 10, NULL);
    rbtInsert(&tree, 5, NULL);
    rbtInsert(&tree, 15, NULL);

    return 0;
}