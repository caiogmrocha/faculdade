#include <stdio.h>
#include <stdlib.h>
#include "bstavl.h"

void printNode(bst *tree) {
    printf("[%i]", tree->value);
}

int main() {
    int option;
    bst *tree = NULL;

    while (1) {
        scanf("%i", &option);

        switch (option) {
            case 1: {
                int value;

                scanf("%i", &value);

                bstInsert(&tree, bstFactory(value));

                break;
            }

            case 2: {
                bstPreOrder(tree, printNode);
                printf("\n");
                break;
            }

            case 3: {
                bstInOrder(tree, printNode);
                printf("\n");
                break;
            }

            case 4: {
                bstPostOrder(tree, printNode);
                printf("\n");
                break;
            }

            case 5: {
                int value;

                scanf("%i", &value);

                bstRemove(&tree, value);

                break;
            }

            case 6: {
                int value;

                scanf("%i", &value);

                bstRotateLeft(bstSearch(&tree, value));
                
                break;
            }

            case 7: {
                int value;

                scanf("%i", &value);

                bstRotateRight(bstSearch(&tree, value));
                
                break;
            }

            case 8: {
                int value;

                scanf("%i", &value);

                bstRotateRightLeft(bstSearch(&tree, value));
                
                break;
            }

            case 9: {
                int value;

                scanf("%i", &value);
                
                bstRotateLeftRight(bstSearch(&tree, value));
                
                break;
            }

            case 10: {
                printf("%d\n", bstHeight(tree));

                break;
            }

            case -1: {
                exit(1);
            }
        }
    }

    return 0;
}