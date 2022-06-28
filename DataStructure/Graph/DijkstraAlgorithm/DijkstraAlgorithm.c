// ���ͽ�Ʈ�� �˰���
// ���ͽ�Ʈ�� �˰����� ����Ŭ�� ���� ���⼺ �׷��V ���ؼ��� ����� �� ����


// �⺻���� ����� ���� �˰���� ������
// ���� �˰����� weights �迭�� ������ ����ġ�� ��������.
// ���ͽ�Ʈ�� �˰����� weights�迭���� ������ from������ �ε����� �迭���� target������ �ε��� �迭���� ���� �����
// (�ش� ������ �����ϱ���� ������ ����ġ�� ������ ����)

#include "Graph.h"
#include "Heap.h"

#define MAX_WEIGHT 36267
void Dijkstra(Graph* _pGraph, Vertex* _pStartVertex, Graph* _pShortestPath) {
	PQNode startNode = { _pStartVertex, 0 };
	PriorityQueue* PQ = PQ_createQueue(10);

	Vertex* currentVertex = NULL;
	Edge* currentEdge = NULL;

	int* weights = (int*)malloc(sizeof(int) * _pGraph->vertexCount);						// �ּ� ��θ� �����ϱ� ���� �迭
	Vertex** shortestPathVerices = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);// �ּҰ�� �׷����� ������ ����
	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);			// �������� �湮���θ� Ȯ���ϱ� ���� �迭
	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);		// �������� ����Ŭ�� �������� �ʰ� �ϱ����� �迭

	currentVertex = _pGraph->vertices;														// ������������
	int i = 0;
	while (currentVertex != NULL) {															// ��� ������
		Vertex* newVertex = createVertex(currentVertex->data);							// �����͸� �����ؼ� 
		addVertex(_pShortestPath, newVertex);								// �ִܰ�α׷����� �������� �߰�

		fringes[i] = NULL;																	// ���� �ε��� �ʱ�ȭ
		precedences[i] = NULL;
		weights[i] = MAX_WEIGHT;
		shortestPathVerices[i] = newVertex;

		currentVertex = currentVertex->next;												// ���� ��������
		i++;																				// ���� �ε�����
	}

	PQ_enQueue(PQ, startNode);													// ���۳�� ť�� �߰�
	weights[_pStartVertex->index] = 0;														// ���۳��� �Ÿ��� 0

	while (!isEmpty(PQ)) {																// ť�� �� �� ����
		PQNode popped;
		PQ_deQueue(PQ, &popped);
		currentVertex = (Vertex*)popped.Data;
		fringes[currentVertex->index] = currentVertex;										// ť���� �������� �湮 ó��

		currentEdge = currentVertex->adgacenctList;											// �湮�� ������ ������������ ������
		while (currentEdge != NULL) {														// ��� ������ ���鼭
			Vertex* targetVertex = currentEdge->target;
			if (fringes[targetVertex->index] == NULL && weights[currentVertex->index] + currentEdge->weight < weights[targetVertex->index]) {
				// ������ ������ ���� �湮���� �ʾҰ�, ���ݱ��� �� ����� �Ÿ��� ������ִ� �������� ��κ��� ������ ����
				PQNode newNode = { targetVertex, currentEdge->weight };
				PQ_enQueue(PQ, newNode);

				precedences[targetVertex->index] = currentEdge->from;									// from ������ precedences�迭�� ����				
				weights[targetVertex->index] = weights[currentVertex->index] + currentEdge->weight;		// ���� ����� ���̸� ����
				printf("currentEdge %c->%c : weights %d\n", currentEdge->from->data, currentEdge->target->data, weights[targetVertex->index]);
			}
			currentEdge = currentEdge->next;														// ���� ��������
		}
	}


	for (i = 0; i < _pGraph->vertexCount; i++) {

		if (precedences[i] == NULL) {																	// ���������� from�� NULL�̹Ƿ� �ǳʶ�
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