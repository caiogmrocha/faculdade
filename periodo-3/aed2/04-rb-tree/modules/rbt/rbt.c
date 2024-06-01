#include "stdlib.h"
#include "rbt.h"

void rbtInsert(rbt **tree, int value, rbt **parent) {
    if (*tree == NULL) {
        *tree = (rbt *) malloc(sizeof(rbt));

        (*tree)->value = value;
        (*tree)->parent = parent == NULL ? NULL : *parent;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->color = RED;
    } else if (value < (*tree)->value) {
        rbtInsert(&(*tree)->left, value, tree);
    } else {
        rbtInsert(&(*tree)->right, value, tree);
    }
}