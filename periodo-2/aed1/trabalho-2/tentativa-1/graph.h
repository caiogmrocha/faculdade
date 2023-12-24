#ifndef DATASOURCE_H
#define DATASOURCE_H

// Vértice representado por uma lista encadeada de adjacências
struct Vertex {
    int id;
    struct Vertex *next;
};

// Grafo representado por uma matriz de adjacência de vértices
struct Graph {
    int amount;
    struct Vertex *vertices;
};

void initGraph(struct Graph **graph);
void addVertex(struct Graph **graph, int id);
void addEdge(struct Vertex *vertex, int id);
void printGraph(struct Graph *graph);

#endif