#ifndef AVL_H
#define AVL_H

typedef struct avl {
    int value, fb;
    struct avl *left, *right;
} avl;

avl *avlInsert(avl *tree, int value);
avl *avlRemove(avl *tree, int value);

avl *avlPreOrderTraversal(avl *tree, void cb(avl *tree));
avl *avlInOrderTraversal(avl *tree, void cb(avl *tree));
avl *avlPostOrderTraversal(avl *tree, void cb(avl *tree));

#endif