// ��ũ�� ����Ʈ�� �̿��Ͽ� ������ ����
// �迭�� �ٸ��� ������ �뷮�� ������ ���� �ʾƵ� �� - capacity ��� �ʿ����
// ��ũ�� ����Ʈ�� �ε����������� ��忡 ������ �� ����	- top ��� �ʿ����
// ���� ������ �����Ϸ��� �ڽ��� ���� ��ġ�ϴ� ���(nextNode)�� ���� �����͸� ���� �־�� ��.


#include <stdio.h>
#include <stdlib.h>

typedef struct _tagNode {
	char* Data;
	_tagNode* nextNode;
} Node;

typedef struct _tagLinkedListStack {
	int count;
	Node* head;					// ����Ʈ�� ��忡 ������ �� �ְ� ����� ��带 �˰��־�� ��
	Node* top;					// ����Ʈ��ġ�� ������� - �̰��� �˰������� 4byte�� �����Ͽ� ������带 �˱����� ����Ž���̶�� ����� �������� �ʾƵ� ��
} LinkedListStack;


// ���� ����
LinkedListStack* LLS_createStack();
// ���� �Ҹ�
void LLS_destroyStack(LinkedListStack* _pStack);

// ���� ��� �߰�
void LLS_push(LinkedListStack* _pStack, const char* _newData);
// ���� ��� ����
Node* LLS_pop(LinkedListStack* _pStack);

// ��� ����
Node* LLS_createNode(const char* _newData);
// ��� �Ҹ�
void LLS_destroyNode(Node* _remove);


// ������ �ֻ��� ��� Ȯ��
Node* LLS_top(LinkedListStack* _pStack);

// ������ ���� ��� �� Ȯ��
int LLS_getSize(LinkedListStack* _pStack);

// ������ ������� Ȯ��
int LLS_isEmpty(LinkedListStack* _pStack);
