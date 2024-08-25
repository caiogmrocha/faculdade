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

