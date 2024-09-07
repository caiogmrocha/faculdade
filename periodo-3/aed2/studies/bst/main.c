#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    struct tree *right;
    struct tree *left;
    int value;
} Tree;

void insert(Tree **tree, int value) {
    if (*tree == NULL) {
        *tree = (Tree *) malloc(sizeof (Tree));

        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->value = value;
    } else {
        if (value < (*tree)->value) {
            insert(&(*tree)->left, value);
        } else {
            insert(&(*tree)->right, value);
        }     
    }
}

Tree *binarySearch(Tree *tree, int value) {
    if (tree == NULL) {
        return NULL;
    } else {
        if (value == tree->value) {
            return tree;
        } else if (value < tree->value) {
            return binarySearch(tree->left, value);
        } else {
            return binarySearch(tree->right, value);
        }
    }
}

void processPreOrder(Tree *tree, void cb(Tree *tree)) {
    if (tree != NULL) {
        cb(tree);
        processPreOrder(tree->left, cb);
        processPreOrder(tree->right, cb);
    }
}

void processInOrder(Tree *tree, void cb(Tree *tree)) {
    if (tree != NULL) {
        processInOrder(tree->left, cb);
        cb(tree);
        processInOrder(tree->right, cb);
    }
}

void processInDescOrder(Tree *tree, void cb(Tree *tree)) {
    if (tree != NULL) {
        processInDescOrder(tree->right, cb);
        cb(tree);
        processInDescOrder(tree->left, cb);
    }
}

void print(Tree *tree) {
    printf("%i\n", tree->value);
}

void processPostOrder(Tree *tree, void cb(Tree *tree)) {
    if (tree != NULL) {
        processPostOrder(tree->left, cb);
        processPostOrder(tree->right, cb);
        cb(tree);
    }
}

void freeTree(Tree **tree) {
    if (*tree != NULL) {
        freeTree(&(*tree)->left);
        freeTree(&(*tree)->right);
        free(*tree);
    }
}

int main() {
    Tree *tree = NULL;

    insert(&tree, 10);
    insert(&tree, 7);
    insert(&tree, 18);
    insert(&tree, 2);
    insert(&tree, 7);
    insert(&tree, 3);
    insert(&tree, 1);
    insert(&tree, 15);

    Tree *subtree = binarySearch(tree, 16);

    processInDescOrder(tree, print);

    freeTree(&tree);

    return 0;
}