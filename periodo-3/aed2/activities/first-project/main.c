#include <stdio.h>

#include "modules/avl.h"

int main() {
    printf("Hello World!\n");

    avl *tree = NULL;
    short cresceu = 0;

    avlInsert(&tree, 30, &cresceu);
    avlInsert(&tree, 20, &cresceu);
    avlInsert(&tree, 35, &cresceu);
    avlInsert(&tree, 33, &cresceu);
    avlInsert(&tree, 36, &cresceu);
    avlInsert(&tree, 37, &cresceu);

    printf("Value: %i\n", tree->value);

    return 0;
}