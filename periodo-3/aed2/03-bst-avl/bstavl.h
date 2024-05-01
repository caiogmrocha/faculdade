#ifndef BSTAVL_H
#define BSTAVL_H

typedef struct bst {
    int value, height;
    struct bst *left, *right;
} bst;

bst *bstFactory(int value);
void bstInsert(bst **dest, bst *source);
void bstPreOrder(bst *tree, void cb(bst *node));
void bstInOrder(bst *tree, void cb(bst *node));
void bstPostOrder(bst *tree, void cb(bst *node));
void bstRemove(bst **tree, int value);
void bstRotateLeft(bst **tree, int value);
void bstRotateRight(bst **tree, int value);
void bstRotateRightLeft(bst **tree, int value);
void bstRotateLeftRight(bst **tree, int value);
int bstHeight(bst *tree);
// int bstBalanceFactor(bst *tree);
// void bstBalance(bst **tree);

#endif