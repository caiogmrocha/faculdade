#include <stdlib.h>
#include <stdbool.h>
#include "rbt.h"

bool rbtIsLeftChild(rbt *tree) {
    if (tree == NULL) {
        return false;
    } else if (tree->parent == NULL) {
        return false;
    } else if (tree->parent->left == tree) {
        return true;
    } else {
        return false;
    }
}

bool rbtIsRightChild(rbt *tree) {
    return !rbtIsLeftChild(tree);
}

rbt* rbtGetUncle(rbt **tree) {
    if (tree == NULL || *tree == NULL || (*tree)->parent == NULL || (*tree)->parent->parent == NULL) {
        return NULL;
    }

    if (rbtIsLeftChild((*tree)->parent)) {
        return (*tree)->parent->parent->right; 
    } else {
        return (*tree)->parent->parent->left;
    }
}

void rbtRepaint(rbt **tree) {
    if (*tree == NULL) {
        return;
    }

    if ((*tree)->parent == NULL) {
        (*tree)->color = BLACK;

        return;
    }
    
    (*tree)->parent->color = BLACK;

    rbt *uncle = rbtGetUncle(tree);
    
    if (uncle != NULL) {
        uncle->color = BLACK;
    }
    
    rbtRepaint(&(*tree)->parent);
}

void rbtInsertBalance(rbt **tree, rbt **root) {
    if (*tree == NULL) {
        return;
    }

    if ((*tree)->parent == NULL || (*tree)->parent->color == BLACK) {
        return;
    }

    rbt *uncle = rbtGetUncle(tree);

    if (uncle == NULL || uncle->color == BLACK) {
        rbt *a = (*tree)->parent->parent;
        rbt *b = (*tree)->parent;
        rbt *c = (*tree);

        if (rbtIsLeftChild((*tree)->parent) && rbtIsLeftChild(*tree)) {
            // right rotation
            b->right = a;
            b->parent = a->parent;
            b->color = BLACK;

            if (a->parent != NULL) {
                if (rbtIsLeftChild(a)) {
                    a->parent->left = b;
                } else {
                    a->parent->right = b;
                }
            } else {
                *root = b;
            }

            a->left = NULL;
            a->parent = b;
            a->color = RED;
        } else if (rbtIsLeftChild((*tree)->parent) && rbtIsRightChild(*tree)) {
            // left rotation            
            // c->left = b;
            // c->parent = a;

            // b->right = NULL;
            // b->parent = c;

            // a->left = c;

            // // right rotation
            // c->right = a;
            // c->parent = NULL;
            // c->color = BLACK;

            // a->left = NULL;
            // a->parent = b;
            // a->color = RED;

            // a = c;

            // (*tree)->parent->parent = b;
        } else if (rbtIsRightChild((*tree)->parent) && rbtIsLeftChild(*tree)) {
            // right rotation            
            // (*c)->right = *b;
            // (*c)->parent = *a;
            // *b = *c;

            // // left rotation
            // (*b)->left = *a;
            // (*b)->parent = NULL;
            // (*b)->color = BLACK;

            // (*a)->right = NULL;
            // (*a)->parent = *b;
            // (*a)->color = RED;
        } else {
            b->left = a;
            b->parent = a->parent;
            b->color = BLACK;

            if (a->parent != NULL) {
                if (rbtIsLeftChild(a)) {
                    a->parent->left = b;
                } else {
                    a->parent->right = b;
                }
            } else {
                *root = b;
            }

            a->right = NULL;
            a->parent = b;
            a->color = RED;
        }
    } else {
        rbtRepaint(tree);
    }
}

void rbtInsert(rbt **tree, int value, rbt **parent, rbt **root) {
    if (*tree == NULL) {
        *tree = (rbt *) malloc(sizeof(rbt));

        (*tree)->value = value;
        (*tree)->parent = parent == NULL ? NULL : *parent;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->color = parent == NULL ? BLACK : RED;
        
        rbtInsertBalance(tree, root);
    } else if (value < (*tree)->value) {
        rbtInsert(&(*tree)->left, value, tree, root == NULL ? tree : root);
    } else {
        rbtInsert(&(*tree)->right, value, tree, root == NULL ? tree : root);
    }
}