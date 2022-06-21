#include "Graph.h"

void depthFirstSearch(Vertex* _pVertex)
{
	printf("%c ", _pVertex->data);
	_pVertex->visited = Visited;
	if (_pVertex->adgacenctList != NULL) {				// ������ ������
		Edge* edge = _pVertex->adgacenctList;			// ���� ����Ʈ�� ����� ����
		while (edge != NULL) {							// ������ NULL�� �ƴϸ�
			if (edge->target->visited == NotVisited) {	// �ش� ������ ����Ű�� ������ �ѹ��� �湮���� �ʾҴٸ�
				depthFirstSearch(edge->target);			// ������ ����Ű�� ������ ���ڷ� ���ȣ��
			}
			edge = edge->next;							// ���� �������� ����
		}
	}
}