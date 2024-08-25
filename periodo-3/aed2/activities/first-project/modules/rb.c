#include <stdlib.h>

#include "rb.h"

rb *rbFactory(int value, rb *parent) {
    rb *tree = (rb *) malloc(sizeof(rb));
    
    tree->value = value;
    tree->color = RED;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = parent;

    return tree;
}

void rbInsert(rb **tree, int value, rb *parent) {
    if (*tree == NULL) {
        *tree = rbFactory(value, parent);
    } else if (value < (*tree)->value) {
        rbInsert(&(*tree)->left, value, *tree);
    } else {
        rbInsert(&(*tree)->right, value, *tree);
    }
}

void rbRemove(rb **tree, int value) {
    if (*tree == NULL) {
        return;
    } else if (value == (*tree)->value) {
        if ((*tree)->left == NULL && (*tree)->right == NULL) {
            free(*tree);

            *tree == NULL;
        } else if ((*tree)->left != NULL && (*tree)->right == NULL) {
            rb *temp = *tree;

            *tree = (*tree)->left;

            (*tree)->left = NULL;

            free(temp);
        } else if ((*tree)->left == NULL && (*tree)->right != NULL) {
            rb *temp = *tree;

            *tree = (*tree)->right;

            (*tree)->right = NULL;

            free(temp);
        } else {
            rb *leftmost = (*tree)->left;

            while (leftmost->right != NULL) {
                leftmost = leftmost->right;
            }

            (*tree)->value = leftmost->value;

            avlRemove(&(*tree)->left, leftmost->value);
        }
    } else if (value < (*tree)->value) {
        rbRemove(&(*tree)->left, value);
    } else {
        rbRemove(&(*tree)->left, value);
    }
}