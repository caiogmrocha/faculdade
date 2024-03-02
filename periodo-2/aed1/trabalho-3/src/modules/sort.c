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