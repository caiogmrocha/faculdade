#include <stdlib.h>
#include "rb-tree.h"

void rbtInsert(rbtree **tree, int value, rbtree *parent) {
    if (*tree == NULL) {
        *tree = (rbtree *) malloc(sizeof(rbtree));

        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->value = value;

        if (parent == NULL) {
            (*tree)->parent = NULL;
            (*tree)->color = BLACK;
        } else {
            (*tree)->parent = parent;
            (*tree)->color = RED;
        }
    }
}

void rbtRotateRight(rbtree **node) {
    if (*node == NULL) {
        return;
    }

    rbtree *a = *node;
    rbtree *b = a->left;
    rbtree *c = b->right;

    b->right = a;
    a->left = c;
    
    *node = b;
}

void rbtRotateLeft(rbtree **node) {
    if (*node == NULL) {
        return;
    }

    rbtree *a = *node;
    rbtree *b = a->right;
    rbtree *c = b->left;

    b->left = a;
    a->right = c;
    
    *node = b;
}