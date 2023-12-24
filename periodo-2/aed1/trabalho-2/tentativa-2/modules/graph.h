#ifndef H_GRAPH
#define H_GRAPH

#include "linkedlist.h"

/**
 * TAD que representa um grafo.
 * 
 * @param vertices lista de adjacências.
 * @param amount quantidade de vértices.
*/
struct Graph {
    struct LinkedListNode **vertices;
    int amount;
};

struct Graph *createGraph();
void addNode(struct Graph **graph, int value);
void addEdge(struct Graph **graph, struct LinkedListNode *vertex1, struct LinkedListNode *vertex2);

#endif