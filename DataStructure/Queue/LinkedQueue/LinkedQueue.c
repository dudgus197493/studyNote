#include "LinkedQueue.h"

LinkedQueue* createQueue()
{
	LinkedQueue* newQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	newQueue->front = NULL;
	newQueue->rear = NULL;
	newQueue->usedSize = 0;

	return newQueue;
}

void destroyQueue(LinkedQueue* _pQueue)
{
	while (!isEmpty(_pQueue)) {
		Node* removeNode = deQueue(_pQueue);
		destroyNode(removeNode);
	}
	free(_pQueue);
}

void enQueue(LinkedQueue* _pQueue, ElementType _data)
{
	Node* newNode = createNode(_data);		// ���ο� ��� ����
	if (isEmpty(_pQueue)) {					// ť�� ����ִٸ�
		_pQueue->front = newNode;
		_pQueue->rear = newNode;
	}
	else {
		_pQueue->rear->nextNode = newNode;	// ť�� ��������� �������� ���ο��� ����
		_pQueue->rear = newNode;			// ť�� �������� ���ο� ��� ����
	}
	_pQueue->usedSize++;
}

Node* deQueue(LinkedQueue* _pQueue)
{
	if (isEmpty(_pQueue)) {
		printf("ť�� ����ֽ��ϴ�.");
		return;
	}
	Node* popNode = _pQueue->front;
	_pQueue->front = _pQueue->front->nextNode;
	_pQueue->usedSize--;
	return popNode;
}

Node* createNode(ElementType _data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = (ElementType)malloc(strlen(_data) + 1);
	strcpy(newNode->data, _data);
	newNode->nextNode = NULL;
	return newNode;
}

void destroyNode(Node* _pNode)
{
	free(_pNode->data);
	free(_pNode);
}

int isEmpty(LinkedQueue* _pQueue)
{
	return _pQueue->usedSize == 0;
}
