#include <stdlib.h>
#include "bstavl.h"

bst *bstFactory(int value) {
    bst *tree = (bst *) malloc(sizeof(bst));

    tree->left = NULL;
    tree->right = NULL;
    tree->value = value;

    return tree;
}

void bstInsert(bst **dest, bst *source) {
    if (*dest == NULL) {
        *dest = source;
    } else if (source->value < (*dest)->value) {
        bstInsert(&(*dest)->left, source);
    } else {
        bstInsert(&(*dest)->right, source);
    }
}

void bstPreOrder(bst *tree, void cb(bst *node)) {
    if (tree != NULL) {
        cb(tree);
        bstPreOrder(tree->left, cb);
        bstPreOrder(tree->right, cb);
    }
}

void bstInOrder(bst *tree, void cb(bst *node)) {
    if (tree != NULL) {
        bstInOrder(tree->left, cb);
        cb(tree);
        bstInOrder(tree->right, cb);
    }
}

void bstPostOrder(bst *tree, void cb(bst *node)) {
    if (tree != NULL) {
        bstPostOrder(tree->left, cb);
        bstPostOrder(tree->right, cb);
        cb(tree);
    }
}

void bstRemove(bst **tree, int value) {
    if (*tree == NULL) {
        return;
    } else if (value == (*tree)->value) {
        if ((*tree)->left == NULL && (*tree)->right == NULL) {
            bst *temp = *tree;
            *tree = NULL;
            free(temp);
        } else if ((*tree)->left != NULL && (*tree)->right == NULL) {
            bst *temp = *tree;
            *tree = (*tree)->left;
            free(temp);
        }
    } else if (value < (*tree)->value) {
        bstRemove(&(*tree)->left, value);
    } else if (value > (*tree)->value) {
        bstRemove(&(*tree)->right, value);
    }
}