#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/graph.h"

void readMaze(char *path, char ***maze, int *numRows, int *numCols);

int main(int argc, char *argv[]) {
    struct Graph *graph = createGraph();

    char **maze;
    int numRows, numCols;

    printf("argc: %d\n", argc);
    printf("argv[0]: %s\n", argv[0]);

    readMaze(argc >= 1 && argv[1] != NULL ? argv[1] : "./databases/L1.txt", &maze, &numRows, &numCols);

    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (maze[i][j] == ' ') {
                addNode(&graph, index);
                index++;
            }
        }
    }

    int diff = -index;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // DIREITA
            if (j < numRows && index + diff < graph->verticesAmount && maze[i][j] == ' ' && maze[i][j+1] == ' ') {
                addEdge(&graph, graph->vertices[index + diff], graph->vertices[index + diff + 1]);
                addEdge(&graph, graph->vertices[index + diff + 1], graph->vertices[index + diff]);
            }

            // BAIXO
            if (i < numCols && index + diff + numCols < graph->verticesAmount && maze[i][j] == ' ' && maze[i+1][j] == ' ') {
                addEdge(&graph, graph->vertices[index + diff], graph->vertices[index + diff + numCols]);
                addEdge(&graph, graph->vertices[index + diff + numCols], graph->vertices[index + diff]);
            }

            // ESQUERDA
            if (j-1 >= 0 && index + diff < graph->verticesAmount && maze[i][j] == ' ' && maze[i][j-1] == ' ') {
                addEdge(&graph, graph->vertices[index + diff], graph->vertices[index + diff - 1]);
                addEdge(&graph, graph->vertices[index + diff - 1], graph->vertices[index + diff]);
            }

            // CIMA
            if (i-1 >= 0 && index + diff < graph->verticesAmount && maze[i][j] == ' ' && maze[i-1][j] == ' ') {
                addEdge(&graph, graph->vertices[index + diff], graph->vertices[index + diff - numCols]);
                addEdge(&graph, graph->vertices[index + diff - numCols], graph->vertices[index + diff]);
            }

            diff++;
        }
    }

    debugGraph(graph);

    // Freeing memory
    for (int i = 0; i < numRows; i++) {
        free(maze[i]);
    }

    free(maze);
    freeGraph(graph);

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

    *numCols = strlen((*maze)[0]);

    fclose(file);
}