#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "rbt.h"

rbt *DB_NULL;

void rbtBootstrap() {
    DB_NULL = (rbt *) malloc(sizeof(rbt));

    DB_NULL->parent = NULL;
    DB_NULL->left = NULL;
    DB_NULL->right = NULL;
    DB_NULL->value = -1;
    DB_NULL->color = DOUBLE_BLACK;
}

void rbtFreeNode(rbt **tree) {
    if (*tree != NULL) {
        free(*tree);
        *tree = NULL;
    }
}

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
    if (*tree != NULL) {
        rbt *d = *tree;
        rbt *b = d->right;

        d->right = b->left;

        if (d->right != NULL) {
            d->right->parent = d;
        }

        b->left = d;
        b->parent = d->parent;

        if (b->parent != NULL) {
            if (rbtIsLeftChild(d)) {
                b->parent->left = b;
            } else {
                b->parent->right = b;
            }
        } else {
            *root = b;
        }

        d->parent = b;
    }
}

void rbtRotateRight(rbt **tree, rbt **root) {
    if (*tree != NULL) {
        rbt *d = *tree;
        rbt *b = d->left;

        d->left = b->right;

        if (d->left != NULL) {
            d->left->parent = d;
        }

        b->right = d;
        b->parent = d->parent;

        if (b->parent != NULL) {
            if (rbtIsLeftChild(d)) {
                b->parent->left = b;
            } else {
                b->parent->right = b;
            }
        } else {
            *root = b;
        }

        d->parent = b;
    }
}

void rbtInsertFixup(rbt **tree, rbt **root) {
    if (*tree == NULL || (*tree)->parent == NULL || (*tree)->parent->color == BLACK) {
        return;
    }
    
    rbt *uncle = rbtGetUncle(tree);

    if (uncle == NULL || uncle->color == BLACK) {
        if (rbtIsLeftChild((*tree)->parent) && rbtIsLeftChild(*tree)) {
            rbtRotateRight(&(*tree)->parent->parent, root);

            (*tree)->parent->color = BLACK;
            (*tree)->parent->right->color = RED;
        } else if (rbtIsLeftChild((*tree)->parent) && rbtIsRightChild(*tree)) {
            rbt *parent = (*tree)->parent;
            rbt *grandparent = (*tree)->parent->parent;
            
            rbtRotateLeft(&parent, root);
            rbtRotateRight(&grandparent, root);

            grandparent->color = RED;
            grandparent->parent->color = BLACK;
        } else if (rbtIsRightChild((*tree)->parent) && rbtIsLeftChild(*tree)) {
            rbt *parent = (*tree)->parent;
            rbt *grandparent = (*tree)->parent->parent;
            
            rbtRotateRight(&parent, root);
            rbtRotateLeft(&grandparent, root);

            grandparent->color = RED;
            grandparent->parent->color = BLACK;
        } else {
            rbtRotateLeft(&(*tree)->parent->parent, root);

            (*tree)->parent->color = BLACK;
            (*tree)->parent->left->color = RED;
        }
    } else {
        rbtRepaint(tree);
    }
}

void rbtInsertDef(rbt **tree, int value, rbt **parent, rbt **root) {
    if (*tree == NULL) {
        *tree = (rbt *) malloc(sizeof(rbt));

        (*tree)->value = value;
        (*tree)->parent = parent == NULL ? NULL : *parent;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->color = parent == NULL ? BLACK : RED;
        
        rbtInsertFixup(tree, root);
    } else if (value < (*tree)->value) {
        rbtInsertDef(&(*tree)->left, value, tree, root == NULL ? tree : root);
    } else {
        rbtInsertDef(&(*tree)->right, value, tree, root == NULL ? tree : root);
    }
}

