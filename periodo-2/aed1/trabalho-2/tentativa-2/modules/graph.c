#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct Graph *createGraph() {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));

    graph->verticesAmount = 0;
    graph->vertices = NULL;

    return graph;
}

void addNode(struct Graph **graph, int id) {
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

    newVertex->id = id;
    newVertex->visited = 0;
    newVertex->edgesAmount = 0;

    (*graph)->vertices[(*graph)->verticesAmount - 1] = newVertex;
}

void addEdge(struct Graph **graph, struct Vertex *vertex1, struct Vertex *vertex2) {
    if (*graph == NULL) {
        fprintf(stderr, "Grafo iniciado de forma incorreta.\n");
        exit(1);
    }

    if (vertex1 == NULL || vertex2 == NULL) {
        fprintf(stderr, "Vértice(s) inválido(s).\n");
        exit(1);
    }

    vertex1->edgesAmount += 1;

    vertex1->edgesArray = (struct Vertex *) realloc(vertex1->edgesArray, (vertex1->edgesAmount + 1) * sizeof(struct Vertex));

    if (vertex1->edgesArray == NULL) {
        fprintf(stderr, "Erro ao tentar alocar dinamicamente os vértice do grafo.\n");
        exit(1);
    }

    vertex1->edgesArray[vertex1->edgesAmount - 1] = *vertex2;

    vertex2->edgesAmount += 1;

    vertex2->edgesArray = (struct Vertex *) realloc(vertex2->edgesArray, (vertex2->edgesAmount + 1) * sizeof(struct Vertex));

    if (vertex2->edgesArray == NULL) {
        fprintf(stderr, "Erro ao tentar alocar dinamicamente os vértice do grafo.\n");
        exit(1);
    }

    vertex2->edgesArray[vertex2->edgesAmount - 1] = *vertex1;
}