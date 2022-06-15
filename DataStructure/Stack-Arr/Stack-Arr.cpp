#include "Stack-Arr.h"

ArrayStack* AS_createStack(int _initSize)
{
	ArrayStack* newStack = (ArrayStack*)malloc(sizeof(ArrayStack));
	newStack->capacity = _initSize;
	newStack->top = 0;
	newStack->nodes = (Node*)malloc(sizeof(Node)*newStack->capacity);

	return newStack;
}

void AS_destroyStack(ArrayStack* _remove)
{
	free(_remove->nodes);
	free(_remove);
}


void AS_push(ArrayStack* _pStack, int newData)
{
	// 예외처리 스택이 꽉차있다면 공간 두배 확장
	/*if (_pStack->top == _pStack->capacity) {
		_pStack->capacity *= 2;
		_pStack->nodes = (Node*)realloc(_pStack->nodes, sizeof(Node)*_pStack->capacity);
	}*/
	// top이 가리키는 인덱스에 newData저장
	_pStack->nodes[_pStack->top].Data = newData;
	_pStack->top++;
}

int AS_pop(ArrayStack* _pStack)
{
	_pStack->top--;								// 스택이 가지고있는 최상위 노드의 위치는 실제 데이터의 인덱스보다 1높기때문에
	return _pStack->nodes[_pStack->top].Data;	// 먼저 top을 줄이고 그다음에 top위치에있는 데이터를 반환해준다.
}

int AS_getSize(ArrayStack* _pStack)
{
	return _pStack->top;
}

int AS_top(ArrayStack* _pStack)
{
	return _pStack->nodes[_pStack->top - 1].Data;
}

int AS_isFull(ArrayStack* _pStack)
{
	return (_pStack->capacity == _pStack->top);
}

int AS_isEmpty(ArrayStack* _pStack)
{
	return (_pStack->top == 0);
}