void rbtInsert(rbt **tree, int value) {
    rbtInsertDef(tree, value, NULL, NULL);
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

bool rbtRemoveFixupSecondCaseCheck(rbt *tree) {
    bool parentIsBlack = tree->parent != NULL && tree->parent->color == BLACK;

    return (
        tree->parent != NULL &&
        tree->parent->color == BLACK &&

        rbtIsLeftChild(tree) &&
        tree->parent->right != NULL &&
        tree->parent->right->color == RED &&

        (tree->parent->right->left == NULL || tree->parent->right->left->color == BLACK) &&
        (tree->parent->right->right == NULL || tree->parent->right->right->color == BLACK)
    );
}

bool rbtRemoveFixupSecondMirrorImageCaseCheck(rbt *tree) {
    bool parentIsBlack = tree->parent != NULL && tree->parent->color == BLACK;

    return (
        tree->parent != NULL &&
        tree->parent->color == BLACK &&

        rbtIsRightChild(tree) &&
        tree->parent->left != NULL &&
        tree->parent->left->color == RED &&

        (tree->parent->left->left == NULL || tree->parent->left->left->color == BLACK) &&
        (tree->parent->left->right == NULL || tree->parent->left->right->color == BLACK)
    );
}

bool rbtRemoveFixupThirdCaseCheck(rbt *tree) {
    bool parentIsBlack = tree->parent != NULL && tree->parent->color == BLACK;

    return (
        tree->parent != NULL &&
        tree->parent->color == BLACK &&

        rbtIsLeftChild(tree) &&
        tree->parent->right != NULL &&
        tree->parent->right->color == BLACK &&

        (tree->parent->right->left == NULL || tree->parent->right->left->color == BLACK) &&
        (tree->parent->right->right == NULL || tree->parent->right->right->color == BLACK)
    );
}

bool rbtRemoveFixupThirdMirrorImageCaseCheck(rbt *tree) {
    bool parentIsBlack = tree->parent != NULL && tree->parent->color == BLACK;

    return (
        tree->parent != NULL &&
        tree->parent->color == BLACK &&

        rbtIsRightChild(tree) &&
        tree->parent->left != NULL &&
        tree->parent->left->color == BLACK &&

        (tree->parent->left->left == NULL || tree->parent->left->left->color == BLACK) &&
        (tree->parent->left->right == NULL || tree->parent->left->right->color == BLACK)
    );
}

void rbtRemoveFixup(rbt **tree, rbt **root) {
    if (*tree == NULL) {
        return;
    }

    rbt *node = *tree;

    if ((*tree)->parent == NULL) { // case 1
        if (*tree == DB_NULL) {
            *tree == NULL;
        } else {
            (*tree)->color = BLACK;
        }
    } else if (rbtRemoveFixupSecondCaseCheck(node)) {
        rbtRotateLeft(&node->parent, root);
        node->parent->color = RED;
        node->parent->parent->color = BLACK;

        rbtRemoveFixup(tree, root);
    } else if (rbtRemoveFixupSecondMirrorImageCaseCheck(node)) {
        rbtRotateRight(&node->parent, root);
        node->parent->color = RED;
        node->parent->parent->color = BLACK;

        rbtRemoveFixup(tree, root);
    } else if (rbtRemoveFixupThirdCaseCheck(node)) {
        node->parent->color = DOUBLE_BLACK;
        node->parent->right->color = RED;

        if (node == DB_NULL) {
            node = NULL;
        } else {
            node->color = BLACK;
        }

        rbtRemoveFixup(&node->parent, root);
    } else if (rbtRemoveFixupThirdMirrorImageCaseCheck(node)) {
        node->parent->color = DOUBLE_BLACK;
        node->parent->left->color = RED;
        
        if (node == DB_NULL) {
            node = NULL;
        } else {
            node->color = BLACK;
        }

        rbtRemoveFixup(&node->parent, root);
    } else {
        fprintf(stderr, "Caso não implementado para o rbtRemoveFixup()\n");
        exit(1);
    }
}

void rbtRemoveDef(rbt **tree, int value, rbt **root) {
    if (*tree == NULL) {
        return;
    }

    if (value == (*tree)->value) {
        if ((*tree)->left != NULL && (*tree)->right != NULL) {
            rbt *rightMostNodeFromLeftSubTree = rbtGetRightMostNode(&(*tree)->left);

            (*tree)->value = rightMostNodeFromLeftSubTree->value;

            rbtRemoveDef(&(*tree)->left, rightMostNodeFromLeftSubTree->value, root);
        } else if ((*tree)->left != NULL && (*tree)->right == NULL) {
            rbt *temp = *tree;

            (*tree)->left->parent = (*tree)->parent;
            *tree = (*tree)->left;
            (*tree)->color = BLACK;

            free(temp);
        } else if ((*tree)->left == NULL && (*tree)->right != NULL) {
            rbt *temp = *tree;

            (*tree)->right->parent = (*tree)->parent;
            *tree = (*tree)->right;
            (*tree)->color = BLACK;

            free(temp);
        } else if ((*tree)->color == RED) {
            rbt *temp = (*tree);

            *tree = NULL;

            free(temp);
        } else {
            rbt *temp = *tree;

            DB_NULL->parent = (*tree)->parent;

            if (rbtIsLeftChild(*tree)) {
                DB_NULL->parent->left = DB_NULL;
            } else {
                DB_NULL->parent->right = DB_NULL;
            }

            *tree = DB_NULL;

            rbtRemoveFixup(tree, root);

            free(temp);
        }
    } else if (value < (*tree)->value) {
        rbtRemoveDef(&(*tree)->left, value, root);
    } else {
        rbtRemoveDef(&(*tree)->right, value, root);
    }
}

void rbtRemove(rbt **tree, int value) {
    rbtRemoveDef(tree, value, tree);
}

void rbtPreOrderTraversal(rbt **tree, void cb(rbt **tree)) {
    if (*tree != NULL) {
        cb(tree);
        rbtPreOrderTraversal(&(*tree)->left, cb);
        rbtPreOrderTraversal(&(*tree)->right, cb);
    }
}

void rbtInOrderTraversal(rbt **tree, void cb(rbt **tree)) {
    if (*tree != NULL) {
        rbtInOrderTraversal(&(*tree)->left, cb);
        cb(tree);
        rbtInOrderTraversal(&(*tree)->right, cb);
    }
}

void rbtPostOrderTraversal(rbt **tree, void cb(rbt **tree)) {
    if (*tree != NULL) {
        rbtPostOrderTraversal(&(*tree)->left, cb);
        rbtPostOrderTraversal(&(*tree)->right, cb);
        cb(tree);
    }
}