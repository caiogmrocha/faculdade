#include <stdlib.h>
#include "avl.h"

avl *avlFactory(int value) {
    avl *node = (avl *) malloc(sizeof(avl));

    node->left = NULL;
    node->right = NULL;
    node->value = value;
    node->fb = 0;

    return node;
}

avl *avlInsert(avl *tree, int value) {
    if (tree == NULL) {
        tree = avlFactory(value);
    } else if (value > tree->value) {
        tree->right = avlInsert(tree->right, value);
    } else {
        tree->left = avlInsert(tree->left, value);
    }

    return tree;
}

avl *greather(avl *tree) {
    avl *iterator = tree->right;

    while (iterator->right != NULL) {
        iterator = iterator->right;
    }

    return iterator;
}

avl *avlRemove(avl *tree, int value) {
    if (tree == NULL) {
        return tree;
    } else if (value == tree->value) {
        if (tree->left == NULL && tree->right == NULL) {
            free(tree);

            return NULL;
        } else if (tree->left != NULL && tree->right == NULL) {
            avl *temp = tree;

            tree = tree->left;

            free(temp);

            return tree;
        } else if (tree->left == NULL && tree->right != NULL) {
            avl *temp = tree;

            tree = tree->right;

            free(temp);

            return tree;
        } else {
            avl *greatherAtLeft = greather(tree->left);

            tree->value = greatherAtLeft->value;

            tree->left = avlRemove(tree->left, greatherAtLeft->value);

            return tree;
        }
    } else if (value > tree->value) {
        tree->right = avlRemove(tree->right, value);
    } else {
        tree->left = avlRemove(tree->left, value);
    }

    return tree;
}

avl *avlPreOrderTraversal(avl *tree, void cb(avl *tree)) {
    if (tree != NULL) {
        cb(tree);
        avlPreOrderTraversal(tree->left, cb);
        avlPreOrderTraversal(tree->right, cb);
    }
}

avl *avlInOrderTraversal(avl *tree, void cb(avl *tree)) {
    if (tree != NULL) {
        avlInOrderTraversal(tree->left, cb);
        cb(tree);
        avlInOrderTraversal(tree->right, cb);
    }
}

avl *avlPostOrderTraversal(avl *tree, void cb(avl *tree)) {
    if (tree != NULL) {
        avlPostOrderTraversal(tree->left, cb);
        avlPostOrderTraversal(tree->right, cb);
        cb(tree);
    }
}
