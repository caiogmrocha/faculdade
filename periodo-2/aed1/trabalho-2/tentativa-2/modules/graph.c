#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct Graph *createGraph() {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));

    graph->amount = 0;
    graph->vertices = NULL;

    return graph;
}

void addNode(struct Graph **graph, int value) {
    if (*graph == NULL) {
        fprintf(stderr, "Grafo iniciado de forma incorreta.\n");
        exit(1);
    }

    (*graph)->amount += 1;

    printf("amount: %d\n", (*graph)->amount);

    if ((*graph)->vertices == NULL) {
        (*graph)->vertices = (struct LinkedListNode **) malloc((*graph)->amount * sizeof(struct LinkedListNode *));
    } else {
        (*graph)->vertices = (struct LinkedListNode **) realloc((*graph)->vertices, (*graph)->amount * sizeof(struct LinkedListNode *));
    }

    if ((*graph)->vertices == NULL) {
        fprintf(stderr, "Erro ao tentar alocar dinamicamente os vértice do grafo.\n");
        exit(1);
    }

    struct LinkedListNode *newNode = (struct LinkedListNode *) malloc(sizeof(struct LinkedListNode));

    newNode->value = value;
    newNode->next = NULL;

    (*graph)->vertices[(*graph)->amount - 1] = newNode;
}

void addEdge(struct Graph **graph, struct LinkedListNode *vertex1, struct LinkedListNode *vertex2);