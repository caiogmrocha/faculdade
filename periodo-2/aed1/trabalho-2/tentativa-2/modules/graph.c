#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct Graph *createGraph() {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));

    graph->verticesAmount = 0;
    graph->vertices = NULL;

    return graph;
}

void addNode(struct Graph **graph, int id, int x, int y) {
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
    newVertex->x = x;
    newVertex->y = y;
    newVertex->visited = 0;
    newVertex->edgesAmount = 0;
    newVertex->edgesArray = NULL;

    (*graph)->vertices[(*graph)->verticesAmount - 1] = newVertex;
}

void addEdge(struct Graph **graph, struct Vertex **vertex1, struct Vertex **vertex2) {
    if (*graph == NULL) {
        fprintf(stderr, "Grafo iniciado de forma incorreta.\n");
        exit(1);
    }

    if (*vertex1 == NULL || *vertex2 == NULL) {
        fprintf(stderr, "Vértice(s) inválido(s).\n");
        exit(1);
    }

    for (int i = 0; i < (*vertex1)->edgesAmount; i++) {
        if ((*(*vertex1)->edgesArray[i]).id == (*vertex2)->id) return;
    }

    (*vertex1)->edgesAmount += 1;

    (*vertex1)->edgesArray = (struct Vertex **) realloc((*vertex1)->edgesArray, ((*vertex1)->edgesAmount + 1) * sizeof(struct Vertex *));

    if ((*vertex1)->edgesArray == NULL) {
        fprintf(stderr, "Erro ao tentar alocar dinamicamente os vértice do grafo.\n");
        exit(1);
    }

    (*vertex1)->edgesArray[(*vertex1)->edgesAmount - 1] = *vertex2;

    (*vertex2)->edgesAmount += 1;

    (*vertex2)->edgesArray = (struct Vertex **) realloc((*vertex2)->edgesArray, ((*vertex2)->edgesAmount + 1) * sizeof(struct Vertex *));

    if ((*vertex2)->edgesArray == NULL) {
        fprintf(stderr, "Erro ao tentar alocar dinamicamente os vértice do grafo.\n");
        exit(1);
    }

    (*vertex2)->edgesArray[(*vertex2)->edgesAmount - 1] = *vertex1;
}

void debugGraph(struct Graph *graph) {
    for (int i = 0; i < graph->verticesAmount; i++) {
        struct Vertex *vertex = graph->vertices[i];

        debugVertex(vertex);
    }
}

void debugVertex(struct Vertex *vertex) {
    printf("Adjacências do V%d: ", vertex->id);

    printf("[ ");

    for (int j = 0; j < vertex->edgesAmount; j++) {
        if (j == vertex->edgesAmount - 1) {
            printf("%d", (*vertex->edgesArray[j]).id);
        } else {
            printf("%d, ", (*vertex->edgesArray[j]).id);
        }
    }

    printf(" ]\n");
}

void freeGraph(struct Graph *graph) {
    if (graph == NULL) {
        fprintf(stderr, "Grafo iniciado de forma incorreta.\n");
        exit(1);
    }

    for (int i = 0; i < graph->verticesAmount; i++) {
        if (graph->vertices[i]->edgesAmount > 0) {
            free(graph->vertices[i]->edgesArray);
        }

        if (graph->vertices[i] != NULL) {
            free(graph->vertices[i]);
        }
    }

    if (graph->verticesAmount > 0) {
        free(graph->vertices);
    }

    if (graph != NULL) {
        free(graph);
    }
}

struct Vertex *peekNodeByCoordinates(struct Graph *graph, int x, int y) {
    for (int i = 0; i < graph->verticesAmount; i++) {
        if (graph->vertices[i]->x == x && graph->vertices[i]->y == y) {
            return graph->vertices[i];
        }
    }

    return NULL;
}

struct Vertex *peekNodeById(struct Graph *graph, int id) {
    for (int i = 0; i < graph->verticesAmount; i++) {
        if (graph->vertices[i]->id == id) {
            return graph->vertices[i];
        }
    }

    return NULL;
}