#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "modules/helpers.h"
#include "modules/sort.h"

void printArray(int *array, int size);

void bubbleSort(int *array, int size);

int main() {
    srand(time(NULL));

    // 10.000
    int *completellyRandomArray10000 = generateArray(10000, 0, 'A');
    int *seventyFivePercentRandomArray10000 = generateArray(10000, 75, 'A');
    int *fiftyPercentRandomArray10000 = generateArray(10000, 50, 'A');
    int *completellyAscOrderedArray10000 = generateArray(10000, 100, 'A');
    int *completellyDescOrderedArray10000 = generateArray(10000, 100, 'D');

    // 50.000
    int *completellyRandomArray50000 = generateArray(50000, 0, 'A');
    int *seventyFivePercentRandomArray50000 = generateArray(50000, 75, 'A');
    int *fiftyPercentRandomArray50000 = generateArray(50000, 50, 'A');
    int *completellyAscOrderedArray50000 = generateArray(50000, 100, 'A');
    int *completellyDescOrderedArray50000 = generateArray(50000, 100, 'D');

    // 100.000
    int *completellyRandomArray100000 = generateArray(100000, 0, 'A');
    int *seventyFivePercentRandomArray100000 = generateArray(100000, 75, 'A');
    int *fiftyPercentRandomArray100000 = generateArray(100000, 50, 'A');
    int *completellyAscOrderedArray100000 = generateArray(100000, 100, 'A');
    int *completellyDescOrderedArray100000 = generateArray(100000, 100, 'D');

    // 500.000
    int *completellyRandomArray500000 = generateArray(500000, 0, 'A');
    int *seventyFivePercentRandomArray500000 = generateArray(500000, 75, 'A');
    int *fiftyPercentRandomArray500000 = generateArray(500000, 50, 'A');
    int *completellyAscOrderedArray500000 = generateArray(500000, 100, 'A');
    int *completellyDescOrderedArray500000 = generateArray(500000, 100, 'D');

    // 1.000.000
    int *completellyRandomArray1000000 = generateArray(1000000, 0, 'A');
    int *seventyFivePercentRandomArray1000000 = generateArray(1000000, 75, 'A');
    int *fiftyPercentRandomArray1000000 = generateArray(1000000, 50, 'A');
    int *completellyAscOrderedArray1000000 = generateArray(1000000, 100, 'A');
    int *completellyDescOrderedArray1000000 = generateArray(1000000, 100, 'D');
    
    // 10.000.000
    int *completellyRandomArray10000000 = generateArray(10000000, 0, 'A');
    int *seventyFivePercentRandomArray10000000 = generateArray(10000000, 75, 'A');
    int *fiftyPercentRandomArray10000000 = generateArray(10000000, 50, 'A');
    int *completellyAscOrderedArray10000000 = generateArray(10000000, 100, 'A');
    int *completellyDescOrderedArray10000000 = generateArray(10000000, 100, 'D');

    // 50.000.000
    int *completellyRandomArray50000000 = generateArray(50000000, 0, 'A');
    int *seventyFivePercentRandomArray50000000 = generateArray(50000000, 75, 'A');
    int *fiftyPercentRandomArray50000000 = generateArray(50000000, 50, 'A');
    int *completellyAscOrderedArray50000000 = generateArray(50000000, 100, 'A');
    int *completellyDescOrderedArray50000000 = generateArray(50000000, 100, 'D');

    // printArray(array, 100);

    // int array[4] = {4,3,2,1};
    // clock_t t0, tf;
    // double dt;

    // t0 = clock();
    // quickSort(array, 0, 3);
    // tf = clock();
    // dt = (double) (tf-t0)/CLOCKS_PER_SEC;

    // free
    free(completellyRandomArray10000);
    free(seventyFivePercentRandomArray10000);
    free(fiftyPercentRandomArray10000);
    free(completellyAscOrderedArray10000);
    free(completellyDescOrderedArray10000);
    free(completellyRandomArray50000);
    free(seventyFivePercentRandomArray50000);
    free(fiftyPercentRandomArray50000);
    free(completellyAscOrderedArray50000);
    free(completellyDescOrderedArray50000);
    free(completellyRandomArray100000);
    free(seventyFivePercentRandomArray100000);
    free(fiftyPercentRandomArray100000);
    free(completellyAscOrderedArray100000);
    free(completellyDescOrderedArray100000);
    free(completellyRandomArray500000);
    free(seventyFivePercentRandomArray500000);
    free(fiftyPercentRandomArray500000);
    free(completellyAscOrderedArray500000);
    free(completellyDescOrderedArray500000);
    free(completellyRandomArray1000000);
    free(seventyFivePercentRandomArray1000000);
    free(fiftyPercentRandomArray1000000);
    free(completellyAscOrderedArray1000000);
    free(completellyDescOrderedArray1000000);
    free(completellyRandomArray10000000);
    free(seventyFivePercentRandomArray10000000);
    free(fiftyPercentRandomArray10000000);
    free(completellyAscOrderedArray10000000);
    free(completellyDescOrderedArray10000000);
    free(completellyRandomArray50000000);
    free(seventyFivePercentRandomArray50000000);
    free(fiftyPercentRandomArray50000000);
    free(completellyAscOrderedArray50000000);
    free(completellyDescOrderedArray50000000);

    return 0;
}