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
	//rear은 실제 후단보다 +1값을 가지고 있음(rear인덱스에는 비어있음)
	if (_pQueue->rear == _pQueue->capacity) {	// rear이 배열의 마지막을 가리키고 있었다면
		pos = _pQueue->rear;					// 그 인덱스에 데이터를 저장하고
		_pQueue->rear = 0;						// 맨 앞으로 이동 
	}
	else {										// 마지막을 가리키고 있지 않다면
		pos = _pQueue->rear++;					// 그 인덱스에 데이터를 저장하고 한칸 뒤로 이동
	}
	_pQueue->nodes[pos].iData = _newData;		// 실제 데이터 저장 처리
}

int CQ_deQueue(CircularQueue* _pQueue)
{
	int pos = _pQueue->front;
	if (_pQueue->front == _pQueue->capacity) {	// 전단이 배열의 끝을 가리키고 있었다면
		_pQueue->front = 0;						// 0으로 초기화
	} else{										// 전단이 배열의 끝을 가리키고 있지 않았다면
		_pQueue->front++;						// 한칸 전진
	}
	return _pQueue->nodes[pos].iData;
}

int CQ_isEmpty(CircularQueue* _pQueue)
{
	return _pQueue->front == _pQueue->rear;		// 전단과 후단이 같은 곳을 가리키면 비어있다는 뜻
}

int CQ_isFull(CircularQueue* _pQueue)
{
	if (_pQueue->front < _pQueue->rear) {		// 전단이 후단보다 앞을 가리킬 때
		return (_pQueue->rear - _pQueue->front) == _pQueue->capacity;	// 후단 인덱스 - 전단 인덱스가 용량이면 꽉차있다는 뜻
	}
	else {									// 전단이 후단보다 뒤를 가리킬 때
		return (_pQueue->rear + 1) == _pQueue->front;					// 후단인덱스 + 1이 전단인덱스와 같으면 꽉차있다는 뜻
	}
}

int CQ_getSize(CircularQueue* _pQueue)
{
	if (_pQueue->front <= _pQueue->rear) {		// 전단이 후단보다 앞을 가리킬 때
		return _pQueue->rear - _pQueue->front;
	}
	else if (_pQueue->front > _pQueue->rear) {	// 전단이 후단보다 뒤를 가리킬 때
		return _pQueue->rear + (_pQueue->capacity - _pQueue->front + 1);
	}
	return 0;
}



