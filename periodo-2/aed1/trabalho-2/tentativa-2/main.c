#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "modules/stack.h"
#include "modules/graph.h"
#include "modules/depth-search.h"

void readMaze(char *path, char ***maze, int *numRows, int *numCols);
void debugGraphMazePath(struct Graph *graph, char **maze, int numRows, int numCols, struct LinkedListNode *pathStack);

// create a function to pretty print maze with an * in an specific position

void printMaze(char **maze, int numRows, int numCols, int row, int col) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {

            if (i == row && j == col && maze[i][j] == ' ') {
                printf("*");
            } else {
                printf("%c", maze[i][j]);
            }
        }
    }
}


int main(int argc, char *argv[]) {
    struct Graph *graph = createGraph();

    char **maze;
    int numRows, numCols;

    readMaze(argc >= 1 && argv[1] != NULL ? argv[1] : "./databases/L1.txt", &maze, &numRows, &numCols);

    int index = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (maze[i][j] == ' ') {
                addNode(&graph, index, i, j);
                // system("clear");
                // debugVertex(graph->vertices[index]);
                // printMaze(maze, numRows, numCols, i, j);
                // usleep(10000L);
                index++;
            }
        }
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (maze[i][j] == ' ') {
                // CIMA
                struct Vertex *vertex1 = peekNodeByCoordinates(graph, i, j);

                if (i - 1 >= 0 && maze[i][j] == ' ' && maze[i-1][j] == ' ') {
                    struct Vertex *vertex2 = peekNodeByCoordinates(graph, i-1, j);
                    addEdge(&graph, &vertex1, &vertex2);
                    addEdge(&graph, &vertex2, &vertex1);
                }

                // BAIXO
                if (i + 1 < numRows && maze[i][j] == ' ' && maze[i+1][j] == ' ') {
                    struct Vertex *vertex2 = peekNodeByCoordinates(graph, i+1, j);
                    addEdge(&graph, &vertex1, &vertex2);
                    addEdge(&graph, &vertex2, &vertex1);
                }

                // ESQUERDA
                if (j - 1 >= 0 && maze[i][j] == ' ' && maze[i][j-1] == ' ') {
                    struct Vertex *vertex2 = peekNodeByCoordinates(graph, i, j-1);
                    addEdge(&graph, &vertex1, &vertex2);
                    addEdge(&graph, &vertex2, &vertex1);
                }

                // DIREITA
                if (j + 1 < numCols && maze[i][j] == ' ' && maze[i][j+1] == ' ') {
                    struct Vertex *vertex2 = peekNodeByCoordinates(graph, i, j+1);
                    addEdge(&graph, &vertex1, &vertex2);
                    addEdge(&graph, &vertex2, &vertex1);
                }
            }
        }
    }

    struct LinkedListNode *pathStack = NULL;

    depthSearch(graph, 0, graph->vertices[graph->verticesAmount-1]->id, &pathStack);

    debugGraphMazePath(graph, maze, numRows, numCols, pathStack);

    // printf("Caminho: ");

    struct LinkedListNode *pathStackIterator = pathStack;

    // while (pathStackIterator != NULL) {
    //     printf("%d ", ((struct Vertex *) pathStackIterator->value)->id);
    //     pathStackIterator = pathStackIterator->next;
    // }

    // printf("\n");

    // Freeing memory
    for (int i = 0; i < numRows; i++) {
        free(maze[i]);
    }

    pathStackIterator = pathStack;

    while (pathStackIterator != NULL) {
        struct LinkedListNode *previousPathStackNode = pathStackIterator;
        pathStackIterator = pathStackIterator->next;
        free(previousPathStackNode);
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

void debugGraphMazePath(struct Graph *graph, char **maze, int numRows, int numCols, struct LinkedListNode *pathStack) {
    system("clear");

    struct LinkedListNode *pathStackIterator  = pathStack;

    while (pathStackIterator != NULL) {
        struct Vertex *vertex = (struct Vertex *) pathStackIterator->value;
        maze[vertex->x][vertex->y] = '*';
        pathStackIterator = pathStackIterator->next;
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {

            printf("%c", maze[i][j]);
        }
    }

    printf("\n");

    pathStackIterator  = pathStack;

    while (pathStackIterator != NULL) {
        struct Vertex *vertex = (struct Vertex *) pathStackIterator->value;
        maze[vertex->x][vertex->y] = ' ';
        pathStackIterator = pathStackIterator->next;
    }
}