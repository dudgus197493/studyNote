#include "LinkedList.h"

void depthFirstSearch(Vertex* _pVertex, LinkedList* _pList);

// 위상 정렬
void TopologicalSort(Vertex* _pVertex, LinkedList* _pList) {
	while (_pVertex != NULL && _pVertex->visited == NotVisited) {
		depthFirstSearch(_pVertex, _pList);

		_pVertex = _pVertex->next;
	}
}

void depthFirstSearch(Vertex* _pVertex, LinkedList* _pList)
{
	_pVertex->visited = Visited;
	Edge* edge = _pVertex->adgacenctList;			// 간선 리스트의 헤드노드 저장
	while (edge != NULL) {							// 간선이 NULL이 아니면
		if (edge->target != NULL && edge->target->visited == NotVisited) {	// 해당 간선이 가리키는 정점이 한번도 방문하지 않았다면
			depthFirstSearch(edge->target, _pList);			// 간선이 가리키는 정점을 인자로 재귀호출
		}
		edge = edge->next;							// 다음 간선으로 갱신
	}
	printf("%c\n", _pVertex->data);
	PushFront(_pList, _pVertex);
}
