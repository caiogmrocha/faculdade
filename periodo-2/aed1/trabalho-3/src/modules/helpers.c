#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

int randomInteger(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int *generateArray(int size, int percent, char order) {
    int *array = malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    if (order == 'A') {
        for (int i = 0; i < size; i++) {
            array[i] = i+1;
        }
    } else {
        for (int i = 0, j = size; i < size && j > 0; i++, j--) {
            array[i] = j;
        }
    }

    if (percent != 0) {
        int ordered_amount = (int) ((double) percent) / 100 * size;
        int unordered_amount = size - ordered_amount;

        for (int i = 0; i < unordered_amount; i++) {
            int j = randomInteger(0, size);
            int k = randomInteger(0, size);

            int aux = array[j];
            array[j] = array[k];
            array[k] = aux;
        }
    }

    return array;
}