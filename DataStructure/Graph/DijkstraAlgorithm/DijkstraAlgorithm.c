// 다익스트라 알고리즘
// 다익스트라 알고리즘은 사이클이 없는 방향성 그래픙 한해서만 사용할 수 있음


// 기본적인 골격은 프림 알고리즘과 유사함
// 프림 알고리즘은 weights 배열에 간선의 가중치만 저장했음.
// 다익스트라 알고리즘의 weights배열에는 간선의 from정점의 인덱스에 배열값과 target정점의 인덱스 배열값의 합이 저장됨
// (해당 정점에 도달하기까지 간선의 가중치의 총합이 저장)

#include "Graph.h"
#include "Heap.h"

#define MAX_WEIGHT 36267
void Dijkstra(Graph* _pGraph, Vertex* _pStartVertex, Graph* _pShortestPath) {
	PQNode startNode = { _pStartVertex, 0 };
	PriorityQueue* PQ = PQ_createQueue(10);

	Vertex* currentVertex = NULL;
	Edge* currentEdge = NULL;

	int* weights = (int*)malloc(sizeof(int) * _pGraph->vertexCount);						// 최소 경로를 저장하기 위한 배열
	Vertex** shortestPathVerices = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);// 최소경로 그래프의 정점들 집합
	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);			// 정점들의 방문여부를 확인하기 위한 배열
	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);		// 정점들이 사이클을 형성하지 않게 하기위한 배열

	currentVertex = _pGraph->vertices;														// 시작정점부터
	int i = 0;
	while (currentVertex != NULL) {															// 모든 정점을
		Vertex* newVertex = createVertex(currentVertex->data);							// 데이터를 복사해서 
		addVertex(_pShortestPath, newVertex);								// 최단경로그래프의 정점으로 추가

		fringes[i] = NULL;																	// 현제 인덱스 초기화
		precedences[i] = NULL;
		weights[i] = MAX_WEIGHT;
		shortestPathVerices[i] = newVertex;

		currentVertex = currentVertex->next;												// 다음 정점으로
		i++;																				// 다음 인덱스로
	}

	PQ_enQueue(PQ, startNode);													// 시작노드 큐에 추가
	weights[_pStartVertex->index] = 0;														// 시작노드는 거리가 0

	while (!isEmpty(PQ)) {																// 큐가 빌 때 까지
		PQNode popped;
		PQ_deQueue(PQ, &popped);
		currentVertex = (Vertex*)popped.Data;
		fringes[currentVertex->index] = currentVertex;										// 큐에서 꺼냈으면 방문 처리

		currentEdge = currentVertex->adgacenctList;											// 방문한 정점의 간선정보들을 가져옴
		while (currentEdge != NULL) {														// 모든 간선을 돌면서
			Vertex* targetVertex = currentEdge->target;
			if (fringes[targetVertex->index] == NULL && weights[currentVertex->index] + currentEdge->weight < weights[targetVertex->index]) {
				// 목적지 정점이 아직 방문되지 않았고, 지금까지 온 경로의 거리가 저장되있던 목적지의 경로보다 작으면 들어옴
				PQNode newNode = { targetVertex, currentEdge->weight };
				PQ_enQueue(PQ, newNode);

				precedences[targetVertex->index] = currentEdge->from;									// from 정점을 precedences배열에 저장				
				weights[targetVertex->index] = weights[currentVertex->index] + currentEdge->weight;		// 현재 경로의 길이를 저장
				printf("currentEdge %c->%c : weights %d\n", currentEdge->from->data, currentEdge->target->data, weights[targetVertex->index]);
			}
			currentEdge = currentEdge->next;														// 다음 정점으로
		}
	}


	for (i = 0; i < _pGraph->vertexCount; i++) {

		if (precedences[i] == NULL) {																	// 시작정점은 from이 NULL이므로 건너뜀
			continue;
		}
		int fromIndex = precedences[i]->index;
		int toIndex = i;

		addEdge(shortestPathVerices[fromIndex], createEdge(shortestPathVerices[fromIndex], shortestPathVerices[toIndex], weights[i]));
	}
	free(fringes);
	free(precedences);
	free(shortestPathVerices);
	PQ_destroyQueue(PQ);
}