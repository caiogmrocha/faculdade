#ifndef AVL_H
#define AVL_H

typedef struct avl {
    int value, fb;
    struct avl *left, *right;
} avl;

avl *avlInsert(avl *tree, int value);

#endif