#include "LinkedList.h"

void depthFirstSearch(Vertex* _pVertex, LinkedList* _pList);

// ���� ����
void TopologicalSort(Vertex* _pVertex, LinkedList* _pList) {
	while (_pVertex != NULL && _pVertex->visited == NotVisited) {
		depthFirstSearch(_pVertex, _pList);

		_pVertex = _pVertex->next;
	}
}

void depthFirstSearch(Vertex* _pVertex, LinkedList* _pList)
{
	_pVertex->visited = Visited;
	Edge* edge = _pVertex->adgacenctList;			// ���� ����Ʈ�� ����� ����
	while (edge != NULL) {							// ������ NULL�� �ƴϸ�
		if (edge->target != NULL && edge->target->visited == NotVisited) {	// �ش� ������ ����Ű�� ������ �ѹ��� �湮���� �ʾҴٸ�
			depthFirstSearch(edge->target, _pList);			// ������ ����Ű�� ������ ���ڷ� ���ȣ��
		}
		edge = edge->next;							// ���� �������� ����
	}
	printf("%c\n", _pVertex->data);
	PushFront(_pList, _pVertex);
}
