#include <stdlib.h>

#include "avl.h"

avl *avlFactory(int value) {
    avl *tree = (avl *) malloc(sizeof(avl));

    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}


void avlInsert(avl **tree, int value) {
    if (*tree == NULL) {
        *tree = avlFactory(value);
    } else if (value < (*tree)->value) {
        avlInsert(&(*tree)->left, value);
    } else {
        avlInsert(&(*tree)->right, value);
    }
}