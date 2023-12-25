#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct Graph *createGraph() {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));

    graph->verticesAmount = 0;
    graph->vertices = NULL;

    return graph;
}

void addNode(struct Graph **graph, int value) {
    if (*graph == NULL) {
        fprintf(stderr, "Grafo iniciado de forma incorreta.\n");
        exit(1);
    }

    (*graph)->verticesAmount += 1;

    (*graph)->vertices = (struct Vertex **) realloc((*graph)->vertices, ((*graph)->verticesAmount + 1) * sizeof(struct Vertex *));

    if ((*graph)->vertices == NULL) {
        fprintf(stderr, "Erro ao tentar alocar dinamicamente os vértice do grafo.\n");
        exit(1);
    }

    struct Vertex *newVertex = (struct Vertex *) malloc(sizeof(struct Vertex));

    newVertex->value = value;
    newVertex->edgesAmount = 0;

    (*graph)->vertices[(*graph)->verticesAmount - 1] = newVertex;
}
