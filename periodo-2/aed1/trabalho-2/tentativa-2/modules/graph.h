#ifndef H_GRAPH
#define H_GRAPH

#include "linkedlist.h"

struct Vertex {
    int id;
    int x;
    int y;
    int visited;
    int edgesAmount;
    struct Vertex *edgesArray;
};

struct Graph {
    int verticesAmount;
    struct Vertex **vertices;
};

struct Graph *createGraph();
void addNode(struct Graph **graph, int id, int x, int y);
struct Vertex *peekNode(struct Graph *graph, int x, int y);
void addEdge(struct Graph **graph, struct Vertex *vertex1, struct Vertex *vertex2);
void debugGraph(struct Graph *graph);
void debugVertex(struct Vertex *vertex);
void freeGraph(struct Graph *graph);

#endif