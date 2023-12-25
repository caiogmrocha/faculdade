#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/graph.h"

int main() {
    struct Graph *graph = createGraph();

    addNode(&graph, 0);
    addNode(&graph, 1);
    addNode(&graph, 2);
    addNode(&graph, 3);
    addNode(&graph, 4);
    addEdge(&graph, graph->vertices[0], graph->vertices[1]);
    addEdge(&graph, graph->vertices[1], graph->vertices[2]);

    for (int i = 0; i < graph->verticesAmount; i++) {
        struct Vertex *vertex = graph->vertices[i];

        printf("Adjacências do V%d: ", vertex->id);

        printf("[ ");

        for (int j = 0; j < vertex->edgesAmount; j++) {
            if (j == vertex->edgesAmount - 1) {
                printf("%d", vertex->edgesArray[j].id);
            } else {
                printf("%d, ", vertex->edgesArray[j].id);
            }
        }
        printf(" ]\n");
    }

    return 0;
}