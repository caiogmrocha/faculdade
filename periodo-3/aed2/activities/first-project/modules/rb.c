#include <stdlib.h>

#include "rb.h"

rb *rbFactory(int value, rb *parent) {
    rb *tree = (rb *) malloc(sizeof(rb));
    
    tree->value = value;
    tree->color = RED;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = parent;

    return tree;
}

void rbInsert(rb **tree, int value, rb *parent) {
    if (*tree == NULL) {
        *tree = rbFactory(value, parent);
    } else if (value < (*tree)->value) {
        rbInsert(&(*tree)->left, value, *tree);
    } else {
        rbInsert(&(*tree)->right, value, *tree);
    }
}