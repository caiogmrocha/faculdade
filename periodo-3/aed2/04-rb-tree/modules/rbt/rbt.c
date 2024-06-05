#include <stdlib.h>
#include <stdio.h>
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

    if ((*tree)->parent->parent != NULL) {
        (*tree)->parent->parent->color = RED;
    }
    
    (*tree)->parent->color = BLACK;

    rbt *uncle = rbtGetUncle(tree);
    
    if (uncle != NULL) {
        uncle->color = BLACK;
    }
    
    rbtRepaint(&(*tree)->parent->parent);
}

void rbtRotateLeft(rbt **tree, rbt **root) {
    rbt *a = (*tree)->parent->parent;
    rbt *b = (*tree)->parent;
    rbt *c = (*tree);

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

    a->right = b->left;

    if (b->left != NULL) {
        b->left->parent = a;
    }

    a->right = NULL;
    a->parent = b;
    a->color = RED;
}

void rbtRotateRight(rbt **tree, rbt **root) {
    rbt *a = (*tree)->parent->parent;
    rbt *b = (*tree)->parent;
    rbt *c = (*tree);

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
}

void rbtRotateLeftRight(rbt **tree, rbt **root) {
    rbt *a = (*tree)->parent->parent;
    rbt *b = (*tree)->parent;
    rbt *c = (*tree);

    // left rotation
    c->left = b;
    c->parent = b->parent;
    b->parent = c;
    b->right = NULL;
    a->left = c;

    // right rotation
    c->right = a;
    c->parent = a->parent;
    c->color = BLACK;

    if (a->parent != NULL) {
        if (rbtIsLeftChild(a)) {
            a->parent->left = c;
        } else {
            a->parent->right = c;
        }
    } else {
        *root = c;
    }

    a->left = NULL;
    a->parent = c;
    a->color = RED;
}

void rbtRotateRightLeft(rbt **tree, rbt **root) {
    rbt *a = (*tree)->parent->parent;
    rbt *b = (*tree)->parent;
    rbt *c = (*tree);

    // left rotation
    c->right = b;
    c->parent = b->parent;
    b->parent = c;
    b->left = NULL;
    a->right = c;

    // right rotation
    c->left = a;
    c->parent = a->parent;
    c->color = BLACK;

    if (a->parent != NULL) {
        if (rbtIsLeftChild(a)) {
            a->parent->left = c;
        } else {
            a->parent->right = c;
        }
    } else {
        *root = c;
    }

    a->right = NULL;
    a->parent = c;
    a->color = RED;
}

void rbtInsertBalance(rbt **tree, rbt **root) {
    if (*tree == NULL || (*tree)->parent == NULL || (*tree)->parent->color == BLACK) {
        return;
    }
    
    rbt *uncle = rbtGetUncle(tree);

    if (uncle == NULL || uncle->color == BLACK) {
        if (rbtIsLeftChild((*tree)->parent) && rbtIsLeftChild(*tree)) {
            rbtRotateRight(tree, root);
        } else if (rbtIsLeftChild((*tree)->parent) && rbtIsRightChild(*tree)) {
            rbtRotateLeftRight(tree, root);
        } else if (rbtIsRightChild((*tree)->parent) && rbtIsLeftChild(*tree)) {
            rbtRotateRightLeft(tree, root);
        } else {
            rbtRotateLeft(tree, root);
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

rbt* rbtGetRightMostNode(rbt **tree) {
    if (*tree == NULL) {
        return NULL;
    }

    rbt *iterator = *tree;

    while (iterator->right != NULL) {
        iterator = iterator->right;
    }

    return iterator;
}

void rbtRemove(rbt **tree, int value, rbt **root) {
    if (*tree == NULL) {
        return;
    }

    if (value == (*tree)->value) {
        if ((*tree)->color == RED) {
            if ((*tree)->left == NULL && (*tree)->right == NULL) {
                rbt *temp = (*tree);

                *tree = NULL;

                free(temp);
            } else {
                rbt *rightMostNodeFromLeftSubTree = rbtGetRightMostNode(&(*tree)->left);

                (*tree)->value = rightMostNodeFromLeftSubTree->value;

                rbtRemove(&(*tree)->left, rightMostNodeFromLeftSubTree->value, root);
            }
        } else {
            printf("not implemented case");
        }
    } else if (value < (*tree)->value) {
        rbtRemove(&(*tree)->left, value, root);
    } else {
        rbtRemove(&(*tree)->right, value, root);
    }
}