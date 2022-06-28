#include<stdio.h>
#include<stdlib.h>
typedef struct _tagPQNode {
	void* Data;
	int priority;
} PQNode;

typedef struct _tagPriorityQueue {
	PQNode* nodes;			// ť ��� �迭
	int capacity;				// ť ��� �迭 �ƽ� ������
	int usedSize;				// ť ��� �迭 ������� ������
} PriorityQueue;

// ť ����
PriorityQueue* PQ_createQueue(int _initSize);
// ť ��� ����
void PQ_enQueue(PriorityQueue* _pPQ, PQNode _newNode);

// ť �ּڰ� ���� & ��ȯ
void PQ_deQueue(PriorityQueue* _pPQ, PQNode* _pRoot);

// �θ� ��� ��ġ ��ȯ 
int H_getParent(int _index);

// �θ� �ڽ� ��ġ ����
void H_swapNodes(PriorityQueue* _pPQ, int currentPos, int parentPos);

// ���� �ڽ� �ε��� ��ȯ - �����ڽĸ� ���ϸ� ��ȯ���� +1�� ������ �ڽ� �ε����� ���� �� ����
int H_getLeftChildPos(int _index);

// ť ��� ��� ���
void PQ_printAllNodes(PriorityQueue* _pPQ);

// ť ����
void PQ_destroyQueue(PriorityQueue* _pPQ);

// ����ִ��� Ȯ��
int isEmpty(PriorityQueue* _pPQ);	// ���� ���� �ʿ�
