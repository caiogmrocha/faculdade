#include <stdio.h>

#include "modules/avl.h"

int main() {
    printf("Hello World!\n");

    avl *tree = avlFactory(1);

    printf("Value: %i\n", tree->value);

    return 0;
}