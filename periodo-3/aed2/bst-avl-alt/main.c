#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

void print(avl *tree) {
    printf("[%i]", tree->value);
}

int main(int argc, char **argv) {
    avl *tree = NULL;

    tree = avlInsert(tree, 10);
    tree = avlInsert(tree, 5);
    tree = avlInsert(tree, 15);
    tree = avlInsert(tree, 17);
    tree = avlInsert(tree, 9);

    avlPreOrderTraversal(tree, print);
    printf("\n");

    avlInOrderTraversal(tree, print);
    printf("\n");

    avlPostOrderTraversal(tree, print);
    printf("\n");

    printf("tree->value == %i\n", tree->value);

    return 0;
}