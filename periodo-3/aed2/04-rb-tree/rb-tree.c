#include "rb-tree.h"

void rbtRotateRight(rbtree **node) {
    rbtree *parent = (*node)->parent;
    rbtree *grand = parent->parent;

    parent->color = BLACK;
    grand->color = RED;

    (*node)->right = parent->right;
    parent->right = grand;
}