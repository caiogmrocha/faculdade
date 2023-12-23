#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "graph.h"

// Vértice representado por uma lista encadeada de adjacências
struct Vertex {
    int id;
    int row;
    int col;
    int visited;
    struct Vertex *next;
};

// Grafo representado por uma matriz de adjacência de vértices
struct Graph {
    int amount;
    struct Vertex *vertices;
};

// Pilha representada por uma lista encadeada de vértices
// struct Stack {
//     struct Vertex *vertex;
//     struct Stack *next;
// };

void initGraph(struct Graph **graph);
void addVertex(struct Graph **graph, int id, int row, int col);
void addEdge(struct Vertex *vertex1, struct Vertex *vertex2);
void printGraph(struct Graph *graph);

void readLabyrinthFile(char *path, char ***labirynth, int *numRows);
void assignGraphVertices(struct Graph *graph, char **labirynth, int numRows);
void linkGraphVertices(struct Graph *graph, char **labirynth, int numRows);

// void initStack(struct Stack **stack);
// void push(struct Stack **stack, struct Vertex *vertex);
// struct Vertex *pop(struct Stack **stack);

int main() {
    struct Graph *graph;
    struct Vertex *visitedVertices;
    
    initGraph(&graph);

    char **labirynth = NULL;
    int numRows = 0;

    readLabyrinthFile("./requirements/L1.txt", &labirynth, &numRows);
    assignGraphVertices(graph, labirynth, numRows);
    linkGraphVertices(graph, labirynth, numRows);

    printGraph(graph);

    return 0;
}

void initGraph(struct Graph **graph) {
    *graph = (struct Graph *) malloc(sizeof(struct Graph));
    (*graph)->amount = 0;
    (*graph)->vertices = NULL;
}

void addVertex(struct Graph **graph, int id, int row, int col) {
    (*graph)->amount += 1;
    (*graph)->vertices = (struct Vertex *) realloc((*graph)->vertices, (*graph)->amount * sizeof(struct Vertex));

    (*graph)->vertices[(*graph)->amount-1].id = id;
    (*graph)->vertices[(*graph)->amount-1].row = row;
    (*graph)->vertices[(*graph)->amount-1].col = col;
    (*graph)->vertices[(*graph)->amount-1].visited = 0;
    (*graph)->vertices[(*graph)->amount-1].next = NULL;
}

void addEdge(struct Vertex *vertex1, struct Vertex *vertex2) {
    struct Vertex *newVertex = (struct Vertex *) malloc(sizeof(struct Vertex));
    if (!newVertex) {
        printf("Failed to allocate memory for new vertex.\n");
        exit(1);
    }

    // Copy the data from vertex2 to the new vertex
    *newVertex = *vertex2;
    newVertex->next = NULL;

    struct Vertex *iterator = vertex1;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }

    iterator->next = newVertex;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->amount; i++) {

        struct Vertex *iterator = &(graph->vertices[i]);

        printf("Vértice %d [%d, %d]: ", graph->vertices[i].id, graph->vertices[i].row, graph->vertices[i].col);

        iterator = iterator->next;

        printf("[ ");

        while (iterator != NULL) {
            if (iterator->next == NULL) {
                printf("[%d, %d]", iterator->row, iterator->col);
            } else {
                printf("[%d, %d], ", iterator->row, iterator->col);
            }

            iterator = iterator->next;
        }

        printf(" ]\n");
    }
}

void readLabyrinthFile(char *path, char ***labirynth, int *numRows) {
    char input[160];
    FILE *arquivo = fopen(path, "r");
    int row = 0;

    while (fgets(input, sizeof(input), arquivo) != NULL) {
        *labirynth = (char **) realloc(*labirynth, (row + 1) * sizeof(char *));
        (*labirynth)[row] = (char *) malloc(strlen(input)+1);
        strcpy((*labirynth)[row], input);
        row++;
    }

    fclose(arquivo);

    *numRows = row;
}

void assignGraphVertices(struct Graph *graph, char **labirynth, int numRows) {
    int row, col, vertexId = 0;

    for (row = 0; row < numRows; row++) {
        int numCols = strlen(labirynth[row]) - 1;
        
        for (col = 0; col < numCols; col++) {
            if (labirynth[row][col] == ' ') { // é um vértice
                addVertex(&graph, vertexId, row, col);

                vertexId++;
            }
        }
    }
}

void linkGraphVertices(struct Graph *graph, char **labirynth, int numRows) {
    printf("amount: %d\n", graph->amount);

    for (int i = 0; i < graph->amount; i++) {
        struct Vertex *iterator = &(graph->vertices[i]);
        int numCols = strlen(labirynth[iterator->row]) - 1;
        

        for (int j = 0; j < graph->amount; j++) {
            if (i != j) {
                struct Vertex *iterator2 = &(graph->vertices[j]);

                // 1. Check and assign adjacency to the left.
                if (iterator->col != 0 && iterator->row == iterator2->row && iterator->col - 1 == iterator2->col) {
                    addEdge(iterator, iterator2);
                }

                // 2. Check and assign adjacency to the right.
                if (iterator->col != numCols && iterator->row == iterator2->row && iterator->col + 1 == iterator2->col) {
                    addEdge(iterator, iterator2);
                }

                // 3. Check and assign adjacency above.
                if (iterator->row != 0 && iterator->col == iterator2->col && iterator->row - 1 == iterator2->row) {
                    addEdge(iterator, iterator2);
                }

                // 4. Check and assign adjacency below.
                if (iterator->row != numRows - 1 && iterator->col == iterator2->col && iterator->row + 1 == iterator2->row) {
                    addEdge(iterator, iterator2);
                }
            }
        }
    }
}

// void initStack(struct Stack **stack) {
//     *stack = (struct Stack *) malloc(sizeof(struct Stack));
//     (*stack)->vertex = NULL;
//     (*stack)->next = NULL;
// }

// void push(struct Stack **stack, struct Vertex *vertex) {
//     struct Stack *newStack = (struct Stack *) malloc(sizeof(struct Stack));
//     newStack->vertex = vertex;
//     newStack->next = *stack;
//     *stack = newStack;
// }

// struct Vertex *pop(struct Stack **stack) {
//     struct Stack *aux = *stack;
//     struct Vertex *vertex = aux->vertex;
//     *stack = aux->next;
//     free(aux);
//     return vertex;
// }
