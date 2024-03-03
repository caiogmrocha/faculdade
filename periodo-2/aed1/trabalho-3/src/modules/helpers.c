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
    printf("Iterations: %i\n", metrics.bubbleSort.iterations);
    printf("Permutations: %i\n", metrics.bubbleSort.permutations);
    printf("Comparisons: %i\n", metrics.bubbleSort.comparisons);
    printf("\n");

    printf("Insertion Sort\n");
    printf("Execution Time: %f\n", metrics.insertionSort.executionTime);
    printf("Iterations: %i\n", metrics.insertionSort.iterations);
    printf("Permutations: %i\n", metrics.insertionSort.permutations);
    printf("Comparisons: %i\n", metrics.insertionSort.comparisons);
    printf("\n");

    printf("Selection Sort\n");
    printf("Execution Time: %f\n", metrics.selectionSort.executionTime);
    printf("Iterations: %i\n", metrics.selectionSort.iterations);
    printf("Permutations: %i\n", metrics.selectionSort.permutations);
    printf("Comparisons: %i\n", metrics.selectionSort.comparisons);
    printf("\n");

    printf("Quick Sort\n");
    printf("Execution Time: %f\n", metrics.quickSort.executionTime);
    printf("Iterations: %i\n", metrics.quickSort.iterations);
    printf("Permutations: %i\n", metrics.quickSort.permutations);
    printf("Comparisons: %i\n", metrics.quickSort.comparisons);
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
    fprintf(file, "- Iterations: %i\n", metrics.bubbleSort.iterations);
    fprintf(file, "- Permutations: %i\n", metrics.bubbleSort.permutations);
    fprintf(file, "- Comparisons: %i\n", metrics.bubbleSort.comparisons);
    fprintf(file, "\n");

    fprintf(file, "## Insertion Sort\n");
    fprintf(file, "- Execution Time: %f\n", metrics.insertionSort.executionTime);
    fprintf(file, "- Iterations: %i\n", metrics.insertionSort.iterations);
    fprintf(file, "- Permutations: %i\n", metrics.insertionSort.permutations);
    fprintf(file, "- Comparisons: %i\n", metrics.insertionSort.comparisons);
    fprintf(file, "\n");

    fprintf(file, "## Selection Sort\n");
    fprintf(file, "- Execution Time: %f\n", metrics.selectionSort.executionTime);
    fprintf(file, "- Iterations: %i\n", metrics.selectionSort.iterations);
    fprintf(file, "- Permutations: %i\n", metrics.selectionSort.permutations);
    fprintf(file, "- Comparisons: %i\n", metrics.selectionSort.comparisons);
    fprintf(file, "\n");

    fprintf(file, "## Quick Sort\n");
    fprintf(file, "- Execution Time: %f\n", metrics.quickSort.executionTime);
    fprintf(file, "- Iterations: %i\n", metrics.quickSort.iterations);
    fprintf(file, "- Permutations: %i\n", metrics.quickSort.permutations);
    fprintf(file, "- Comparisons: %i\n", metrics.quickSort.comparisons);
    fprintf(file, "\n");

    fclose(file);
}

void printMetricsToLatex(Metrics metrics, int size) {
    printf("\\begin{tikzpicture}\n");
    printf("\\begin{axis}[\n");
    printf("xbar,\n");
    printf("]\n");
    printf("\\addplot[bblue,style={fill=bblue}] coordinates {(%f,%i)};\n", metrics.bubbleSort.executionTime, size);
    printf("\\addplot[rred,style={fill=rred}] coordinates {(%f,%i)};\n", metrics.insertionSort.executionTime, size);
    printf("\\addplot[ggreen,style={fill=ggreen}] coordinates {(%f,%i)};\n", metrics.selectionSort.executionTime, size);
    printf("\\addplot[ppurple,style={fill=ppurple}] coordinates {(%f,%i)};\n", metrics.quickSort.executionTime, size);
    printf("\\legend {Bubble Sort,Insertion Sort,Selection Sort,Quick Sort}\n");
    printf("\\end{axis}\n");
    printf("\\end{tikzpicture}\n");
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