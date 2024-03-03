#include <stdio.h>
#include "helpers.h"
#include "sort.h"

void bubbleSort(int *array, int size) {
    if (size == 1) return;

    for (int j = 0; j < size-1; j++) {
        for (int i = 0; i < size-1; i++) {
            if (array[i] > array[i+1]) {
                int aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
            }
        }
    }
}

void insertionSort(int *array, int size) {
    if (size == 1) return;

    for (int i = 1; i < size; i++) {
        int curr = array[i];
        int j = i-1;

        while (j >= 0 && array[j] > curr) {
            array[j+1] = array[j];
            j--;
        }

        array[++j] = curr;
    }
}

void selectionSort(int *array, int size) {
    if (size == 1) return;

    for (int i = 0; i < size; i++) {
        int menor_posicao = i;
            
        for (int j = i; j < size; j++) {
            if (array[j] < array[menor_posicao]) {
                menor_posicao = j;
            }
        }

        int aux = array[i];
        array[i] = array[menor_posicao];
        array[menor_posicao] = aux;
    }
}

void quickSort(int *array, int start, int end) {
    if (start < end) {
        int j = start;
        
        for (int i = start; i < end; i++) {
            if (array[i] <= array[end]) {
                int aux = array[i];
                array[i] = array[j];
                array[j] = aux;
                j++;
            }
        }

        int aux = array[j];
        array[j] = array[end];
        array[end] = aux;

        quickSort(array, j+1, end);
        quickSort(array, start, j-1);
    }
}