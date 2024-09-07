#include <stdlib.h>
#include <stdio.h>

#include "avl.h"

void printNode(avl *node) {
    printf("[%i %i]\n", node->value, node->bf);
}

int main() {
    avl *tree = NULL;
    short grew = 0;
    short shrank = 0;

    int option;

    while (1) {
        scanf("%i", &option);

        switch (option) {
            case 1: {
                int value;

                scanf("%i", &value);

                avlInsert(&tree, value, &grew);
            } break;

            case 2: {
                avlPreOrderTraversal(tree, (void (*)(avl *node)) printNode);
            } break;

            case 3: {
                int value;

                scanf("%i", &value);

                avlRemove(&tree, value, &shrank);
            } break;
            
            case 99: {
                avlPostOrderTraversal(tree, (void (*)(avl *node)) free);
                exit(0);
            } break;
        }
    }

    return 0;
}