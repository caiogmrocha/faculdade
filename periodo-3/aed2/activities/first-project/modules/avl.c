#include <stdlib.h>

#include "avl.h"

avl *avlFactory(int value) {
    avl *tree = (avl *) malloc(sizeof(avl));

    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}
