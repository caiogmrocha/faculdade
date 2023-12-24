#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/graph.h"

int main() {
    struct Graph *graph = createGraph();

    addNode(&graph, 1);
    addNode(&graph, 2);
    // addNode(&graph, 3);
    // addNode(&graph, 4);
    // addNode(&graph, 5);

    for (int i = 0; i < graph->amount; i++) {
        struct LinkedListNode *iterator = graph->vertices[i];

        printf("Vértice %d: ", iterator->value);

        while (iterator != NULL) {
            if (iterator->next == NULL) {
                printf("%d\n", iterator->value);
            } else {
                printf("%d > ", iterator->value);
            }

            iterator = iterator->next;
        }
    }

    return 0;
}