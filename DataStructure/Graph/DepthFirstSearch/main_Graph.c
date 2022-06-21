#include "Graph.h"

void depthFirstSearch(Vertex* _pVertex);


int main() {
	
	Graph* G = createGraph();

	Vertex* V1 = createVertex('1');
	Vertex* V2 = createVertex('2');
	Vertex* V3 = createVertex('3');
	Vertex* V4 = createVertex('4');
	Vertex* V5 = createVertex('5');
	Vertex* V6 = createVertex('6');
	Vertex* V7 = createVertex('7');

	addVertex(G, V1);
	addVertex(G, V2);
	addVertex(G, V3);
	addVertex(G, V4);
	addVertex(G, V5);
	addVertex(G, V6);
	addVertex(G, V7);
	
	addEdge(V1, createEdge(V1, V2, 0));
	addEdge(V1, createEdge(V1, V3, 0));
	
	addEdge(V2, createEdge(V2, V4, 0));
	addEdge(V2, createEdge(V2, V5, 0));

	addEdge(V3, createEdge(V3, V4, 0));
	addEdge(V3, createEdge(V3, V6, 0));

	addEdge(V4, createEdge(V4, V5, 0));
	addEdge(V4, createEdge(V4, V7, 0));

	addEdge(V5, createEdge(V5, V7, 0));

	addEdge(V6, createEdge(V6, V7, 0));

	/*printGraph(G);*/

	depthFirstSearch(G->vertices);

	destroyGraph(G);
	printf("그래프가 소멸되었습니다.");
	return 0;
}


