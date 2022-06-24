#include "Heap.h"
#include<string.h>

PriorityQueue* PQ_createQueue(int _initSize)
{
	PriorityQueue* newHeap = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	newHeap->capacity = _initSize;
	newHeap->usedSize = 0;
	newHeap->nodes = (PQNode*)malloc(sizeof(PQNode) * newHeap->capacity);
	printf("���ο� ť ���� [���迭 ������ = %d]\n", newHeap->capacity);
		
	return newHeap;
}

void PQ_enQueue(PriorityQueue* _pPQ, PQNode _newNode)
{
	int currentPos = _pPQ->usedSize;					
	
	int parentPos = H_getParent(currentPos);		// ���� �� ����� �θ� �ǽôº� ã��
	
	if (_pPQ->capacity == _pPQ->usedSize) {			// ���� ó�� - ť �迭�� �̹� �������ִٸ� ���� 2�� �ø���
		if (_pPQ->capacity == 0) {
			_pPQ->capacity = 1;
		}
			_pPQ->capacity *= 2;
			_pPQ->nodes = (PQNode*)realloc(_pPQ->nodes, sizeof(PQNode) * _pPQ->capacity);
	}
	_pPQ->nodes[currentPos] = _newNode;
	
	while (currentPos > 0 && _pPQ->nodes[currentPos].priority < _pPQ->nodes[parentPos].priority) {			// cuurent�� parent���� ������ �ڸ���ȯ ũ�� break;
		
		H_swapNodes(_pPQ, currentPos, parentPos);		// �θ� �ڽ� ������ ������ �ٲٱ�

		
		currentPos = parentPos;							// ���� ��ġ�� �ڽ��� �θ𿴴� ��ġ�� ����
		
		parentPos = H_getParent(currentPos);		// ���ŵ� ���� ��ġ�� �������� �θ� ��ġ ���ϱ�
	}
	_pPQ->usedSize++;
}

void PQ_deQueue(PriorityQueue* _pPQ, PQNode* _pRoot)
{
	
	*_pRoot = _pPQ->nodes[0];							// �迭�� ù��° ��Ұ� �ּڰ�
	
	memset(&_pPQ->nodes[0], 0, sizeof(PQNode));	// �迭�� ù��° ��� �޸� 0���� �ʱ�ȭ
	_pPQ->usedSize--;
	
	H_swapNodes(_pPQ, 0, _pPQ->usedSize);		// �迭�� ������ ��Ҹ� ù��°�� �̵�
	
	
	int currentPos = 0;									// ���� �Ӽ��� �����ϱ� ���� �ڽ��� �ڸ� ã�ư���
	while (1) {										// - �ݺ���
		
		int leftChildPos = H_getLeftChildPos(currentPos);	// 1. �ڽ��� ���� �ڽ� ����� ��ġ�� ����
		int rightChildPos = leftChildPos + 1;
		int smallerPos;
		
		if (leftChildPos >= _pPQ->usedSize) {		// ����ó�� - ���� �ε����� �ٳ���϶� break
			break;
		}
		if (rightChildPos >= _pPQ->usedSize) {		// ����ó�� - ������ �ڽ� ��尡 ���� �� ���� ��� �ε����� ��
			smallerPos = leftChildPos;
		}
		else {
			// 2. �ڽ��� ���� ���� �ڽĳ���� ���������� ũ�ٸ� ��ġ ��ȯ
			smallerPos = _pPQ->nodes[leftChildPos].priority < _pPQ->nodes[rightChildPos].priority ? leftChildPos : rightChildPos;
		}
		
		if (_pPQ->nodes[currentPos].priority > _pPQ->nodes[smallerPos].priority) {
			
			H_swapNodes(_pPQ, currentPos, smallerPos);		// ��ġ ��ȯ			
			
			currentPos = smallerPos;									// ���� ����Ű�� �ε����� �ڽź��� �۾Ҵ� ����� �ε����� ����
		}
		
		else {
			break;														// �ڽĺ��� �ڽ��� �۴ٸ� break
		}
	} // end while

	if (_pPQ->usedSize < _pPQ->capacity / 2) {						// 3. �������� �� ���� ������� �޸𸮰� ť�� �� �޸��� 1/2���� ������ ť �޸� ����
		_pPQ->capacity /= 2;
		_pPQ->nodes = (PQNode*)realloc(_pPQ->nodes, sizeof(PQNode) * _pPQ->capacity);
	}
}

int H_getParent(int _index)
{
	int parent = (_index - 1) / 2;
	return parent;
}

void H_swapNodes(PriorityQueue* _pPQ, int currentPos, int parentPos)
{
	// �޸� ���縦 ���� �޸𸮰��� ��ü�� ����
	
	int copySize = sizeof(PQNode);
	PQNode* tmpNode = (PQNode*)malloc(copySize);					// �ӽ÷� ������ �޸� �Ҵ�
	
	memcpy(tmpNode, &_pPQ->nodes[currentPos], copySize);		// �޸� ��ȯ
	memcpy(&_pPQ->nodes[currentPos], &_pPQ->nodes[parentPos], copySize);
	memcpy(&_pPQ->nodes[parentPos], tmpNode, copySize);
	
	free(tmpNode);														// �ӽ÷� ���� �޸� �Ҵ� ����

	// Data���� �ٲ۴ٸ� ���߿� ����� ���� ����ü���� ��� ����� �ٲ������
	/*int tmp = _pPQ->nodes[parentPos].Data;
	_pPQ->nodes[parentPos].Data = _pPQ->nodes[currentPos].Data;
	_pPQ->nodes[currentPos].Data = _pPQ->nodes[parentPos].Data;*/
}

int H_getLeftChildPos(int _index)
{
	int leftChildPos = (2 * _index) + 1;
	return leftChildPos;
}

void PQ_printAllNodes(PriorityQueue* _pPQ)
{
	printf("ť ���==============\n");
	for (int i = 0; i < _pPQ->usedSize; i++) {
		
		printf("%s[%d] ", _pPQ->nodes[i].Data, _pPQ->nodes[i].priority);
	}
	printf("\nťũ�� : %d, ������� ũ�� : %d\n", _pPQ->capacity, _pPQ->usedSize);
}

void PQ_destroyQueue(PriorityQueue* _pPQ)
{
	free(_pPQ->nodes);
	free(_pPQ);
}

int isEmpty(PriorityQueue* _pPQ)
{
	return _pPQ->usedSize == 0;
}
