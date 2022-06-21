#include "Graph.h"

void depthFirstSearch(Vertex* _pVertex)
{
	printf("%c ", _pVertex->data);
	_pVertex->visited = Visited;
	if (_pVertex->adgacenctList != NULL) {				// 간선이 있으면
		Edge* edge = _pVertex->adgacenctList;			// 간선 리스트의 헤드노드 저장
		while (edge != NULL) {							// 간선이 NULL이 아니면
			if (edge->target->visited == NotVisited) {	// 해당 간선이 가리키는 정점이 한번도 방문하지 않았다면
				depthFirstSearch(edge->target);			// 간선이 가리키는 정점을 인자로 재귀호출
			}
			edge = edge->next;							// 다음 간선으로 갱신
		}
	}
}