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

    char **maze;
    int numRows, numCols;

    readMaze("./databases/L1.txt", &maze, &numRows, &numCols);

    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (maze[i][j] == ' ') {
                addNode(&graph, index);
                index++;
            }
        }
    }

    // numRows = 2;
    // numCols = 6;

    int diff = -index;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // DIREITA
            if (j < numRows && index + diff < graph->verticesAmount && maze[i][j] == ' ' && maze[i][j+1] == ' ') {
                // printf("falhou na verificação à direita\n");
                // printf("index: %d, diff: %d, numCols: %d\n", index, diff, numCols);
                addEdge(&graph, graph->vertices[index + diff], graph->vertices[index + diff + 1]);
                addEdge(&graph, graph->vertices[index + diff + 1], graph->vertices[index + diff]);
            }

            // printf("i: %d, j: %d, index: %d, diff: %d, numRows: %d, numCols: %d\n", i, j, index, diff, numRows, numCols);

            // if (graph->vertices[index + diff]->id == 177) {
            //     printf("chegou aqui");
            // }

            // BAIXO
            if (i < numCols && index + diff + numCols < graph->verticesAmount && maze[i][j] == ' ' && maze[i+1][j] == ' ') {
                // printf("falhou na verificação abaixo\n");
                addEdge(&graph, graph->vertices[index + diff], graph->vertices[index + diff + numCols]);
                addEdge(&graph, graph->vertices[index + diff + numCols], graph->vertices[index + diff]);
            }

            // ESQUERDA
            if (j-1 >= 0 && index + diff < graph->verticesAmount && maze[i][j] == ' ' && maze[i][j-1] == ' ') {
                // printf("falhou na verificação à esquerda\n");
                addEdge(&graph, graph->vertices[index + diff], graph->vertices[index + diff - 1]);
                addEdge(&graph, graph->vertices[index + diff - 1], graph->vertices[index + diff]);
            }

            // CIMA
            if (i-1 >= 0 && index + diff < graph->verticesAmount && maze[i][j] == ' ' && maze[i-1][j] == ' ') {
                // printf("falhou na verificação acima\n");
                addEdge(&graph, graph->vertices[index + diff], graph->vertices[index + diff - numCols]);
                addEdge(&graph, graph->vertices[index + diff - numCols], graph->vertices[index + diff]);
            }

            diff++;
        }
    }

    // printf("Número de linhas: %d\n", numRows);
    // printf("Número de colunas: %d\n", numCols);
    // printf("Número de caracteres: %d\n", c);

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