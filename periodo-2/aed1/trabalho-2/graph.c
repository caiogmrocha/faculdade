#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


void initGraph(struct Graph **graph, int amount) {
    *graph = (struct Graph *) malloc(sizeof(struct Graph));
    (*graph)->vertices = (struct Vertex *) malloc(amount * sizeof(struct Vertex));

    for (int i = 0; i < amount; i++) {
        (*graph)->vertices[i].id = i;
        (*graph)->vertices[i].next = NULL;
    }

    (*graph)->amount = amount;
}

void addEdge(struct Vertex *vertex, int id) {
    struct Vertex *newVertex = (struct Vertex *) malloc(sizeof(struct Vertex));
    
    newVertex->id = id;
    newVertex->next = NULL;

    struct Vertex *iterator = vertex;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }

    iterator->next = newVertex;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->amount; i++) {
        printf("Vértice %d:\n", graph->vertices[i].id);

        struct Vertex *iterator = &(graph->vertices[i]);

        while (iterator != NULL) {

            if (iterator->next == NULL) {
                printf("%d\n", iterator->id);
            } else {
                printf("%d > ", iterator->id);
            }

            iterator = iterator->next;
        }
    }
}