#include "Graph.h"

Graph* createGraph()
{
	Graph* newGraph = (Graph*)malloc(sizeof(Graph));	// �׷��� ũ���� �ڵ��޸� �Ҵ�
	newGraph->vertices = NULL;								// ��������� ������ NULL�ʱ�ȭ
	newGraph->vertexCount = 0;								// ������ ���� 0 �ʱ�ȭ;


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
	Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));// ���� ũ���� �ڵ��޸� �Ҵ�
	newVertex->data = _data;								 // data��Ʈ�� _data����
	newVertex->index = -1;
	newVertex->visited = NotVisited;						 // �湮���� ���� �ʱ�ȭ
	newVertex->adgacenctList = NULL;						 // ������ �������ִ� �������� ��尣���ּ� NULL �ʱ�ȭ
	newVertex->next = NULL;									 // ���� ������ ������ NULL �ʱ�ȭ
	return newVertex;
}

void destroyVertex(Vertex* _pVertex)
{
	// ���� ������ ������ �ִ� ���������� ����
	Edge* remove = _pVertex->adgacenctList; // ����带 remove�� ����
	if (remove != NULL) {					// ���� ��尡 �ִٸ�
		while (remove->next != NULL) {		// ���� ��尡 ������ �ƴ϶��
			_pVertex->adgacenctList = _pVertex->adgacenctList->next;	// ������ ������� ������带 ���� ����
			destroyEdge(remove);		// remove�Ҹ�
			remove = _pVertex->adgacenctList;
		}
		destroyEdge(remove);			// ������ ���������� �Ҹ�
	}
	free(_pVertex);					// ���� �޸� �Ҹ�
}

Edge* createEdge(Vertex* _from, Vertex* _target, int _weight)
{
	Edge* newEdge = (Edge*)malloc(sizeof(Edge));		 // ���� ũ���� �ڵ��޸� �Ҵ�
	newEdge->from = _from;									 // ������ ������� �Ű������� �޾� �Ҵ�
	newEdge->target = _target;								 // ������ �������� �Ű������� �޾� �Ҵ�
	newEdge->weight = 0;									 // ������ ����ġ 0���� �ʱ�ȭ
	newEdge->next = NULL;									 // ���� ������ ������ NULL�� �ʱ�ȭ
	return newEdge;
}

void destroyEdge(Edge* _pRemove)
{
	free(_pRemove);
}

void addVertex(Graph* _pGraph, Vertex* _pNewVertex)
{
	// �׷����� ������� ��
	if (_pGraph->vertices == NULL) {
		_pGraph->vertices = _pNewVertex;
	}
	else {	// �׷����� ������ 1�� �̻� ���� ��
		// �׷����� ������ �ִ� ���� ����Ʈ�� ���� ã��
		Vertex* vertices = _pGraph->vertices;
		while (vertices->next != NULL) {
			vertices = vertices->next;
		}
		// ���� ��带 ã�Ҵٸ� ��������� �������� _pVertiex�ּ� �Ҵ�
		vertices->next = _pNewVertex;
	}
	// �׷����� ���� ���� ī���� ����
	_pNewVertex->index = _pGraph->vertexCount++;
}

void addEdge(Vertex* _pVertex, Edge* _pNewEdge)
{
	// ������ ����� ������ ���� ��
	if (_pVertex->adgacenctList == NULL) {
		_pVertex->adgacenctList = _pNewEdge;
	}
	else {	// ������ ����� ������ 1�� �̻� ���� ��
		Edge* adgacenctList = _pVertex->adgacenctList;
		// ������ �������ִ� ��������Ʈ�� ������� ã��
		while (adgacenctList->next != NULL) {
			adgacenctList = adgacenctList->next;
		}
		// ������带 ã�Ҵٸ� ��������� next�����ͷ� _pNewEdge�ּ� ����
		adgacenctList->next = _pNewEdge;
	}
}

void printGraph(Graph* _pGraph)
{
	Vertex* vertices = _pGraph->vertices;
	if (vertices == NULL) {	 // ����� ������ ���ٸ� ����
		return;
	}
	
	while (vertices != NULL) {
		printf("%d : ", vertices->data);	// ������ ���� ������ ���

		Edge* edge = vertices->adgacenctList;
		if (edge == NULL) {						// ������ ���� ������ ���ٸ�
			vertices = vertices->next;			// ���� ���� ���
			printf("\n");
			continue;

		}
		while (edge != NULL) {					// ��������Ʈ�� ���������� ���
			printf("%d[%d] ", edge->target->data, edge->weight);
			edge = edge->next;					// ���� ���� ���
		}
		printf("\n");
		vertices = vertices->next;				// ���� ������ ��� ������ ��������� ���� ���� ���
	}
}
