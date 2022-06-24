#include "Graph.h"
#include "Heap.h"
// �ּ� ���� Ʈ��
// ��� ������ ����, �� ��Ŭ�� �������� �ʰ�
// �� ����� ���� ����

// ����
// 1. ���� �˰���
// �����ϳ��� ������ ������ �Ѱ� �̻������� ����Ŭ�� ������ �� �ִ�.
// �׷��Ƿ� weights, precedences �迭�� �����Ͽ� �ش� �������� ������ ������ ������ ���峷�� ����ġ(weights)�� ���� ���� �ϳ����� �����ϵ��� ��� �����Ѵ�.


#define MAX_WEIGHT 36267
void prim(Graph* _pGraph, Vertex* _pStartVertex, Graph* _pMST) {
	PQNode startNode = { _pStartVertex, 0 };					// ���������� ť ���� ����
	PriorityQueue* PQ = PQ_createQueue(10);				// �������� ���� �켱���� ť ����

	Vertex* currentVertex = NULL;
	Edge* currentEdge = NULL;

	int* weights = (int*)malloc(sizeof(_pGraph->vertexCount));	// ����ġ���� ���� �迭�� ����(ũ��� �׷����� ���� ��)
																// �������� �ε����ȿ� �ش��������� �ö��� ���(����ġ)�� �����
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);

	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);	// �ش������� �湮�ƴ��� Ȯ��(�ε����ȿ� ������������ �� ������ �湮�Ϸ��� ����)

	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount); // �ش������� ���κ��� �Դ���
	
	currentVertex = _pGraph->vertices;
	int i = 0;
	while (currentVertex != NULL) {										// �׷����� ���������� �ϳ��ϳ� �ҷ��ͼ�
		Vertex* newVertex = createVertex(currentVertex->data);			// ������ �� �ּҽ���׷����� �������� �߰�
		addVertex(_pMST, newVertex);

		fringes[i] = NULL;												
		precedences[i] = NULL;
		MSTVertices[i] = newVertex;
		weights[i] = MAX_WEIGHT;
		currentVertex = currentVertex->next;
		i++;
	}

	PQ_enQueue(PQ, startNode);											// �������� ť�� ����

	weights[_pStartVertex->index] = 0;									// �������� �ε����ڸ��� 0���� �ʱ�ȭ

	while (!isEmpty(PQ)) {												// ť�� �� �� ����
		PQNode popped;
		
		PQ_deQueue(PQ, &popped);										// �켱����(weight)�� ���� ���� ���(����) pop
		currentVertex = (Vertex*)popped.Data;

		fringes[currentVertex->index] = currentVertex;					// �湮ó��

		currentEdge = currentVertex->adgacenctList;						// ���� ������ ���� ���� ����Ʈ ��������
		while (currentEdge != NULL) {									// ��������Ʈ�� NULL�϶����� ��� ���� üũ
			Vertex* targetVertex = currentEdge->target;					// ������ Ÿ������ ��������

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

		addEdge(MSTVertices[toIndex], createEdge(MSTVertices[toIndex], MSTVertices[fromIndex], weights[i]));	// �����⼺�̹Ƿ� ������ ����Ű�� ���� ������ ��������

	}
	free(fringes);
	free(precedences);
	free(MSTVertices);
	/*free(weights);*/
	H_destroyHeap(PQ);
}

// 2. ũ�罺Į �˰���