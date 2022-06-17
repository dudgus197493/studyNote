#include "CircularQueue.h"

CircularQueue* CQ_createQueue(int _initSize)
{
	CircularQueue* newQueue = (CircularQueue*)malloc(sizeof(CircularQueue));
	newQueue->capacity = _initSize;
	newQueue->front = 0;
	newQueue->rear = 0;
	newQueue->nodes = (Node*)malloc(sizeof(Node) * newQueue->capacity + 1);	
	return newQueue;
}

void CQ_destroyQueue(CircularQueue* _pQueue)
{
	free(_pQueue->nodes);
	free(_pQueue);
}

void CQ_enQueue(CircularQueue* _pQueue, int _newData)
{
	int pos;
	//rear�� ���� �Ĵܺ��� +1���� ������ ����(rear�ε������� �������)
	if (_pQueue->rear == _pQueue->capacity) {	// rear�� �迭�� �������� ����Ű�� �־��ٸ�
		pos = _pQueue->rear;					// �� �ε����� �����͸� �����ϰ�
		_pQueue->rear = 0;						// �� ������ �̵� 
	}
	else {										// �������� ����Ű�� ���� �ʴٸ�
		pos = _pQueue->rear++;					// �� �ε����� �����͸� �����ϰ� ��ĭ �ڷ� �̵�
	}
	_pQueue->nodes[pos].iData = _newData;		// ���� ������ ���� ó��
}

int CQ_deQueue(CircularQueue* _pQueue)
{
	int pos = _pQueue->front;
	if (_pQueue->front == _pQueue->capacity) {	// ������ �迭�� ���� ����Ű�� �־��ٸ�
		_pQueue->front = 0;						// 0���� �ʱ�ȭ
	} else{										// ������ �迭�� ���� ����Ű�� ���� �ʾҴٸ�
		_pQueue->front++;						// ��ĭ ����
	}
	return _pQueue->nodes[pos].iData;
}

int CQ_isEmpty(CircularQueue* _pQueue)
{
	return _pQueue->front == _pQueue->rear;		// ���ܰ� �Ĵ��� ���� ���� ����Ű�� ����ִٴ� ��
}

int CQ_isFull(CircularQueue* _pQueue)
{
	if (_pQueue->front < _pQueue->rear) {		// ������ �Ĵܺ��� ���� ����ų ��
		return (_pQueue->rear - _pQueue->front) == _pQueue->capacity;	// �Ĵ� �ε��� - ���� �ε����� �뷮�̸� �����ִٴ� ��
	}
	else {									// ������ �Ĵܺ��� �ڸ� ����ų ��
		return (_pQueue->rear + 1) == _pQueue->front;					// �Ĵ��ε��� + 1�� �����ε����� ������ �����ִٴ� ��
	}
}

int CQ_getSize(CircularQueue* _pQueue)
{
	if (_pQueue->front <= _pQueue->rear) {		// ������ �Ĵܺ��� ���� ����ų ��
		return _pQueue->rear - _pQueue->front;
	}
	else if (_pQueue->front > _pQueue->rear) {	// ������ �Ĵܺ��� �ڸ� ����ų ��
		return _pQueue->rear + (_pQueue->capacity - _pQueue->front + 1);
	}
	return 0;
}



