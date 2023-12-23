#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main() {
    struct Graph *graph;
    
    initGraph(&graph, 4);
    addEdge(&graph->vertices[0], 1);
    addEdge(&graph->vertices[0], 2);
    addEdge(&graph->vertices[0], 3);

    printGraph(graph);

    return 0;
}