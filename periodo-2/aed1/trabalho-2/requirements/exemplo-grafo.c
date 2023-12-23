#include <stdio.h>
#include <stdlib.h>

//estrutura para representar um vértice do grafo
typedef struct vertex{
	int v;
	struct vertex *next;
}vertice;

typedef struct{
	vertice *vertices;
	int n;
}graph;	

int *visited;
graph grafo;

void createGraph(int n, graph *grafo);
void insertEdge(vertice *v, int v2);
void recursiveDepthSearch(graph *grafo, int n, int initial);

//exemplos de criação de dois grafos
void grafo1(graph grafo);
void grafo2(graph grafo);

int main(){
	
	int n = 5;
	graph grafo;
	createGraph(n, &grafo);
	grafo2(grafo);
	int initial = 0;
	visited = (int *) malloc(sizeof(int)*n);

	for(int i=0; i<n; i++)
		visited[i] = 0;
		
	printf("\n\nRecursive Depth First Search: \n\n");
	printf("%d ", initial);
	visited[initial] = 1;
	recursiveDepthSearch(&grafo, n, initial);
	
	free(visited);
}

void grafo1(graph grafo){
	
	insertEdge(&grafo.vertices[0], 1);	
	insertEdge(&grafo.vertices[0], 2);
	insertEdge(&grafo.vertices[1], 0);	
	insertEdge(&grafo.vertices[1], 2);
	insertEdge(&grafo.vertices[2], 0);	
	insertEdge(&grafo.vertices[2], 1);
	insertEdge(&grafo.vertices[2], 3);	
	insertEdge(&grafo.vertices[2], 4);	
	insertEdge(&grafo.vertices[2], 5);	
	insertEdge(&grafo.vertices[2], 6);
	insertEdge(&grafo.vertices[3], 2);		
	insertEdge(&grafo.vertices[3], 4);		
	insertEdge(&grafo.vertices[4], 2);
	insertEdge(&grafo.vertices[4], 3);
	insertEdge(&grafo.vertices[5], 2);
	insertEdge(&grafo.vertices[6], 2);
}

void grafo2(graph grafo){	
	insertEdge(&grafo.vertices[0], 1);	
	insertEdge(&grafo.vertices[0], 2);
	insertEdge(&grafo.vertices[0], 3);
	insertEdge(&grafo.vertices[1], 0);
	insertEdge(&grafo.vertices[1], 4);
	insertEdge(&grafo.vertices[2], 0);
	insertEdge(&grafo.vertices[2], 4);
	insertEdge(&grafo.vertices[3], 0);
	insertEdge(&grafo.vertices[3], 4);
}

void recursiveDepthSearch(graph *grafo, int n, int initial){
	
	struct vertex atual = grafo->vertices[initial];
	struct vertex *vizinho = atual.next;

	while(vizinho != NULL){
		if(!visited[vizinho->v]){
			visited[vizinho->v] = 1;
			printf("%d ", vizinho->v);
			recursiveDepthSearch(grafo, n, vizinho->v);
		}
		vizinho = vizinho->next;
	};
}

void insertEdge(vertice *v, int id){
	vertice *novo = (vertice *) malloc(sizeof(vertice));
	novo->v = id;
	novo->next = NULL;
	struct vertex *temp = v;
	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = novo;
}

void createGraph(int n, graph *grafo){
	grafo->vertices = (vertice *) malloc (sizeof(vertice) * n);
	for(int i=0; i<n ; i++){
		grafo->vertices[i].v = i;
		grafo->vertices[i].next = NULL;
	}
}