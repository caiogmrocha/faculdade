#ifndef BSTAVL_H
#define BSTAVL_H

typedef struct bst {
    int value, height;
    struct bst *left, *right;
} bst;

bst *bstFactory(int value);
void bstInsert(bst **dest, bst *source);
bst **bstSearch(bst **tree, int value);
void bstPreOrder(bst *tree, void cb(bst *node));
void bstInOrder(bst *tree, void cb(bst *node));
void bstPostOrder(bst *tree, void cb(bst *node));
void bstRemove(bst **tree, int value);
void bstRotateLeft(bst **tree);
void bstRotateRight(bst **tree);
void bstRotateRightLeft(bst **tree);
void bstRotateLeftRight(bst **tree);
int bstHeight(bst *tree);
int bstBalanceFactor(bst *left, bst *right);
// TODO: void bstBalance(bst **tree);

#endif