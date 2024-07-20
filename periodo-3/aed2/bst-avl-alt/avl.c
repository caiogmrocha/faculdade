#include <stdlib.h>
#include "avl.h"

avl *avlFactory(int value) {
    avl *node = (avl *) malloc(sizeof(avl));

    node->left = NULL;
    node->right = NULL;
    node->value = value;
    node->fb = 0;

    return node;
}

avl *avlInsert(avl *tree, int value) {
    if (tree == NULL) {
        tree = avlFactory(value);
    } else if (value > tree->value) {
        tree->right = avlInsert(tree->right, value);
    } else {
        tree->left = avlInsert(tree->left, value);
    }

    return tree;
}

avl *avlPreOrderTraversal(avl *tree, void cb(avl *tree)) {
    if (tree != NULL) {
        cb(tree);
        avlPreOrderTraversal(tree->left, cb);
        avlPreOrderTraversal(tree->right, cb);
    }
}

avl *avlInOrderTraversal(avl *tree, void cb(avl *tree)) {
    if (tree != NULL) {
        avlInOrderTraversal(tree->left, cb);
        cb(tree);
        avlInOrderTraversal(tree->right, cb);
    }
}

avl *avlPostOrderTraversal(avl *tree, void cb(avl *tree)) {
    if (tree != NULL) {
        avlPostOrderTraversal(tree->left, cb);
        avlPostOrderTraversal(tree->right, cb);
        cb(tree);
    }
}