#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"
#include "stack.h"
#include "graph.h"

int hasNonVisitedVertices(struct Vertex *vertex) {
    for (int i = 0; i < vertex->edgesAmount; i++) {
        if (!vertex->edgesArray[i]->visited) {
            return 1;
        }
    }

    return 0;
}

void depthSearch(struct Graph *graph, int startVertexId, int endVertexId, struct LinkedListNode **pathStack) {
    struct Vertex *currentVertex = peekNodeById(graph, startVertexId);

    currentVertex->visited = 1;

    if (*pathStack == NULL) {
        push(pathStack, currentVertex);
    }

    for (int i = 0; i < currentVertex->edgesAmount; i++) {
        if (currentVertex->edgesArray[i]->visited) {
            continue;
        } else if (!currentVertex->edgesArray[i]->visited && currentVertex->edgesArray[i]->id == endVertexId) {
            push(pathStack, currentVertex->edgesArray[i]);
            printf("Labirinto solucionado\n");
            return;
        } else if (!currentVertex->edgesArray[i]->visited) {
            currentVertex->edgesArray[i]->visited = 1;
            push(pathStack, currentVertex->edgesArray[i]);
            depthSearch(graph, currentVertex->edgesArray[i]->id, endVertexId, pathStack);
        }
    }

    // if (currentVertex != NULL && hasNonVisitedVertices(currentVertex)) {
    //     struct LinkedListNode *previousPathStackNode = pop(pathStack);
    //     struct Vertex *previousVertex = (struct Vertex *) (previousPathStackNode->value);

    //     depthSearch(graph, previousVertex->id, endVertexId, pathStack);

    //     // free(previousPathStackNode);
    // }

    // printf("Labirinto sem solução\n");
}