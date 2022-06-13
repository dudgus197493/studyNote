#include "Heap.h"
#include <vcruntime_string.h>

Heap* H_createHeap(int _initSize)
{
	Heap* newHeap = (Heap*)malloc(sizeof(Heap));
	newHeap->capacity = _initSize;
	newHeap->usedSize = 0;
	newHeap->nodes = (HeapNode*)malloc(sizeof(HeapNode) * newHeap->capacity);
	printf("���ο� �� ���� [���迭 ������ = %d]\n", newHeap->capacity);
		
	return newHeap;
}

void H_insert(Heap* _pHeap, int _newData)
{
	int currentPos = _pHeap->usedSize;					
	
	int parentPos = H_getParent(currentPos);		// ���� �� ����� �θ� �ǽôº� ã��
	
	if (_pHeap->capacity == _pHeap->usedSize) {			// ���� ó�� - �� �迭�� �̹� �������ִٸ� ���� 2�� �ø���
			_pHeap->capacity *= 2;
			_pHeap->nodes = (HeapNode*)realloc(_pHeap->nodes, sizeof(HeapNode) * _pHeap->capacity);
	}
	_pHeap->nodes[currentPos].iData = _newData;
	while (currentPos > 0 && _pHeap->nodes[currentPos].iData < _pHeap->nodes[parentPos].iData) {			// cuurent�� parent���� ������ �ڸ���ȯ ũ�� break;
		
		H_swapNodes(_pHeap, currentPos, parentPos);		// �θ� �ڽ� ������ ������ �ٲٱ�

		
		currentPos = parentPos;							// ���� ��ġ�� �ڽ��� �θ𿴴� ��ġ�� ����
		
		parentPos = H_getParent(currentPos);		// ���ŵ� ���� ��ġ�� �������� �θ� ��ġ ���ϱ�
	}
	_pHeap->usedSize++;
}

void H_delMinNode(Heap* _pHeap, HeapNode* _pRoot)
{
	
	*_pRoot = _pHeap->nodes[0];							// �迭�� ù��° ��Ұ� �ּڰ�
	
	memset(&_pHeap->nodes[0], 0, sizeof(HeapNode));	// �迭�� ù��° ��� �޸� 0���� �ʱ�ȭ
	_pHeap->usedSize--;
	
	H_swapNodes(_pHeap, 0, _pHeap->usedSize);		// �迭�� ������ ��Ҹ� ù��°�� �̵�
	
	
	int currentPos = 0;									// ���� �Ӽ��� �����ϱ� ���� �ڽ��� �ڸ� ã�ư���
	while (true) {										// - �ݺ���
		
		int leftChildPos = H_getLeftChildPos(currentPos);	// 1. �ڽ��� ���� �ڽ� ����� ��ġ�� ����
		int rightChildPos = leftChildPos + 1;
		int smallerPos;
		
		if (leftChildPos >= _pHeap->usedSize) {		// ����ó�� - ���� �ε����� �ٳ���϶� break
			break;
		}
		if (rightChildPos >= _pHeap->usedSize) {	// ����ó�� - ������ �ڽ� ��尡 ���� �� ���� ��� �ε����� ��
			smallerPos = leftChildPos;
		}
		else {
			// 2. �ڽ��� ���� ���� �ڽĳ���� ���������� ũ�ٸ� ��ġ ��ȯ
			smallerPos = _pHeap->nodes[leftChildPos].iData < _pHeap->nodes[rightChildPos].iData ? leftChildPos : rightChildPos;
		}
		
		if (_pHeap->nodes[currentPos].iData > _pHeap->nodes[smallerPos].iData) {
			
			H_swapNodes(_pHeap, currentPos, smallerPos);		// ��ġ ��ȯ			
			
			currentPos = smallerPos;									// ���� ����Ű�� �ε����� �ڽź��� �۾Ҵ� ����� �ε����� ����
		}
		
		else {
			break;														// �ڽĺ��� �ڽ��� �۴ٸ� break
		}
	} // end while

	if (_pHeap->usedSize < _pHeap->capacity / 2) {						// 3. �������� �� ���� ������� �޸𸮰� ���� �� �޸��� 1/2���� ������ �� �޸� ����
		_pHeap->capacity /= 2;
		_pHeap->nodes = (HeapNode*)realloc(_pHeap->nodes, sizeof(HeapNode) * _pHeap->capacity);
	}
}

int H_getParent(int _index)
{
	int parent = (_index - 1) / 2;
	return parent;
}

void H_swapNodes(Heap* _pHeap, int currentPos, int parentPos)
{
	// �޸� ���縦 ���� �޸𸮰��� ��ü�� ����
	
	int copySize = sizeof(HeapNode);
	HeapNode* tmpNode = (HeapNode*)malloc(copySize);					// �ӽ÷� ������ �޸� �Ҵ�
	
	memcpy(tmpNode, &_pHeap->nodes[currentPos], copySize);		// �޸� ��ȯ
	memcpy(&_pHeap->nodes[currentPos], &_pHeap->nodes[parentPos], copySize);
	memcpy(&_pHeap->nodes[parentPos], tmpNode, copySize);
	
	free(tmpNode);														// �ӽ÷� ���� �޸� �Ҵ� ����

	// Data���� �ٲ۴ٸ� ���߿� ����� ���� ����ü���� ��� ����� �ٲ������
	/*int tmp = _pHeap->nodes[parentPos].iData;
	_pHeap->nodes[parentPos].iData = _pHeap->nodes[currentPos].iData;
	_pHeap->nodes[currentPos].iData = _pHeap->nodes[parentPos].iData;*/
}

int H_getLeftChildPos(int _index)
{
	int leftChildPos = (2 * _index) + 1;
	return leftChildPos;
}

void H_printAllNodes(Heap* _pHeap)
{
	printf("�� ���==============\n");
	for (int i = 0; i < _pHeap->usedSize; i++) {
		
		printf("%d ", _pHeap->nodes[i].iData);
	}
	printf("\n��ũ�� : %d, ������� ũ�� : %d\n", _pHeap->capacity, _pHeap->usedSize);
}

void H_destroyHeap(Heap* _pHeap)
{
	free(_pHeap->nodes);
	free(_pHeap);
}
