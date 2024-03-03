#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "modules/helpers.h"
#include "modules/sort.h"

void printArray(int *array, int size);

void bubbleSort(int *array, int size);

int main() {
    srand(time(NULL));

    int *array = generateOrderedArray(100, 20);

    printArray(array, 100);

    free(array);

    // int array[4] = {4,3,2,1};
    // clock_t t0, tf;
    // double dt;

    // t0 = clock();
    // quickSort(array, 0, 3);
    // tf = clock();
    // dt = (double) (tf-t0)/CLOCKS_PER_SEC;

    return 0;
}