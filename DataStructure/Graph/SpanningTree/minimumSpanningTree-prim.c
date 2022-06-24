// 최소신장트리-프림 알고리즘

// 1. 그래프와 내용이 빈 최소신장트리 준비
// 2. 그래프에서 임의의 정점을 시작 정점으로 선택, 최소 신장트리의 루트 노드로 삽입
// 3. 최소신장트리에 삽입되어 있는 정점들과 이 정점들의 모든 인접 정점 사이에 있는 간선의 가중치 조사
// 4. 간선 중에 가장 가중치가 작은 것을 골라 이 간선에 연결되어 있는 인접 정점을 최소 신장 트리에 삽입
// 5. 단, 새로 삽입되는 정점은 최소신장트리에 삽입 되어 있는 기존의 노드들과 사이클을 형성해서는 안됨
// 3,4,5의 과정을 반복하다가 최소신장트리가 그래프의 모든 정점을 연결하게 되면 알고리즘 종료
#include"Graph.h"
#include"Heap.h"
#define MAX_WEIGHT 36267
void prim(Graph* _pGraph, Vertex* _pStartVertex, Graph* _pPrimMST) {
	PQNode startNode = { _pStartVertex, 0 };						// 시작정점의 들어오는 간선은 없으므로 가중치 0
	PriorityQueue* PQ = PQ_createQueue(10);					// 최소 가중치를 가진 간선을 알아내기위한 우선순위 큐

	Vertex* currentVertex = NULL;									// 현재 다루고있는 정점을 저장할 변수
	Edge* currentEdge = NULL;										// 현재 다루고있는 간선을 저장할 변수

	int* weights = (int*)malloc(sizeof(int) * _pGraph->vertexCount);	// 해당 인덱스가 뜻하는 정점에게 들어오는 간선의 가중치 집합
																			// 그래프의 정점들을 한번에 관리하기 편하게 정점들이 가지고 인덱스값을 통해 배열에 추상화

	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);	// 정점들의 간선정보를 인덱스를 통해 쉽게 연결짓기 위해 만든 정점배열
	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);		// 해당 인덱스가 뜻하는 정점이 방문되었는지를 알수있는 배열 생성
	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);	// 해당 인덱스가 뜻하는 정점으로 들어오는 간선의 출처(간선의 from정보)를 저장
																							// 배열에는 인덱스당 1개밖에 데이터를 저장할 수 없으므로 자연스럽게 해당인덱스가 뜻하는 정점으로 들어오는 간선은 1개로 강제됨
																							// (한번 더 들어오면 간선의 가중치가 가장 낮은 간선정보로 갱신)
																							// 자신한테 들어오는 간선이 1개 이하라면 사이클이 형성 될 수 없음

	// 그래프가 가지고 있는 정점들을 최소신장트리에 옮김
	// 옮기는 과정에서 배열들 초기화
	int i = 0;
	currentVertex = _pGraph->vertices;														// 그래프의 헤드 정점을 현재정점으로 초기화
	while (currentVertex != NULL) {															// 그래프의 모든 정점을 돌면서
		Vertex* newVertex = createVertex(currentVertex->data);							// 그래프의 정점의 데이터를 복사해서
		addVertex(_pPrimMST, newVertex);									// 최소신장트리의 정점으로 추가

		// 배열 초기화
		MSTVertices[i] = newVertex;															// 최소신장트리의 정점들을 쉽게 접근하기위해 배열로 초기화
		weights[i] = MAX_WEIGHT;															// 처음 i번쨰 인덱스에 접근했을때 비교조건이 무조건 참이되게 최댓값 삽입
		fringes[i] = NULL;																	// 방문정보 false 초기화
		precedences[i] = NULL;																// 자신을 가리키는 정점 정보 NULL 초기화
		currentVertex = currentVertex->next;
		i++;
	}

	// 시작노드 큐에 삽입
	PQ_enQueue(PQ, startNode);
	weights[_pStartVertex->index] = 0;														// 시작정점에는 들어오는 간선이 없으므로 0
	// 최소신장트리에 넣을 간선정보배열 저장
	while (!isEmpty(PQ)) {																// 큐가 빌 때까지(빈다면 정렬종료를 뜻함) 
		PQNode popped;																		
		PQ_deQueue(PQ, &popped);													// 가중치가 가장 낮은 정점 가져오기
		currentVertex = (Vertex*)popped.Data;												// 큐의 노드를 정점 자료형으로 전환
		fringes[currentVertex->index] = currentVertex;										// 현재 정점 방문처리
		currentEdge = currentVertex->adgacenctList;											// 현재 정점의 간선정보들 중 헤드간선정보 가져오기
		while (currentEdge != NULL) {														// 모든 간선들을 돌면서
			Vertex* targetVertex = currentEdge->target;										// 현재 간선의 목적지정점 정보를 가져오기
			if (fringes[targetVertex->index] == NULL && currentEdge->weight < weights[targetVertex->index]) {	
				// 현재 간선의 목적지정점이 이미 방문되지 않았거나(큐에서 한번도 꺼내지 않았거나), 현재 간선의 가중치가 이미 목적지정점을 가리키고있는 간선의 가중치보다 작다면 if문 실행
				PQNode newNode = { targetVertex , currentEdge->weight };					// 정점을 우선순위큐의 노드로 포장
				PQ_enQueue(PQ, newNode);													// 큐에 추가

				weights[targetVertex->index] = currentEdge->weight;							// 목적지정점을 가리키는 간선정보배열들에 현재 간선정보를 갱신
				precedences[targetVertex->index] = currentEdge->from;
			}
			currentEdge = currentEdge->next;
		}
	}

	// 간선정보들을 저장한 배열들을 바탕으로 최소신장트리의 간선 추가

	for (int i = 0; i < _pGraph->vertexCount; i++) {
		int fromIndex, toIndex;	

		if (precedences[i] == NULL) {	// 시작정점은 들어오는 정점의 정보가 없으므로 걸러내기위한 코드
			continue;
		}
		fromIndex = precedences[i]->index;		// 추가할 간선의 from멤버에 넣을 정점에 접근할 인덱스
		toIndex = i;

		addEdge(MSTVertices[fromIndex], createEdge(MSTVertices[fromIndex], MSTVertices[toIndex], weights[i]));

		addEdge(MSTVertices[toIndex], createEdge(MSTVertices[toIndex], MSTVertices[fromIndex], weights[i]));
	}
	free(fringes);
	free(precedences);
	free(MSTVertices);

	PQ_destroyQueue(PQ);
}