#include "Graph.h"
#include "DisjointSet.h"
#include "Heap.h"

void Kruskal(Graph* _pGraph, Graph* _pMST) {
	Vertex* currentVertex = NULL;
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);

	DisjointSet** vertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * _pGraph->vertexCount);

	PriorityQueue* PQ = PQ_createQueue(10);

	currentVertex = _pGraph->vertices;
	int i = 0;
	while (currentVertex != NULL) {
		Edge* currentEdge;

		vertexSet[i] = createNode(currentVertex);
		MSTVertices[i] = createVertex(currentVertex->data);
		addVertex(_pMST, MSTVertices[i]);

		currentEdge = currentVertex->adgacenctList;

		while (currentEdge != NULL) {
			PQNode newNode = { currentEdge, currentEdge->weight };
			PQ_enQueue(PQ, newNode);

			currentEdge = currentEdge->next;
		}
		currentVertex = currentVertex->next;
		i++;
	}

	while (!isEmpty(PQ)) {
		Edge* currentEdge;
		int fromIndex;
		int toIndex;
		PQNode popped;

		PQ_deQueue(PQ, &popped);
		currentEdge = (Edge*)popped.Data;

		printf("%c - %c : %d\n", currentEdge->from->data, currentEdge->target->data, currentEdge->weight);

		fromIndex = currentEdge->from->index;
		toIndex = currentEdge->target->index;
		if (FindSet(vertexSet[fromIndex]) != FindSet(vertexSet[toIndex])) {
			addEdge(MSTVertices[fromIndex], createEdge(MSTVertices[fromIndex], MSTVertices[toIndex], currentEdge->weight));

			addEdge(MSTVertices[toIndex], createEdge(MSTVertices[toIndex], MSTVertices[fromIndex], currentEdge->weight));

			UnionSet(vertexSet[fromIndex], vertexSet[toIndex]);
			
		}
	}
	for (int i = 0; i < _pGraph->vertexCount; i++) {
		destroyNode(vertexSet[i]);
	}

	free(vertexSet);
	free(MSTVertices);
}