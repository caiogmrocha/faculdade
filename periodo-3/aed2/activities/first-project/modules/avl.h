#ifndef AVL_H
#define AVL_H

typedef struct avl {
    int value;
    struct avl *left, *right;
} avl;

avl *avlFactory(int value);
void avlInsert(avl **tree, int value);
void avlRemove(avl **tree, int value);

#endif