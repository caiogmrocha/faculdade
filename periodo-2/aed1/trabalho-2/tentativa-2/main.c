#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/graph.h"

void readMaze(char *path, char ***maze, int *numRows, int *numCols);

int main() {
    struct Graph *graph = createGraph();

    // addNode(&graph, 0);
    // addNode(&graph, 1);
    // addNode(&graph, 2);
    // addNode(&graph, 3);
    // addNode(&graph, 4);
    // addEdge(&graph, graph->vertices[0], graph->vertices[1]);
    // addEdge(&graph, graph->vertices[1], graph->vertices[2]);

    // for (int i = 0; i < graph->verticesAmount; i++) {
    //     struct Vertex *vertex = graph->vertices[i];

    //     printf("Adjacências do V%d: ", vertex->id);

    //     printf("[ ");

    //     for (int j = 0; j < vertex->edgesAmount; j++) {
    //         if (j == vertex->edgesAmount - 1) {
    //             printf("%d", vertex->edgesArray[j].id);
    //         } else {
    //             printf("%d, ", vertex->edgesArray[j].id);
    //         }
    //     }
    //     printf(" ]\n");
    // }

    char **maze;
    int numRows, numCols;

    readMaze("./databases/L1.txt", &maze, &numRows, &numCols);

    for (int i = 0; i < numRows; i++) {
        printf("%s", maze[i]);
    }

    return 0;
}

void readMaze(char *path, char ***maze, int *numRows, int *numCols) {
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        fprintf(stderr, "Erro ao tentar abrir o arquivo.\n");
        exit(1);
    }

    char input[160];

    while (fgets(input, sizeof(input), file) != NULL) {
        *maze = (char **) realloc(*maze, (*numRows + 1) * sizeof(char *));
        (*maze)[*numRows] = (char *) malloc(strlen(input)+1);
        strcpy((*maze)[*numRows], input);
        (*numRows)++;
    }

    fclose(file);
}