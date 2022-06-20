#include <stdio.h>


// �����迭�� ������ ����Ʈ�� �Ѻ���� ����������
// ���� �迭�� �� �޸𸮿� ���ӵ� �޸𸮸� ��Ƴ���
// �����͸� �����Ѵ�.

// ������ ����Ʈ�� �����͸� �߰��Ҷ����� �� �޸� ��򰡿� �����͸� �����ϰ�
// ������(���)���� �����Ѵ�.

typedef struct _tagNode {
	int iData;					// �ڽ��� ������ ������
	_tagNode* pNextNode;		// �ڽ��� ���� ���(������)
} Node;


typedef struct _tagList {
	int iCount;					// ������ ����Ʈ�� ������ ����

	// int iMaxCount;			// �ѹ��� �޸𸮰����� ��� �����͸� �߰��ϴ� �迭�� �ٸ���
								// ��ũ�� ����Ʈ�� �����͸� �߰��Ҷ����� �޸𸮸� �Ҵ��ϹǷ� ��������� �Ѱ谡 ����.
	
	Node* pHeadNode;			// ����Ʈ �ڽ��� ���(������)�� �ƴϹǷ�
								// ������ Ȯ���Ϸ��� ù��° ����� �ּҸ� �˰� �־��� �Ѵ�.

} LinkedList;

// ����Ʈ �ʱ�ȭ �Լ�
void InitList(LinkedList* _pList);

// ������ ����Ʈ ������ �߰�
void PushBack(LinkedList* _pList, int _iData);

void PushFront(LinkedList* _pList, int _iData);

// ����Ʈ �޸� ����
void ReleaseList(LinkedList* _pList);

// ����Ʈ ���
void printList(LinkedList* _pList);