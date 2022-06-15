// ���� (Stack)
// ó���� �� �����Ͱ� ���� �������� ������ �ڷᱸ��
// FILO(First Input Last Out) or LIFO(Last Input First Out)
// ����� ���԰� ������ �ڷᱸ���� ���� �������� �̷����
// �߰��� �����͸� �����ϰų� �����ϴ°��� ������� ����

// �迭�� �̿��Ͽ� ������ ����
// ����
// ������ ������
// ����
// �������� ������ �뷮�� �����ϱ� ��ƴٴ� ����������
// ���� ���� �ʱ⿡ ����ڰ� ���� �뷮��ŭ�� ��带 �Ѳ����� ������ �ֻ��� ����� ��ġ�� ��Ÿ���� ������ �̿��� ����/���� ���� ����

#include <stdio.h>
#include <stdlib.h>
typedef struct _tagNode {
	int Data;
} Node;

typedef struct _tagArrayStack {
	int capacity;			// ������ �뷮
	int top;				// �ֻ��� ����� ��ġ
	Node* nodes;			// ������ ������ �迭
} ArrayStack;

// ���� ����
ArrayStack* AS_createStack(int _initSize);

// ���� �Ҹ�
void AS_destroyStack(ArrayStack* _remove);

// ���� ����
void AS_push(ArrayStack* _pStack, int newData);

// ���� ����
int AS_pop(ArrayStack* _pStack);

// ������ ������ Ȯ�� ���� - top����� �� ������
int AS_getSize(ArrayStack* _pStack);

// �ֻ��� ��� Ȯ�� ����
int AS_top(ArrayStack* _pStack);

// ������ �����ִ��� Ȯ��
int AS_isFull(ArrayStack* _pStack);

// ������ ����ִ��� Ȯ��
int AS_isEmpty(ArrayStack* _pStack);