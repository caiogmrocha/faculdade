#include <stdlib.h>
#include <stdio.h>
#include "modules/rbt/rbt.h"

int main () {
    rbt *tree = NULL;

    rbtInsert(&tree, 20, NULL, NULL);
    rbtInsert(&tree, 5, NULL, NULL);
    rbtInsert(&tree, 10, NULL, NULL);

    return 0;
}