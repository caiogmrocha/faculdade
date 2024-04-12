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

    // printf("value: %p\n", tree->left);

    return 0;
}