#include <stdio.h>
#include "helpers.h"
#include "sort.h"

void bubbleSort(int *array, int size, MetricsData *metrics) {    
    for (int j = 0; j < size-1; j++) {
        metrics->iterations++;

        for (int i = 0; i < size-1; i++) {
            metrics->iterations++;
            metrics->comparisons++;

            if (array[i] > array[i+1]) {
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                metrics->permutations++;
            }
        }
    }
}

void insertionSort(int *array, int size, MetricsData *metrics) {
    for (int i = 1; i < size; i++) {
        metrics->iterations++;
        int curr = array[i];
        int j = i-1;

        while (j >= 0 && array[j] > curr) {
            metrics->comparisons++;
            metrics->iterations++;
            metrics->permutations++;
           
            array[j+1] = array[j];
            j--;
        }
        metrics->comparisons++; // last comparison doesnt enter in while block-scope

        array[++j] = curr;
        metrics->permutations++;
    }
}

void selectionSort(int *array, int size, MetricsData *metrics) {
    for (int i = 0; i < size; i++) {
        metrics->iterations++;
        int menor_posicao = i;
            
        for (int j = i; j < size; j++) {
            metrics->iterations++;
            metrics->comparisons++;

            if (array[j] < array[menor_posicao]) {
                menor_posicao = j;
            }
        }

        int aux = array[i];
        array[i] = array[menor_posicao];
        array[menor_posicao] = aux;
        metrics->permutations++;
    }
}

void quickSort(int *array, int start, int end, MetricsData *metrics) {
    if (start < end) {
        int j = start;
        
        for (int i = start; i < end; i++) {
            metrics->iterations++;
            metrics->comparisons++;

            if (array[i] <= array[end]) {
                int aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                metrics->permutations++;
                j++;
            }
        }

        int aux = array[j];
        array[j] = array[end];
        array[end] = aux;
        metrics->permutations++;

        quickSort(array, j+1, end, metrics); 
        quickSort(array, start, j-1, metrics);
    }
}