#ifndef H_DEPTH_SEARCH
#define H_DEPTH_SEARCH

#include "graph.h"

void depthSearch(struct Graph *graph, int startVertexId, int endVertexId, struct LinkedListNode **pathStack);

#endif