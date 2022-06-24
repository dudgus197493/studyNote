#include "Graph.h"

Graph* createGraph()
{
	Graph* newGraph = (Graph*)malloc(sizeof(Graph));	// 그래프 크기의 자동메모리 할당
	newGraph->vertices = NULL;								// 헤드정점의 포인터 NULL초기화
	newGraph->vertexCount = 0;								// 정점의 갯수 0 초기화;


	return newGraph;
}

void destroyGraph(Graph* _pGraph)
{
	while (_pGraph->vertices != NULL) {
		Vertex* vertices = _pGraph->vertices->next;
		destroyVertex(_pGraph->vertices);
		_pGraph->vertices = vertices;
	}
	free(_pGraph);
}

Vertex* createVertex(int _data)
{
	Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));// 정점 크기의 자동메모리 할당
	newVertex->data = _data;								 // data파트에 _data저장
	newVertex->index = -1;
	newVertex->visited = NotVisited;						 // 방문하지 않음 초기화
	newVertex->adgacenctList = NULL;						 // 정점이 가지고있는 간선들의 헤드간선주소 NULL 초기화
	newVertex->next = NULL;									 // 다음 정점의 포인터 NULL 초기화
	return newVertex;
}

void destroyVertex(Vertex* _pVertex)
{
	// 지울 정점이 가지고 있는 간선노드부터 지움
	Edge* remove = _pVertex->adgacenctList; // 헤드노드를 remove로 설정
	if (remove != NULL) {					// 지울 노드가 있다면
		while (remove->next != NULL) {		// 현재 노드가 꼬리가 아니라면
			_pVertex->adgacenctList = _pVertex->adgacenctList->next;	// 현재의 헤드노드의 다음노드를 헤드로 변경
			destroyEdge(remove);		// remove소멸
			remove = _pVertex->adgacenctList;
		}
		destroyEdge(remove);			// 마지막 꼬리노드까지 소멸
	}
	free(_pVertex);					// 정점 메모리 소멸
}

Edge* createEdge(Vertex* _from, Vertex* _target, int _weight)
{
	Edge* newEdge = (Edge*)malloc(sizeof(Edge));		 // 간선 크기의 자동메모리 할당
	newEdge->from = _from;									 // 간선의 출발지점 매개변수로 받아 할당
	newEdge->target = _target;								 // 간선의 도착지점 매개변수로 받아 할당
	newEdge->weight = 0;									 // 간선의 가중치 0으로 초기화
	newEdge->next = NULL;									 // 다음 간선의 포인터 NULL로 초기화
	return newEdge;
}

void destroyEdge(Edge* _pRemove)
{
	free(_pRemove);
}

void addVertex(Graph* _pGraph, Vertex* _pNewVertex)
{
	// 그래프가 비어있을 때
	if (_pGraph->vertices == NULL) {
		_pGraph->vertices = _pNewVertex;
	}
	else {	// 그래프의 정점이 1개 이상 있을 때
		// 그래프가 가지고 있는 정점 리스트의 꼬리 찾기
		Vertex* vertices = _pGraph->vertices;
		while (vertices->next != NULL) {
			vertices = vertices->next;
		}
		// 꼬리 노드를 찾았다면 꼬리노드의 다음노드로 _pVertiex주소 할당
		vertices->next = _pNewVertex;
	}
	// 그래프의 정점 갯수 카운터 증가
	_pNewVertex->index = _pGraph->vertexCount++;
}

void addEdge(Vertex* _pVertex, Edge* _pNewEdge)
{
	// 정점에 연결된 간선이 없을 때
	if (_pVertex->adgacenctList == NULL) {
		_pVertex->adgacenctList = _pNewEdge;
	}
	else {	// 정점에 연결된 간선이 1개 이상 있을 때
		Edge* adgacenctList = _pVertex->adgacenctList;
		// 정점이 가지고있는 간선리스트의 꼬리노드 찾기
		while (adgacenctList->next != NULL) {
			adgacenctList = adgacenctList->next;
		}
		// 꼬리노드를 찾았다면 꼬리노드의 next포인터로 _pNewEdge주소 연결
		adgacenctList->next = _pNewEdge;
	}
}

void printGraph(Graph* _pGraph)
{
	Vertex* vertices = _pGraph->vertices;
	if (vertices == NULL) {	 // 출력할 정점이 없다면 리턴
		return;
	}
	
	while (vertices != NULL) {
		printf("%d : ", vertices->data);	// 정점이 가진 데이터 출력

		Edge* edge = vertices->adgacenctList;
		if (edge == NULL) {						// 정점이 가진 간선이 없다면
			vertices = vertices->next;			// 다음 정점 출력
			printf("\n");
			continue;

		}
		while (edge != NULL) {					// 간선리스트의 꼬리노드까지 출력
			printf("%d[%d] ", edge->target->data, edge->weight);
			edge = edge->next;					// 다음 간선 출력
		}
		printf("\n");
		vertices = vertices->next;				// 현재 정점의 모든 간선을 출력했으면 다음 정점 출력
	}
}
