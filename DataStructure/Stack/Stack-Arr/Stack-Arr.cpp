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
	// ����ó�� ������ �����ִٸ� ���� �ι� Ȯ��
	/*if (_pStack->top == _pStack->capacity) {
		_pStack->capacity *= 2;
		_pStack->nodes = (Node*)realloc(_pStack->nodes, sizeof(Node)*_pStack->capacity);
	}*/
	// top�� ����Ű�� �ε����� newData����
	_pStack->nodes[_pStack->top].Data = newData;
	_pStack->top++;
}

int AS_pop(ArrayStack* _pStack)
{
	_pStack->top--;								// ������ �������ִ� �ֻ��� ����� ��ġ�� ���� �������� �ε������� 1���⶧����
	return _pStack->nodes[_pStack->top].Data;	// ���� top�� ���̰� �״����� top��ġ���ִ� �����͸� ��ȯ���ش�.
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
