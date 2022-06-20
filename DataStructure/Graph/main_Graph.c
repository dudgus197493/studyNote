#include "Graph.h"

int main() {
	Graph* G = createGraph();

	Vertex* V1 = createVertex('1');
	Vertex* V2 = createVertex('2');
	Vertex* V3 = createVertex('3');
	Vertex* V4 = createVertex('4');
	Vertex* V5 = createVertex('5');

	addVertex(G, V1);
	addVertex(G, V2);
	addVertex(G, V3);
	addVertex(G, V4);
	addVertex(G, V5);
	
	addEdge(V1, createEdge(V1, V2, 0));
	addEdge(V1, createEdge(V1, V3, 0));
	addEdge(V1, createEdge(V1, V4, 0));
	addEdge(V1, createEdge(V1, V5, 0));

	addEdge(V2, createEdge(V2, V1, 0));
	addEdge(V2, createEdge(V2, V3, 0));
	addEdge(V2, createEdge(V2, V5, 0));
	
	addEdge(V3, createEdge(V3, V1, 0));
	addEdge(V3, createEdge(V3, V2, 0));

	addEdge(V4, createEdge(V4, V1, 0));
	addEdge(V4, createEdge(V4, V5, 0));

	addEdge(V5, createEdge(V5, V1, 0));
	addEdge(V5, createEdge(V5, V2, 0));
	addEdge(V5, createEdge(V5, V4, 0));
	
	printGraph(G);

	destroyGraph(G);
	printf("�׷����� �Ҹ�Ǿ����ϴ�.");
	return 0;
}