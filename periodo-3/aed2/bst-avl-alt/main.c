#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main(int argc, char **argv) {
    avl *tree = NULL;

    tree = avlInsert(tree, 10);
    tree = avlInsert(tree, 5);
    tree = avlInsert(tree, 15);
    tree = avlInsert(tree, 17);
    tree = avlInsert(tree, 9);

    printf("tree->value == %i\n", tree->value);

    return 0;
}