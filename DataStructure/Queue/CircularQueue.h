// ��ȯ ť 
// �迭�� ����뷮 ���� ������ �ذ� �ϱ� ���� �迭�� ���� ������ �̾�ٿ� �����.
// �������� ���̴°��� �Ұ����ϳ� ť�� ���ܰ� �Ĵ���ġ�� ����Ͽ� ���������� ���� �� �ִ�.
// ť�� �����Ͱ� ���� �ɶ����� ������ ��ġ �ű�
// ť�� �����Ͱ� �߰� �ɶ����� �Ĵ��� ��ġ �ű�
// �Ĵ��� �ڷ� �����ϴٰ� ���ܰ� �����ԵǸ� ������ ����
// ������
// ��ȯ ť�� ��� �ִ� ���¿� ���� �� ���¸� ������ �� ����.
// �ذ�
// ť �迭�� ������ �� ������ �뷮���� 1��ŭ �� ũ�� ���� ���ܰ� �Ĵ�(������ �Ĵ�) ���̸� ���� ��
//	��> ��������� ���ܰ� �Ĵ��� ���� ���� ����Ŵ, ���� �� ������ �Ĵ��� ���ܺ��� 1�������� ����

#include <stdio.h>
#include<stdlib.h>

typedef struct _tagNode {
	int iData;
}Node;

typedef struct _tagCircularQueue {
	int capacity;					// �뷮
	int rear;						// ������ �ε���
	int front;						// �Ĵ��� �ε���
	Node* nodes;						// ��� �迭
} CircularQueue;

// ť ����
CircularQueue* CQ_createQueue(int _initSize);
// ť �Ҹ�
void CQ_destroyQueue(CircularQueue* _pQueue);

// ť ������ ����
void CQ_enQueue(CircularQueue* _pQueue, int _newData);

// ť ������ ����
int CQ_deQueue(CircularQueue* _pQueue);

// ť ���� Ȯ��
int CQ_isEmpty(CircularQueue* _pQueue);

// ť ��ȭ Ȯ��
int CQ_isFull(CircularQueue* _pQueue);

// ť ���� �����ͼ� Ȯ��
int CQ_getSize(CircularQueue* _pQueue);