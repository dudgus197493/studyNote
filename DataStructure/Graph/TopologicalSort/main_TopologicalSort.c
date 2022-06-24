#include "LinkedList.h"

void TopologicalSort(Vertex* _pVertex, LinkedList* _ppList);


int main() {
	
	LinkedList list;
	InitList(&list);

	Graph* Graph = createGraph();

	Vertex* A = createVertex('A');
	Vertex* B = createVertex('B');
	Vertex* C = createVertex('C');
	Vertex* D = createVertex('D');
	Vertex* E = createVertex('E');
	Vertex* F = createVertex('F');
	Vertex* G = createVertex('G');
	Vertex* H = createVertex('H');

	addVertex(Graph, A);
	addVertex(Graph, B);
	addVertex(Graph, C);
	addVertex(Graph, D);
	addVertex(Graph, E);
	addVertex(Graph, F);
	addVertex(Graph, G);
	
	addEdge(A, createEdge(A, C, 0));
	addEdge(A, createEdge(A, D, 0));
	
	addEdge(B, createEdge(B, C, 0));
	addEdge(B, createEdge(B, E, 0));

	addEdge(C, createEdge(C, F, 0));

	addEdge(D, createEdge(D, F, 0));
	addEdge(D, createEdge(D, G, 0));

	addEdge(E, createEdge(E, G, 0));

	addEdge(F, createEdge(F, H, 0));

	addEdge(G, createEdge(G, H, 0));


	// 위상 정렬
	TopologicalSort(Graph->vertices, &list);
	
	printf("Topological Sort Result : ");

	while (list.pHeadNode != NULL) {
		printf("%c ", list.pHeadNode->Data->data);
		list.pHeadNode = list.pHeadNode->pNextNode;
	}
	printf("\n");

	destroyGraph(Graph);
	printf("그래프가 소멸되었습니다.");
	return 0;
}


