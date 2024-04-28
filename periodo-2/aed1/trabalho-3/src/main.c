#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "modules/helpers.h"
#include "modules/sort.h"

void printArray(int *array, int size);

int main() {
    srand(time(NULL));

    int arraysAmount[3] = {
        10000,
        50000,
        100000,
        // 500000,
        // 1000000,
        // 10000000,
        // 50000000,
    };

    for (int i = 0; i < 3; i++) {
        printf("Array size: %i\n", arraysAmount[i]);

        int *completellyRandomArray = generateArray(arraysAmount[i], 0, 'A');
        printf("Array generated!\n");
        // printArray(completellyRandomArray, arraysAmount[i]);
        printMetricsToCsv(
            measurePerformance(completellyRandomArray,arraysAmount[i]),
            arraysAmount[i],
            "completellyRandomArray"
        );
        free(completellyRandomArray);

        int *seventyFivePercentRandomArray = generateArray(arraysAmount[i], 75, 'A');
        printMetricsToCsv(
            measurePerformance(seventyFivePercentRandomArray,arraysAmount[i]),
            arraysAmount[i],
            "seventyFivePercentRandomArray"
        );
        free(seventyFivePercentRandomArray);

        int *fiftyPercentRandomArray = generateArray(arraysAmount[i], 50, 'A');
        printMetricsToCsv(
            measurePerformance(fiftyPercentRandomArray,arraysAmount[i]),
            arraysAmount[i],
            "fiftyPercentRandomArray"
        );
        free(fiftyPercentRandomArray);

        int *completellyAscOrderedArray = generateArray(arraysAmount[i], 100, 'A');
        printMetricsToCsv(
            measurePerformance(completellyAscOrderedArray,arraysAmount[i]),
            arraysAmount[i],
            "completellyAscOrderedArray"
        );
        free(completellyAscOrderedArray);

        int *completellyDescOrderedArray = generateArray(arraysAmount[i], 100, 'D');
        printMetricsToCsv(
            measurePerformance(completellyDescOrderedArray,arraysAmount[i]),
            arraysAmount[i],
            "completellyDescOrderedArray"
        );
        free(completellyDescOrderedArray);
        
        printf("Done!\n");
    }

    printf("Done de verdade!\n");

    return 0;
}