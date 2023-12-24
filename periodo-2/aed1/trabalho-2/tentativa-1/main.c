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
struct Stack {
    struct Vertex *vertex;
    struct Stack *next;
};

void initGraph(struct Graph **graph);
void addVertex(struct Graph **graph, int id, int row, int col);
void addEdge(struct Vertex *vertex1, struct Vertex *vertex2);
void debugGraph(struct Graph *graph);

void readLabyrinthFile(char *path, char ***labirynth, int *numRows);
void assignGraphVertices(struct Graph *graph, char **labirynth, int numRows);
void linkGraphVertices(struct Graph *graph, char **labirynth, int numRows);
struct Stack *solveLabyrinth(struct Graph *graph);
void printSolution(char **labyrinth, struct Stack *solution, int numRows);

void initStack(struct Stack **stack);
void push(struct Stack **stack, struct Vertex *vertex);
struct Vertex *pop(struct Stack **stack);

int main() {
    struct Graph *graph;
    struct Vertex *visitedVertices;
    
    initGraph(&graph);

    char **labirynth = NULL;
    int numRows = 0;

    readLabyrinthFile("./requirements/L1.txt", &labirynth, &numRows);
    assignGraphVertices(graph, labirynth, numRows);
    linkGraphVertices(graph, labirynth, numRows);

    // debugGraph(graph);

    struct Stack *solution = solveLabyrinth(graph);
    printSolution(labirynth, solution, numRows);

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
    struct Vertex *iterator = vertex1;

    while (iterator->next != NULL) {
        iterator = iterator->next;
    }

    iterator->next = vertex2;
}

void debugGraph(struct Graph *graph) {
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
    for (int i = 0; i < graph->amount; i++) {
        struct Vertex *iterator = &(graph->vertices[i]);
        int numCols = strlen(labirynth[iterator->row]) - 1;

        for (int j = 0; j < graph->amount; j++) {
            if (i != j) {
                struct Vertex *iterator2 = &(graph->vertices[j]);

                // 1. Check and assign adjacency to the right.
                if (iterator->col != numCols && iterator->row == iterator2->row && iterator->col + 1 == iterator2->col) {
                    addEdge(iterator, iterator2);
                }

                // 2. Check and assign adjacency below.
                if (iterator->row != numRows - 1 && iterator->col == iterator2->col && iterator->row + 1 == iterator2->row) {
                    addEdge(iterator, iterator2);
                }
            }
        }
    }
}

// Stack functions
void initStack(struct Stack **stack) {
    *stack = (struct Stack *) malloc(sizeof(struct Stack));
    (*stack)->vertex = NULL;
    (*stack)->next = NULL;
}

void push(struct Stack **stack, struct Vertex *vertex) {
    struct Stack *newStack = (struct Stack *) malloc(sizeof(struct Stack));
    newStack->vertex = vertex;
    newStack->next = *stack;
    *stack = newStack;
}

struct Vertex *pop(struct Stack **stack) {
    struct Stack *aux = *stack;
    struct Vertex *vertex = aux->vertex;
    *stack = aux->next;
    free(aux);
    return vertex;
}

struct Stack *solveLabyrinth(struct Graph *graph) {
    struct Stack *stack;
    struct Stack *solution;
    initStack(&stack);
    initStack(&solution);

    struct Vertex *start = &(graph->vertices[0]);
    struct Vertex *end = &(graph->vertices[graph->amount-1]);

    push(&stack, start);

    while (1) {
        struct Vertex *vertex = pop(&stack);

        if (vertex == NULL) {
            printf("Não há caminho possível para a saída.\n");
            break;
        }

        if (vertex->id == end->id) {
            // Push the end vertex onto the solution stack
            push(&solution, vertex);
            printf("Caminho encontrado!\n");
            break;
        }

        if (vertex->visited == 0) {
            vertex->visited = 1;

            struct Vertex *iterator = vertex->next;
            int backtrack = 1;

            while (iterator != NULL) {
                if (iterator->visited == 0) {
                    push(&stack, iterator);
                    backtrack = 0;
                }

                iterator = iterator->next;
            }

            // If we don't need to backtrack, push the current vertex onto the solution stack
            if (!backtrack) {
                push(&solution, vertex);
            }
        }
    }

    return solution; // Corrigido para retornar a pilha de solução
}


void printSolution(char **labyrinth, struct Stack *solution, int numRows) {
    // Modify the labyrinth according to the solution path
    struct Stack *iterator = solution;

    while (iterator != NULL) {
        if (iterator->vertex != NULL) {
            labyrinth[iterator->vertex->row][iterator->vertex->col] = '*';
        }
        iterator = iterator->next;
    }

    // Print the labyrinth
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < strlen(labyrinth[i]); j++) {
            printf("%c", labyrinth[i][j]);
        }
        // printf("\n");
    }
}