#include "Graph.h"
#include "Heap.h"
// 최소 신장 트리
// 모든 정점을 연겨, 단 서클이 생성되지 않게
// 총 비용이 가장 적게

// 구현
// 1. 프림 알고리즘
// 정점하나에 들어오는 간선이 한개 이상있으면 사이클이 형성될 수 있다.
// 그러므로 weights, precedences 배열을 선언하여 해당 정점으로 들어오는 간선의 정보를 가장낮은 가중치(weights)를 갖은 간선 하나만을 저장하도록 계속 갱신한다.


#define MAX_WEIGHT 36267
void prim(Graph* _pGraph, Vertex* _pStartVertex, Graph* _pMST) {
	PQNode startNode = { _pStartVertex, 0 };					// 시작정점을 큐 노드로 생성
	PriorityQueue* PQ = PQ_createQueue(10);				// 간선들을 담을 우선순위 큐 생성

	Vertex* currentVertex = NULL;
	Edge* currentEdge = NULL;

	int* weights = (int*)malloc(sizeof(_pGraph->vertexCount));	// 가중치들을 담을 배열을 생성(크기는 그래프의 정점 수)
																// 정점들의 인덱스안에 해당정점으로 올때의 비용(가중치)이 저장됨
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);

	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);	// 해당정점이 방문됐는지 확인(인덱스안에 정점이있으면 그 정점은 방문완료한 정점)

	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount); // 해당정점이 어디로부터 왔는지
	
	currentVertex = _pGraph->vertices;
	int i = 0;
	while (currentVertex != NULL) {										// 그래프의 정점정보를 하나하나 불러와서
		Vertex* newVertex = createVertex(currentVertex->data);			// 복사한 후 최소신장그래프의 정점으로 추가
		addVertex(_pMST, newVertex);

		fringes[i] = NULL;												
		precedences[i] = NULL;
		MSTVertices[i] = newVertex;
		weights[i] = MAX_WEIGHT;
		currentVertex = currentVertex->next;
		i++;
	}

	PQ_enQueue(PQ, startNode);											// 시작정점 큐에 삽입

	weights[_pStartVertex->index] = 0;									// 시작정점 인덱스자리에 0으로 초기화

	while (!isEmpty(PQ)) {												// 큐가 빌 때 까지
		PQNode popped;
		
		PQ_deQueue(PQ, &popped);										// 우선순위(weight)가 가장 작은 노드(정점) pop
		currentVertex = (Vertex*)popped.Data;

		fringes[currentVertex->index] = currentVertex;					// 방문처리

		currentEdge = currentVertex->adgacenctList;						// 현재 정점이 가진 간선 리스트 가져오기
		while (currentEdge != NULL) {									// 간선리스트가 NULL일때까지 모든 간선 체크
			Vertex* targetVertex = currentEdge->target;					// 간선의 타겟정점 가져오기

			if (fringes[targetVertex->index] == NULL && currentEdge->weight < weights[targetVertex->index]) {
				PQNode newNode = { targetVertex, currentEdge->weight };
				PQ_enQueue(PQ, newNode);

				precedences[targetVertex->index] = currentEdge->from;
				weights[targetVertex->index] = currentEdge->weight;
			}
			currentEdge = currentEdge->next;
		}
	}

	for (int i = 0; i < _pGraph->vertexCount; i++) {
		int fromIndex, toIndex;

		if (precedences[i] == NULL) {
			continue;
		}
		fromIndex = precedences[i]->index;
		toIndex = i;

		addEdge(MSTVertices[fromIndex], createEdge(MSTVertices[fromIndex], MSTVertices[toIndex], weights[i]));

		addEdge(MSTVertices[toIndex], createEdge(MSTVertices[toIndex], MSTVertices[fromIndex], weights[i]));	// 무방향성이므로 양쪽을 가리키는 간선 정보를 만들어야함

	}
	free(fringes);
	free(precedences);
	free(MSTVertices);
	/*free(weights);*/
	H_destroyHeap(PQ);
}

// 2. 크루스칼 알고리즘