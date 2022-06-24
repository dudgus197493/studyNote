#include "Heap.h"
#include<string.h>

PriorityQueue* PQ_createQueue(int _initSize)
{
	PriorityQueue* newHeap = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	newHeap->capacity = _initSize;
	newHeap->usedSize = 0;
	newHeap->nodes = (PQNode*)malloc(sizeof(PQNode) * newHeap->capacity);
	printf("새로운 큐 생성 [노드배열 사이즈 = %d]\n", newHeap->capacity);
		
	return newHeap;
}

void PQ_enQueue(PriorityQueue* _pPQ, PQNode _newNode)
{
	int currentPos = _pPQ->usedSize;					
	
	int parentPos = H_getParent(currentPos);		// 삽입 할 노드의 부모 되시는분 찾기
	
	if (_pPQ->capacity == _pPQ->usedSize) {			// 예외 처리 - 큐 배열이 이미 가득차있다면 공간 2배 늘리기
		if (_pPQ->capacity == 0) {
			_pPQ->capacity = 1;
		}
			_pPQ->capacity *= 2;
			_pPQ->nodes = (PQNode*)realloc(_pPQ->nodes, sizeof(PQNode) * _pPQ->capacity);
	}
	_pPQ->nodes[currentPos] = _newNode;
	
	while (currentPos > 0 && _pPQ->nodes[currentPos].priority < _pPQ->nodes[parentPos].priority) {			// cuurent가 parent보다 작으면 자리교환 크면 break;
		
		H_swapNodes(_pPQ, currentPos, parentPos);		// 부모 자식 서로의 데이터 바꾸기

		
		currentPos = parentPos;							// 현재 위치를 자신의 부모였던 위치로 갱신
		
		parentPos = H_getParent(currentPos);		// 갱신된 현재 위치를 기준으로 부모 위치 구하기
	}
	_pPQ->usedSize++;
}

void PQ_deQueue(PriorityQueue* _pPQ, PQNode* _pRoot)
{
	
	*_pRoot = _pPQ->nodes[0];							// 배열의 첫번째 요소가 최솟값
	
	memset(&_pPQ->nodes[0], 0, sizeof(PQNode));	// 배열의 첫번째 요소 메모리 0으로 초기화
	_pPQ->usedSize--;
	
	H_swapNodes(_pPQ, 0, _pPQ->usedSize);		// 배열의 마지막 요소를 첫번째로 이동
	
	
	int currentPos = 0;									// 힙의 속성을 유지하기 위해 자신의 자리 찾아가기
	while (1) {										// - 반복문
		
		int leftChildPos = H_getLeftChildPos(currentPos);	// 1. 자신의 양쪽 자식 노드의 위치를 구함
		int rightChildPos = leftChildPos + 1;
		int smallerPos;
		
		if (leftChildPos >= _pPQ->usedSize) {		// 예외처리 - 현재 인덱스가 잎노드일때 break
			break;
		}
		if (rightChildPos >= _pPQ->usedSize) {		// 예외처리 - 오른쪽 자식 노드가 없을 때 왼쪽 노드 인덱스로 비교
			smallerPos = leftChildPos;
		}
		else {
			// 2. 자신의 값이 양쪽 자식노드중 작은값보다 크다면 위치 교환
			smallerPos = _pPQ->nodes[leftChildPos].priority < _pPQ->nodes[rightChildPos].priority ? leftChildPos : rightChildPos;
		}
		
		if (_pPQ->nodes[currentPos].priority > _pPQ->nodes[smallerPos].priority) {
			
			H_swapNodes(_pPQ, currentPos, smallerPos);		// 위치 교환			
			
			currentPos = smallerPos;									// 현재 가리키는 인덱스를 자신보다 작았던 노드의 인덱스로 갱신
		}
		
		else {
			break;														// 자식보다 자신이 작다면 break
		}
	} // end while

	if (_pPQ->usedSize < _pPQ->capacity / 2) {						// 3. 삭제했을 때 현재 사용중인 메모리가 큐의 총 메모리의 1/2보다 작을때 큐 메모리 감소
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
	// 메모리 복사를 통해 메모리공간 자체를 스왑
	
	int copySize = sizeof(PQNode);
	PQNode* tmpNode = (PQNode*)malloc(copySize);					// 임시로 저장할 메모리 할당
	
	memcpy(tmpNode, &_pPQ->nodes[currentPos], copySize);		// 메모리 교환
	memcpy(&_pPQ->nodes[currentPos], &_pPQ->nodes[parentPos], copySize);
	memcpy(&_pPQ->nodes[parentPos], tmpNode, copySize);
	
	free(tmpNode);														// 임시로 잡은 메모리 할당 해제

	// Data값만 바꾼다면 나중에 멤버가 많은 구조체들은 모든 멤버를 바꿔줘야함
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
	printf("큐 출력==============\n");
	for (int i = 0; i < _pPQ->usedSize; i++) {
		
		printf("%s[%d] ", _pPQ->nodes[i].Data, _pPQ->nodes[i].priority);
	}
	printf("\n큐크기 : %d, 사용중인 크기 : %d\n", _pPQ->capacity, _pPQ->usedSize);
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
