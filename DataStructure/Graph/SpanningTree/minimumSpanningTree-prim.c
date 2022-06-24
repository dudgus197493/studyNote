// �ּҽ���Ʈ��-���� �˰���

// 1. �׷����� ������ �� �ּҽ���Ʈ�� �غ�
// 2. �׷������� ������ ������ ���� �������� ����, �ּ� ����Ʈ���� ��Ʈ ���� ����
// 3. �ּҽ���Ʈ���� ���ԵǾ� �ִ� ������� �� �������� ��� ���� ���� ���̿� �ִ� ������ ����ġ ����
// 4. ���� �߿� ���� ����ġ�� ���� ���� ��� �� ������ ����Ǿ� �ִ� ���� ������ �ּ� ���� Ʈ���� ����
// 5. ��, ���� ���ԵǴ� ������ �ּҽ���Ʈ���� ���� �Ǿ� �ִ� ������ ����� ����Ŭ�� �����ؼ��� �ȵ�
// 3,4,5�� ������ �ݺ��ϴٰ� �ּҽ���Ʈ���� �׷����� ��� ������ �����ϰ� �Ǹ� �˰��� ����
#include"Graph.h"
#include"Heap.h"
#define MAX_WEIGHT 36267
void prim(Graph* _pGraph, Vertex* _pStartVertex, Graph* _pPrimMST) {
	PQNode startNode = { _pStartVertex, 0 };						// ���������� ������ ������ �����Ƿ� ����ġ 0
	PriorityQueue* PQ = PQ_createQueue(10);					// �ּ� ����ġ�� ���� ������ �˾Ƴ������� �켱���� ť

	Vertex* currentVertex = NULL;									// ���� �ٷ���ִ� ������ ������ ����
	Edge* currentEdge = NULL;										// ���� �ٷ���ִ� ������ ������ ����

	int* weights = (int*)malloc(sizeof(int) * _pGraph->vertexCount);	// �ش� �ε����� ���ϴ� �������� ������ ������ ����ġ ����
																			// �׷����� �������� �ѹ��� �����ϱ� ���ϰ� �������� ������ �ε������� ���� �迭�� �߻�ȭ

	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);	// �������� ���������� �ε����� ���� ���� �������� ���� ���� �����迭
	Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);		// �ش� �ε����� ���ϴ� ������ �湮�Ǿ������� �˼��ִ� �迭 ����
	Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * _pGraph->vertexCount);	// �ش� �ε����� ���ϴ� �������� ������ ������ ��ó(������ from����)�� ����
																							// �迭���� �ε����� 1���ۿ� �����͸� ������ �� �����Ƿ� �ڿ������� �ش��ε����� ���ϴ� �������� ������ ������ 1���� ������
																							// (�ѹ� �� ������ ������ ����ġ�� ���� ���� ���������� ����)
																							// �ڽ����� ������ ������ 1�� ���϶�� ����Ŭ�� ���� �� �� ����

	// �׷����� ������ �ִ� �������� �ּҽ���Ʈ���� �ű�
	// �ű�� �������� �迭�� �ʱ�ȭ
	int i = 0;
	currentVertex = _pGraph->vertices;														// �׷����� ��� ������ ������������ �ʱ�ȭ
	while (currentVertex != NULL) {															// �׷����� ��� ������ ���鼭
		Vertex* newVertex = createVertex(currentVertex->data);							// �׷����� ������ �����͸� �����ؼ�
		addVertex(_pPrimMST, newVertex);									// �ּҽ���Ʈ���� �������� �߰�

		// �迭 �ʱ�ȭ
		MSTVertices[i] = newVertex;															// �ּҽ���Ʈ���� �������� ���� �����ϱ����� �迭�� �ʱ�ȭ
		weights[i] = MAX_WEIGHT;															// ó�� i���� �ε����� ���������� �������� ������ ���̵ǰ� �ִ� ����
		fringes[i] = NULL;																	// �湮���� false �ʱ�ȭ
		precedences[i] = NULL;																// �ڽ��� ����Ű�� ���� ���� NULL �ʱ�ȭ
		currentVertex = currentVertex->next;
		i++;
	}

	// ���۳�� ť�� ����
	PQ_enQueue(PQ, startNode);
	weights[_pStartVertex->index] = 0;														// ������������ ������ ������ �����Ƿ� 0
	// �ּҽ���Ʈ���� ���� ���������迭 ����
	while (!isEmpty(PQ)) {																// ť�� �� ������(��ٸ� �������Ḧ ����) 
		PQNode popped;																		
		PQ_deQueue(PQ, &popped);													// ����ġ�� ���� ���� ���� ��������
		currentVertex = (Vertex*)popped.Data;												// ť�� ��带 ���� �ڷ������� ��ȯ
		fringes[currentVertex->index] = currentVertex;										// ���� ���� �湮ó��
		currentEdge = currentVertex->adgacenctList;											// ���� ������ ���������� �� ��尣������ ��������
		while (currentEdge != NULL) {														// ��� �������� ���鼭
			Vertex* targetVertex = currentEdge->target;										// ���� ������ ���������� ������ ��������
			if (fringes[targetVertex->index] == NULL && currentEdge->weight < weights[targetVertex->index]) {	
				// ���� ������ ������������ �̹� �湮���� �ʾҰų�(ť���� �ѹ��� ������ �ʾҰų�), ���� ������ ����ġ�� �̹� ������������ ����Ű���ִ� ������ ����ġ���� �۴ٸ� if�� ����
				PQNode newNode = { targetVertex , currentEdge->weight };					// ������ �켱����ť�� ���� ����
				PQ_enQueue(PQ, newNode);													// ť�� �߰�

				weights[targetVertex->index] = currentEdge->weight;							// ������������ ����Ű�� ���������迭�鿡 ���� ���������� ����
				precedences[targetVertex->index] = currentEdge->from;
			}
			currentEdge = currentEdge->next;
		}
	}

	// ������������ ������ �迭���� �������� �ּҽ���Ʈ���� ���� �߰�

	for (int i = 0; i < _pGraph->vertexCount; i++) {
		int fromIndex, toIndex;	

		if (precedences[i] == NULL) {	// ���������� ������ ������ ������ �����Ƿ� �ɷ��������� �ڵ�
			continue;
		}
		fromIndex = precedences[i]->index;		// �߰��� ������ from����� ���� ������ ������ �ε���
		toIndex = i;

		addEdge(MSTVertices[fromIndex], createEdge(MSTVertices[fromIndex], MSTVertices[toIndex], weights[i]));

		addEdge(MSTVertices[toIndex], createEdge(MSTVertices[toIndex], MSTVertices[fromIndex], weights[i]));
	}
	free(fringes);
	free(precedences);
	free(MSTVertices);

	PQ_destroyQueue(PQ);
}