#include "Stack-LinkedList.h"
#include <string.h>

LinkedListStack* LLS_createStack()
{
	LinkedListStack* newStack = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	newStack->head = NULL;
	newStack->top = NULL;
	newStack->count = 0;
	return newStack;
}

void LLS_push(LinkedListStack* _pStack, const char* _newData)
{
	Node* newNode = LLS_createNode(_newData);			// 새로운 노드 생성
	// 스택이 비어있을 때
	if (_pStack->head == NULL) {
		_pStack->head = newNode;
		_pStack->top = newNode;
	}
	else {	// 스택에 데이터가 하나라도 있으면
		_pStack->top->nextNode = newNode;				// 현재 최상위 노드의 다음 노드로 newNode를 연결
		_pStack->top = newNode;							// 스택의 최상위 노드를 newNode로 갱신
	}
	_pStack->count++;									// 데이터 카운트 증가
}

Node* LLS_pop(LinkedListStack* _pStack)
{
	Node* popNode = _pStack->top;						// pop함수가 반환할 노드
	_pStack->count--;									// 데이터 카운트 감소
	if (_pStack->head == _pStack->top) {				// 스택에 데이터가 1개밖에 없었다면
		_pStack->head = NULL;
		_pStack->top = NULL;
	}
	else {												// 데이터가 더 있다면
		Node* nextTopNode = _pStack->head;				// 다음 top노드가 될 노드를 찾음
		while (nextTopNode->nextNode != _pStack->top) { // 순차 탐색
			nextTopNode = nextTopNode->nextNode;
		}
		nextTopNode->nextNode = NULL;					// top노드를 가리켰던 이전노드의 포인터 NULL로 초기화
		_pStack->top = nextTopNode;						// 리스트의 top노드 포인터를 nextTopNode주소로 갱신
	}
	return popNode;										// popNode 반환
}

Node* LLS_createNode(const char* _newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->nextNode = NULL;
	newNode->Data = (char*)malloc(strlen(_newData) + 1);
	strcpy_s(newNode->Data, strlen(_newData) + 1 ,_newData);
	return newNode;
}

void LLS_destroyNode(Node* _remove)
{
	free(_remove->Data);
	free(_remove);
}

Node* LLS_top(LinkedListStack* _pStack)
{
	return _pStack->top;
}

int LLS_getSize(LinkedListStack* _pStack)
{
	return _pStack->count;
}

void LLS_destroyStack(LinkedListStack* _pStack)
{
	// 스택 공간이 빌 때까지 반복문으로 노드를 제거
	while (!LLS_isEmpty(_pStack)) {
		Node* remove = LLS_pop(_pStack);
		LLS_destroyNode(remove);
	}
	// 스택안에 모든 노드를 소멸했다면 스택자신도 소멸
	free(_pStack);
}

int LLS_isEmpty(LinkedListStack* _pStack)
{
	return _pStack->count == 0;
}
