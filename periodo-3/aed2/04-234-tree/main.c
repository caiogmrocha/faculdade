#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ttf-tree.h"

int main() {
    ttf *tree = ttfFactory();

    while (true) {
        int option;

        scanf("%i", &option);

        switch (option) {
            case 1: {
                int value;

                scanf("%i", &value);

                printf("%i\n", ttfAppendValue(&tree, value));
            } break;

            case 2: {
                for (int i = 0; i < TTF_VALUES_AMOUNT; i++) printf("[%i]", tree->values[i]);
                
                printf("\n");
            } break;

            case -1: {
                exit(EXIT_SUCCESS);
            }
        }
    }

    return EXIT_SUCCESS;
}