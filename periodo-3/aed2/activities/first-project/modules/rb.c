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

int rbIsLeftChild(rb *node) {
    return node->parent->left == node;
}

int rbIsRoot(rb *node) {
    return node->parent == NULL;
}

rb *rbGetUncle(rb *node) {
    if (node != NULL && node->parent != NULL && node->parent->parent != NULL) {
        if (rbIsLeftChild(node->parent)) {
            return node->parent->parent->right;
        } else {
            return node->parent->parent->left;
        }
    }

    return NULL;
}

void rbInsertFixupRepaint(rb *tree) {
    if (rbIsRoot(tree)) {
        tree->color = BLACK;

        return;
    }

    if (tree->parent != NULL && tree->parent->parent != NULL) {
        tree->parent->parent->color = RED;
    }
    
    tree->parent->color = BLACK;

    rb *uncle = rbGetUncle(tree);
    
    if (uncle != NULL) {
        uncle->color = BLACK;
    }
    
    rbInsertFixupRepaint(tree->parent->parent);
}

void rbInsertFixup(rb **node) {
    rb *uncle = rbGetUncle(*node);

    if (uncle == NULL || uncle->color == BLACK) {
        
    } else {
        rbInsertFixupRepaint((*node)->parent->parent);
    }
}

void rbInsert(rb **tree, int value, rb *parent) {
    if (*tree == NULL) {
        *tree = rbFactory(value, parent);

        if ((*tree)->parent != NULL && (*tree)->parent->color == RED) {

        }
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