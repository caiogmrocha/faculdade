#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    struct tree *left;
    struct tree *right;
    int value;
} Tree;

void insert(Tree **tree, int value) {
    if (*tree == NULL) {
        *tree = (Tree *) malloc(sizeof(tree));

        (*tree)->left = NULL;
        (*tree)->right = NULL;
        (*tree)->value = value;
    } else if (value < (*tree)->value) {
        insert(&(*tree)->left, value);
    } else {
        insert(&(*tree)->right, value);
    }
}

// void freeTree(Tree **tree) {
//     if (*tree != NULL) {
//         freeTree(&(*tree)->left);
//         freeTree(&(*tree)->right);
//         free(tree);
//     }
// }

void processPreOrder(Tree **tree, void cb(Tree *tree, char **output), char **output) {
    if (*tree != NULL) {
        cb(*tree, output);
        processPreOrder(&(*tree)->left, cb, output);
        processPreOrder(&(*tree)->right, cb, output);
    }
}

void processInOrder(Tree **tree, void cb(Tree *tree, char **output), char **output) {
    if (*tree != NULL) {
        processInOrder(&(*tree)->left, cb, output);
        cb(*tree, output);
        processInOrder(&(*tree)->right, cb, output);
    }
}

void processPostOrder(Tree **tree, void cb(Tree *tree, char **output), char **output) {
    if (*tree != NULL) {
        processPostOrder(&(*tree)->left, cb, output);
        processPostOrder(&(*tree)->right, cb, output);
        cb(*tree, output);
    }
}

void processOutput(Tree *tree, char **output) {
    int fragmentLength = snprintf(NULL, 0, "%i ", tree->value) + 1;
    
    if (*output == NULL) {
        *output = (char *) malloc(sizeof(char) * fragmentLength);
        (*output)[0] = '\0';
    } else {
        *output = (char *) realloc(*output, sizeof(char) * (strlen(*output) + fragmentLength));
    }

    char fragment[3];

    sprintf(fragment, "%i ", tree->value);

    strcat(*output, fragment);
};

int main() {
    int c;

    scanf("%i", &c);

    for (int i = 0; i < c; i++) {
        int n;
        Tree *tree = NULL;

        printf("Case %i:\n", i + 1);

        scanf("%i", &n);

        for (int j = 0; j < n; j++) {
            int value;

            scanf("%i", &value);

            insert(&tree, value);
        }

        char *output = NULL;

        printf("Pre.: ");
        processPreOrder(&tree, processOutput, &output);
        output[strlen(output) - 1] = '\0';
        printf("%s", output);
        printf("\n");

        output = NULL;

        printf("In..: ");
        processInOrder(&tree, processOutput, &output);
        output[strlen(output) - 1] = '\0';
        printf("%s", output);
        printf("\n");

        output = NULL;
        printf("Post: ");
        processPostOrder(&tree, processOutput, &output);
        output[strlen(output) - 1] = '\0';
        printf("%s", output);
        printf("\n");

        printf("\n");
    }


    return 0;
}