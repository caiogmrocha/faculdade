#include <stdlib.h>
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

// preorder - RED
// inorder - ERD
// postorder - EDR