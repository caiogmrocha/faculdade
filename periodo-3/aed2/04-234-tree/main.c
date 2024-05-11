#include <stdio.h>
#include <stdlib.h>
#include "ttf-tree.h"

int main() {
    printf("Hello World!\n");

    ttf *tree = ttfFactory();

    printf("%i\n", ttfAppendValue(&tree, 1));
    printf("%i\n", ttfAppendValue(&tree, 2));
    printf("%i\n", ttfAppendValue(&tree, 3));
    printf("%i\n", ttfAppendValue(&tree, 4));

    return 0;
}