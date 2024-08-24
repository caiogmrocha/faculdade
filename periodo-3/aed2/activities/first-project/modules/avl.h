#ifndef AVL_H
#define AVL_H

typedef struct avl {
    int value;
    struct avl *left, *right;
} avl;

avl *avlFactory(int value);

void avlRotateLeft(avl **node);

void avlInsert(avl **tree, int value);
void avlRemove(avl **tree, int value);

int avlBalanceFactor(avl *tree);
int avlHeight(avl *tree);

#endif