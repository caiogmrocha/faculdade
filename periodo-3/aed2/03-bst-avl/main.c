#include <stdio.h>
#include <stdlib.h>
#include "bstavl.h"

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

            case -1: {
                exit(1);
            }
        }
    }

    return 0;
}