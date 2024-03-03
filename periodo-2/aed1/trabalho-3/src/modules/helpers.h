#ifndef H_HELPERS
#define H_HELPERS

typedef struct {
    double executionTime;
    int iterations;
    int permutations;
    int comparisons;
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
void printMetricsToLatex(Metrics metrics, int size);
Metrics measurePerformance(int *array, int size);
int *generateArray(int size, int percent, char order);

#endif