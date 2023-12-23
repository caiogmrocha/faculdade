#ifndef DATASOURCE_H
#define DATASOURCE_H

// Vértice representado por uma lista encadeada de adjacências
struct Vertex {
    int id;
    struct Vertex *next;
};

// Grafo representado por uma matriz de adjacência de vértices
struct Graph {
    struct Vertex *vertices;
    int amount;
};

void initGraph(struct Graph **graph, int amount);
void addEdge(struct Vertex *vertex, int id);
void printGraph(struct Graph *graph);

#endif