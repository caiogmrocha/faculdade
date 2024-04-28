#ifndef H_HELPERS
#define H_HELPERS

typedef struct {
    double executionTime;
    long int iterations;
    long int permutations;
    long int comparisons;
} MetricsData;

typedef struct {
    MetricsData bubbleSort;
    MetricsData insertionSort;
    MetricsData selectionSort;
    MetricsData quickSort;
} Metrics;

void printArray(int *array, int size);
void printMetrics(Metrics metrics);
void printMetricsToTxt(Metrics metrics, int size, char *arrayName);
void printMetricsToCsv(Metrics metrics, int size, char *arrayName);
Metrics measurePerformance(int *array, int size);
int *generateArray(int size, int percent, char order);

#endif