#include "sort.h"

void bubbleSort(int *array, int size) {
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
