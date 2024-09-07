#include <stdlib.h>

#include "avl.h"

avl *avlFactory(int value) {
    avl *tree = (avl *) malloc(sizeof(avl));

    tree->value = value;
    tree->bf = 0;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

int avlHeight(avl *tree) {
    if (tree == NULL) {
        return 0;
    } else {
        int leftHeight = avlHeight(tree->left);
        int rightHeight = avlHeight(tree->right);

        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

int avlBalanceFactor(avl *tree) {
    return avlHeight(tree->right) - avlHeight(tree->left);
}

void avlRotateLeft(avl **node) {
    if (*node == NULL) {
        return;
    }

    avl *p = *node;
    avl *u = p->right;

    p->right = u->left;
    u->left = p;

    *node = u;
}

void avlRotateRight(avl **node) {
    if (*node == NULL) {
        return;
    }

    avl *p = *node;
    avl *u = p->right;

    p->left = u->right;
    u->right = p;

    *node = u;
}

void avlRotateLeftRight(avl **node) {
    avlRotateLeft(&(*node)->left);
    avlRotateRight(node);
}

void avlRotateRightLeft(avl **node) {
    avlRotateRight(&(*node)->right);
    avlRotateRight(node);
}

void avlFixup(avl **node) {
    avl *p = *node;
    
    if (p->bf > 0) {
        avl *u = p->right;        

        if (u->bf >= 0) {
            if (u->bf == 1) {
                p->bf = 0;
                u->bf = 0;
            } else {
                p->bf = 1;
                u->bf = -1;
            }

            avlRotateLeft(node);
        } else {
            avl *v = u->left;

            if (v->bf == -1) {
                p->bf = 0;
                u->bf = 1;
                v->bf = 0;
            } else if (v->bf == 0) {
                p->bf = 0;
                u->bf = 0;
                v->bf = 0;
            } else if (v->bf == 1) {
                p->bf = -1;
                u->bf = 0;
                v->bf = 0;
            }

            avlRotateRightLeft(node);
        }
    } else {
        avl *u = p->left;        

        if (u->bf <= 0) {
            if (u->bf == -1) {
                p->bf = 0;
                u->bf = 0;
            } else {
                p->bf = 1;
                u->bf = -1;
            }

            avlRotateRight(node);
        } else {
            avl *v = u->right;

            if (v->bf == -1) {
                p->bf = 1;
                u->bf = 0;
                v->bf = 0;
            } else if (v->bf == 0) {
                p->bf = 0;
                u->bf = 0;
                v->bf = 0;
            } else if (v->bf == 1) {
                p->bf = 0;
                u->bf = -1;
                v->bf = 0;
            }

            avlRotateLeftRight(node);
        }
    }
}

void avlInsert(avl **tree, int value, short *grew) {
    if (*tree == NULL) {
        *tree = avlFactory(value);

        *grew = 1;
    } else if (value < (*tree)->value) {
        avlInsert(&(*tree)->left, value, grew);

        if (*grew) {
            if ((*tree)->bf == -1) {
                *grew = 0;
                avlFixup(tree);
            } else if ((*tree)->bf == 0) {
                (*tree)->bf =  -1;
                *grew = 1; // indica que a subárvore atual subiu para o a próxima chamada a ser desempilhada
            } else if ((*tree)->bf == 1) {
                (*tree)->bf = 0;
                *grew = 0;
            }
        }
    } else {
        avlInsert(&(*tree)->right, value, grew);

        if (*grew) {
            if ((*tree)->bf == -1) {
                (*tree)->bf = 0;
                *grew = 0;
            } else if ((*tree)->bf == 0) {
                (*tree)->bf = 1;
                *grew = 1; // indica que a subárvore atual subiu para o a próxima chamada a ser desempilhada
            } else if ((*tree)->bf == 1) {
                *grew = 0;
                avlFixup(tree);
            }
        }
    }
}

void avlRemove(avl **tree, int value, short *shrank) {
    if (*tree == NULL) {
        *shrank = 0;
        return;
    } else if (value == (*tree)->value) {
        *shrank = 1;

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

            avlRemove(&(*tree)->left, leftmost->value, shrank);

            if (*shrank) {
                if ((*tree)->bf == -1) {
                    *shrank = 1;
                    (*tree)->bf = 0;
                } else if ((*tree)->bf == 0) {
                    *shrank = 0;
                    (*tree)->bf = 1;
                } else if ((*tree)->bf == 1) {
                    avlFixup(tree);
                }
            }
        }
    } else if (value < (*tree)->value) {
        avlRemove(&(*tree)->left, value, shrank);

        if (*shrank) {
            if ((*tree)->bf == -1) {
                *shrank = 1;
                (*tree)->bf = 0;
            } else if ((*tree)->bf == 0) {
                *shrank = 0;
                (*tree)->bf = 1;
            } else if ((*tree)->bf == 1) {
                avlFixup(tree);
            }
        }
    } else {
        avlRemove(&(*tree)->right, value, shrank);

        if (*shrank) {
            if ((*tree)->bf == -1) {
                avlFixup(tree);
            } else if ((*tree)->bf == 0) {
                *shrank = 0;
                (*tree)->bf = -1;
            } else if ((*tree)->bf == 1) {
                *shrank = 1;
                (*tree)->bf = 0;
            }
        }
    }
}

void avlPreOrderTraversal(avl *tree, void (*cb)(avl *node)) {
    if (tree != NULL) {
        cb(tree);
        avlPreOrderTraversal(tree->left, cb);
        avlPreOrderTraversal(tree->right, cb);
    }
}

void avlPostOrderTraversal(avl *tree, void (*cb)(avl *node)) {
    if (tree != NULL) {
        avlPostOrderTraversal(tree->left, cb);
        avlPostOrderTraversal(tree->right, cb);
        cb(tree);
    }
}