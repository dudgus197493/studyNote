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
	Node* newNode = LLS_createNode(_newData);			// ���ο� ��� ����
	// ������ ������� ��
	if (_pStack->head == NULL) {
		_pStack->head = newNode;
		_pStack->top = newNode;
	}
	else {	// ���ÿ� �����Ͱ� �ϳ��� ������
		_pStack->top->nextNode = newNode;				// ���� �ֻ��� ����� ���� ���� newNode�� ����
		_pStack->top = newNode;							// ������ �ֻ��� ��带 newNode�� ����
	}
	_pStack->count++;									// ������ ī��Ʈ ����
}

Node* LLS_pop(LinkedListStack* _pStack)
{
	Node* popNode = _pStack->top;						// pop�Լ��� ��ȯ�� ���
	_pStack->count--;									// ������ ī��Ʈ ����
	if (_pStack->head == _pStack->top) {				// ���ÿ� �����Ͱ� 1���ۿ� �����ٸ�
		_pStack->head = NULL;
		_pStack->top = NULL;
	}
	else {												// �����Ͱ� �� �ִٸ�
		Node* nextTopNode = _pStack->head;				// ���� top��尡 �� ��带 ã��
		while (nextTopNode->nextNode != _pStack->top) { // ���� Ž��
			nextTopNode = nextTopNode->nextNode;
		}
		nextTopNode->nextNode = NULL;					// top��带 �����״� ��������� ������ NULL�� �ʱ�ȭ
		_pStack->top = nextTopNode;						// ����Ʈ�� top��� �����͸� nextTopNode�ּҷ� ����
	}
	return popNode;										// popNode ��ȯ
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
	// ���� ������ �� ������ �ݺ������� ��带 ����
	while (!LLS_isEmpty(_pStack)) {
		Node* remove = LLS_pop(_pStack);
		LLS_destroyNode(remove);
	}
	// ���þȿ� ��� ��带 �Ҹ��ߴٸ� �����ڽŵ� �Ҹ�
	free(_pStack);
}

int LLS_isEmpty(LinkedListStack* _pStack)
{
	return _pStack->count == 0;
}
