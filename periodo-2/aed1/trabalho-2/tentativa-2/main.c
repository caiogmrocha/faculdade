#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/graph.h"

int main() {
    struct Graph *graph = createGraph();

    addNode(&graph, 1);
    addNode(&graph, 2);
    addNode(&graph, 3);
    addNode(&graph, 4);
    addNode(&graph, 5);

    for (int i = 0; i < graph->verticesAmount; i++) {
        struct Vertex *vertex = graph->vertices[i];

        printf("Vértice %d: ", vertex->value);

        for (int j = 0; j < vertex->edgesAmount; j++) {
            printf("%d ", vertex->edgesArray[j].value);

            if (j == vertex->edgesAmount - 1) {
                printf("%d", vertex->edgesArray[j].value);
            } else {
                printf("%d > ", vertex->edgesArray[j].value);
            }
        }

        printf("\n");
    }

    return 0;
}