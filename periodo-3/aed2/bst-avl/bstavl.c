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

    (*dest)->height = bstHeight(*dest);

    bstBalance(dest);
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

    if (*tree != NULL) {
        (*tree)->height = bstHeight(*tree);
    }

    bstBalance(tree);
}

void bstRotateLeft(bst **tree) {
    if (*tree == NULL) {
        return;
    } else {
        bst *a = *tree;
        bst *b = a->right;
        bst *c = b->left;

        b->left = a;
        a->right = c;
        *tree = b;
    }
}

void bstRotateRight(bst **tree) {
    if (*tree == NULL) {
        return;
    } else {
        bst *a = *tree;
        bst *b = a->left;
        bst *c = b->right;

        b->right = a;
        a->left = c;
        *tree = b;
    }
}

void bstRotateRightLeft(bst **tree) {
    bstRotateRight(&(*tree)->right);
    bstRotateLeft(tree);
}

void bstRotateLeftRight(bst **tree) {
    bstRotateLeft(&(*tree)->left);
    bstRotateRight(tree);
}

int bstHeight(bst *tree) {
    if (tree == NULL) {
        return -1;
    } else if (tree->left == NULL && tree->right == NULL) {
        return 0;
    } else {
        int leftHeight = bstHeight(tree->left);
        int rightHeight = bstHeight(tree->right);

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

int bstBalanceFactor(bst **tree) {
    if (*tree == NULL || ((*tree)->left == NULL && (*tree)->right == NULL)) {
        return 0;
    } else if ((*tree)->left == NULL && (*tree)->right != NULL) {
        return 0 - (*tree)->right->height;
    } else if ((*tree)->left != NULL && (*tree)->right == NULL) {
        return (*tree)->left->height - 0;
    } else {
        return (*tree)->left->height - (*tree)->right->height;
    }
}

bst **bstSearch(bst **tree, int value) {
    if (*tree == NULL) {
        return NULL;
    } else if (value == (*tree)->value) {
        return tree;
    } else if (value > (*tree)->value) {
        return bstSearch(&(*tree)->right, value);
    } else {
        return bstSearch(&(*tree)->left, value);
    }
}

void bstBalance(bst **tree) {
    if (*tree == NULL) {
        return;
    }

    int balanceFactor = bstBalanceFactor(tree);

    if (balanceFactor <= -1 && bstBalanceFactor(&(*tree)->right) >= 1) {
        bstRotateRightLeft(tree);
    } else if (balanceFactor >= 1 && bstBalanceFactor(&(*tree)->left) <= -1) {
        bstRotateLeftRight(tree);
    } else if (balanceFactor <= -1) {
        bstRotateLeft(tree);
    } else if (balanceFactor >= 1) {
        bstRotateRight(tree);
    }
}