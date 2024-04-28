#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "helpers.h"
#include "sort.h"

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

void printMetrics(Metrics metrics) {
    printf("Bubble Sort\n");
    printf("Execution Time: %f\n", metrics.bubbleSort.executionTime);
    printf("Iterations: %li\n", metrics.bubbleSort.iterations);
    printf("Permutations: %li\n", metrics.bubbleSort.permutations);
    printf("Comparisons: %li\n", metrics.bubbleSort.comparisons);
    printf("\n");

    printf("Insertion Sort\n");
    printf("Execution Time: %f\n", metrics.insertionSort.executionTime);
    printf("Iterations: %li\n", metrics.insertionSort.iterations);
    printf("Permutations: %li\n", metrics.insertionSort.permutations);
    printf("Comparisons: %li\n", metrics.insertionSort.comparisons);
    printf("\n");

    printf("Selection Sort\n");
    printf("Execution Time: %f\n", metrics.selectionSort.executionTime);
    printf("Iterations: %li\n", metrics.selectionSort.iterations);
    printf("Permutations: %li\n", metrics.selectionSort.permutations);
    printf("Comparisons: %li\n", metrics.selectionSort.comparisons);
    printf("\n");

    printf("Quick Sort\n");
    printf("Execution Time: %f\n", metrics.quickSort.executionTime);
    printf("Iterations: %li\n", metrics.quickSort.iterations);
    printf("Permutations: %li\n", metrics.quickSort.permutations);
    printf("Comparisons: %li\n", metrics.quickSort.comparisons);
    printf("\n");
}

void printMetricsToTxt(Metrics metrics, int size, char *arrayName) {
    FILE *file = fopen("metrics.md", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(file, "# Array name: %s\n (size: %i)\n", arrayName, size);
    
    fprintf(file, "## Bubble Sort\n");
    fprintf(file, "- Execution Time: %f\n", metrics.bubbleSort.executionTime);
    fprintf(file, "- Iterations: %li\n", metrics.bubbleSort.iterations);
    fprintf(file, "- Permutations: %li\n", metrics.bubbleSort.permutations);
    fprintf(file, "- Comparisons: %li\n", metrics.bubbleSort.comparisons);
    fprintf(file, "\n");

    fprintf(file, "## Insertion Sort\n");
    fprintf(file, "- Execution Time: %f\n", metrics.insertionSort.executionTime);
    fprintf(file, "- Iterations: %li\n", metrics.insertionSort.iterations);
    fprintf(file, "- Permutations: %li\n", metrics.insertionSort.permutations);
    fprintf(file, "- Comparisons: %li\n", metrics.insertionSort.comparisons);
    fprintf(file, "\n");

    fprintf(file, "## Selection Sort\n");
    fprintf(file, "- Execution Time: %f\n", metrics.selectionSort.executionTime);
    fprintf(file, "- Iterations: %li\n", metrics.selectionSort.iterations);
    fprintf(file, "- Permutations: %li\n", metrics.selectionSort.permutations);
    fprintf(file, "- Comparisons: %li\n", metrics.selectionSort.comparisons);
    fprintf(file, "\n");

    fprintf(file, "## Quick Sort\n");
    fprintf(file, "- Execution Time: %f\n", metrics.quickSort.executionTime);
    fprintf(file, "- Iterations: %li\n", metrics.quickSort.iterations);
    fprintf(file, "- Permutations: %li\n", metrics.quickSort.permutations);
    fprintf(file, "- Comparisons: %li\n", metrics.quickSort.comparisons);
    fprintf(file, "\n");

    fclose(file);
}

void printMetricsToCsv(Metrics metrics, int size, char *arrayName) {
    FILE *file = fopen("metrics.csv", "a");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Array Name, Size, Algorithm, Execution Time, Iterations, Permutations, Comparisons
    fprintf(file, "%s,%i,%s,%f,%li,%li,%li\n", arrayName, size, "BubbleSort", metrics.bubbleSort.executionTime, metrics.bubbleSort.iterations, metrics.bubbleSort.permutations, metrics.bubbleSort.comparisons);
    fprintf(file, "%s,%i,%s,%f,%li,%li,%li\n", arrayName, size, "InsertionSort", metrics.insertionSort.executionTime, metrics.insertionSort.iterations, metrics.insertionSort.permutations, metrics.insertionSort.comparisons);
    fprintf(file, "%s,%i,%s,%f,%li,%li,%li\n", arrayName, size, "SelectionSort", metrics.selectionSort.executionTime, metrics.selectionSort.iterations, metrics.selectionSort.permutations, metrics.selectionSort.comparisons);
    fprintf(file, "%s,%i,%s,%f,%li,%li,%li\n", arrayName, size, "QuickSort", metrics.quickSort.executionTime, metrics.quickSort.iterations, metrics.quickSort.permutations, metrics.quickSort.comparisons);

    fclose(file);
}

Metrics measurePerformance(int *array, int size) {
    clock_t t0, tf;

    Metrics metrics = {
        .bubbleSort = {
            .executionTime = 0.0,
            .iterations = 0,
            .permutations = 0,
            .comparisons = 0,
        },
        .insertionSort = {
            .executionTime = 0.0,
            .iterations = 0,
            .permutations = 0,
            .comparisons = 0,
        },
        .selectionSort = {
            .executionTime = 0.0,
            .iterations = 0,
            .permutations = 0,
            .comparisons = 0,
        },
        .quickSort = {
            .executionTime = 0.0,
            .iterations = 0,
            .permutations = 0,
            .comparisons = 0,
        },
    };
    
    printf("BubbleSort\n");
    t0 = clock();
    bubbleSort(array, size, &metrics.bubbleSort);
    tf = clock();
    metrics.bubbleSort.executionTime = (double) (tf-t0)/CLOCKS_PER_SEC;
    
    printf("insertionSort\n");
    t0 = clock();
    insertionSort(array, size, &metrics.insertionSort);
    tf = clock();
    metrics.insertionSort.executionTime = (double) (tf-t0)/CLOCKS_PER_SEC;
    
    printf("selectionSort\n");
    t0 = clock();
    selectionSort(array, size, &metrics.selectionSort);
    tf = clock();
    metrics.selectionSort.executionTime = (double) (tf-t0)/CLOCKS_PER_SEC;
    
    printf("quickSort\n");
    t0 = clock();
    quickSort(array, 0, size-1, &metrics.quickSort);
    tf = clock();
    metrics.quickSort.executionTime = (double) (tf-t0)/CLOCKS_PER_SEC;

    return metrics;
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