#include <stdio.h>
#include "helpers.h"

void printArray(int *array, int size) {
    printf("[ ");   
    
    for (int i = 0; i < size; i++) {
        if (i == size-1) {
            printf("%i", array[i]);
        } else {
            printf("%i, ", array[i]);
        }
    }

    printf(" ]\n");
}