#include <stdio.h>
#include "modules/helpers.h"
#include "modules/sort.h"

void printArray(int *array, int size);

void bubbleSort(int *array, int size);

int main() {
    int array[4] = {4,3,2,1};

    printArray(array, 4);
    selectionSort(array, 4);
    printArray(array, 4);

    return 0;
}