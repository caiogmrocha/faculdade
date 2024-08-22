#include <stdlib.h>

#include "avl.h"

avl *avlFactory(int value) {
    avl *tree = (avl *) malloc(sizeof(avl));

    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}


void avlInsert(avl **tree, int value) {
    if (*tree == NULL) {
        *tree = avlFactory(value);
    } else if (value < (*tree)->value) {
        avlInsert(&(*tree)->left, value);
    } else {
        avlInsert(&(*tree)->right, value);
    }
}

void avlRemove(avl **tree, int value) {
    if (*tree == NULL) {
        return;
    } else if (value == (*tree)->value) {
        if ((*tree)->left == NULL && (*tree)->right == NULL) {
            free(*tree);

            *tree = NULL;
        } else if ((*tree)->left != NULL && (*tree)->right == NULL) {
            avl *temp = *tree;

            *tree = (*tree)->left;

            (*tree)->left = NULL;

            free(temp);
        } else if ((*tree)->left == NULL && (*tree)->right != NULL) {
            avl *temp = *tree;

            *tree = (*tree)->right;

            (*tree)->right = NULL;

            free(temp);
        } else {
            avl *leftmost = (*tree)->left;

            while (leftmost->right != NULL) {
                leftmost = leftmost->right;
            }

            (*tree)->value = leftmost->value;

            avlRemove(&(*tree)->left, leftmost->value);
        }
    } else if (value < (*tree)->value) {
        avlRemove(&(*tree)->left, value);
    } else {
        avlRemove(&(*tree)->right, value);
    }
}