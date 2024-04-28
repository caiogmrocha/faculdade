#include <stdlib.h>
#include <stdio.h>
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
        } else if ((*tree)->left == NULL && (*tree)->right != NULL) {
            bst *temp = *tree;
            *tree = (*tree)->right;
            free(temp);
        } else {
            bst *leftMax = (*tree)->left;

            while (leftMax->right != NULL) {
                leftMax = leftMax->right;
            }

            (*tree)->value = leftMax->value;

            bstRemove(&(*tree)->left, leftMax->value);
        }
    } else if (value < (*tree)->value) {
        bstRemove(&(*tree)->left, value);
    } else if (value > (*tree)->value) {
        bstRemove(&(*tree)->right, value);
    }
}

bst *bstRotateLeft(bst **tree, int value) {
    if (*tree == NULL) {
        return NULL;
    } else if (value == (*tree)->value) {
        bst *a = *tree;
        bst *b = a->right;
        bst *c = b->left;

        b->left = a;
        a->right = c;
        *tree = b;

        return b;
    } else if (value < (*tree)->value) {
        return bstRotateLeft(&(*tree)->left, value);
    } else {
        return bstRotateLeft(&(*tree)->right, value);
    }
}