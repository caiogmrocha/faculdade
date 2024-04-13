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

void processPreOrder(Tree *tree) {
    if (tree != NULL) {
        printf("%i\n", tree->value);
        processPreOrder(tree->left);
        processPreOrder(tree->right);
    }
}

void processInOrder(Tree *tree) {
    if (tree != NULL) {
        processInOrder(tree->left);
        printf("%i\n", tree->value);
        processInOrder(tree->right);
    }
}

void processPostOrder(Tree *tree) {
    if (tree != NULL) {
        processPostOrder(tree->left);
        processPostOrder(tree->right);
        printf("%i\n", tree->value);
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

    processPostOrder(tree);

    return 0;
}