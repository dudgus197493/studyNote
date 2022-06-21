#include "LinkedQueue.h"

void breadthFirstSearch(Vertex* _pVertex, LinkedQueue* _pQueue) {
	_pVertex->visited = Visited;								// 시작 정점 방문함 갱신
	enQueue(_pQueue, _pVertex);							// 깊이 0의 정점 큐에 넣기
	while (!isEmpty(_pQueue)) {									// 큐가 빈상태가 아니면 반복
		Vertex* pVertex = deQueue(_pQueue)->data;						// 가장 전단에 있는 정점 꺼내기
		printf("%d ", pVertex->data);
		Edge* pEdge = pVertex->adgacenctList;					// 꺼낸 정점이 가지고있는 간선 리스트
		while (pEdge != NULL) {
			if (pEdge->target->visited == NotVisited) {			// 간선이 가리키는 다음 정점이 한번도 방문하지 않았다면
				pEdge->target->visited = Visited;				// 간선이 가리키는 정점 방문함 갱신 하고 큐에 넣기
				enQueue(_pQueue, pEdge->target);
			}
			pEdge = pEdge->next;								// 다음 간선으로 갱신
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

	printf("\n프로그램이 종료됩니다.");
}


