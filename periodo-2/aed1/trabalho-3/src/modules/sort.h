#ifndef H_SORT
#define H_SORT

#include "helpers.h"

void bubbleSort(int *array, int size, MetricsData *metrics);
void insertionSort(int *array, int size, MetricsData *metrics);
void selectionSort(int *array, int size, MetricsData *metrics);
void quickSort(int *array, int start, int end, MetricsData *metrics);

#endif