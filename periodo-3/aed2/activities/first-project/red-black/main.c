#include <stdlib.h>
#include <stdio.h>

#include "rbt.h"

void printNode(rbt **node) {
    if ((*node) != NULL) {
        if ((*node)->color == BLACK) {
            printf("[%i %c]\n", (*node)->value, 'B');
        } else {
            printf("[%i %c]\n", (*node)->value, 'R');
        }
    }
}

void freeNode(rbt **node) {
    if ((*node) != NULL) {
        free(*node);
        *node = NULL;
    }
}

int main() {
    rbt *tree = NULL;

    int option;

    while (1) {
        scanf("%i", &option);

        switch (option) {
            case 1: {
                int value;

                scanf("%i", &value);

                rbtInsert(&tree, value);
            } break;

            case 2: {
                rbtPreOrderTraversal(&tree, printNode);
            } break;

            case 3: {
                int value;

                scanf("%i", &value);

                rbtRemove(&tree, value);
            } break;
            
            case 99: {
                rbtPostOrderTraversal(&tree, freeNode);
                exit(0);
            } break;
        }
    }

    return 0;
}
