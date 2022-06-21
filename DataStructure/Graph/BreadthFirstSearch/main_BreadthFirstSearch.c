#include "LinkedQueue.h"

void breadthFirstSearch(Vertex* _pVertex, LinkedQueue* _pQueue) {
	_pVertex->visited = Visited;								// ���� ���� �湮�� ����
	enQueue(_pQueue, _pVertex);							// ���� 0�� ���� ť�� �ֱ�
	while (!isEmpty(_pQueue)) {									// ť�� ����°� �ƴϸ� �ݺ�
		Vertex* pVertex = deQueue(_pQueue)->data;						// ���� ���ܿ� �ִ� ���� ������
		printf("%d ", pVertex->data);
		Edge* pEdge = pVertex->adgacenctList;					// ���� ������ �������ִ� ���� ����Ʈ
		while (pEdge != NULL) {
			if (pEdge->target->visited == NotVisited) {			// ������ ����Ű�� ���� ������ �ѹ��� �湮���� �ʾҴٸ�
				pEdge->target->visited = Visited;				// ������ ����Ű�� ���� �湮�� ���� �ϰ� ť�� �ֱ�
				enQueue(_pQueue, pEdge->target);
			}
			pEdge = pEdge->next;								// ���� �������� ����
		}
	}
}


int main() {
	
	Graph* G = createGraph();
	Vertex* V1 = createVertex(1);
	Vertex* V2 = createVertex(2);
	Vertex* V3 = createVertex(3);
	Vertex* V4 = createVertex(4);
	Vertex* V5 = createVertex(5);
	Vertex* V6 = createVertex(6);
	Vertex* V7 = createVertex(7);


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


	LinkedQueue* Queue = createQueue();

	breadthFirstSearch(G->vertices, Queue);

	destroyQueue(Queue);
	destroyGraph(G);

	printf("\n���α׷��� ����˴ϴ�.");
}


