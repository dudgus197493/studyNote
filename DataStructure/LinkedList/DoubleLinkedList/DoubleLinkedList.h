#include<iostream>
typedef struct _tagNode {
	// �ڽ��� �� ���
	_tagNode* prevNode;
	// �ڽ��� �� ���
	_tagNode* nextNode;
	// ������
	int iData;
} Node;

typedef struct _tagDoubleLinkedList {
	// ��� ���
	Node* headNode;
	// ���� ���
	Node* tailNode;
	// ���� �Ǿ� �ִ� ������ ī��Ʈ
	unsigned int count;
} DoubleLinkedList;

// list ����
DoubleLinkedList* DLL_createList();

// ��� ���� / �Ҹ�
Node* createNode(int _data);
void destroyNode(Node* _pTarget);

// ��� �߰�
void DLL_appendBack(DoubleLinkedList* _pList, int _data);
void DLL_appendFront(DoubleLinkedList* _pList, int _data);

// ��� Ž��	- ���� LinkedList�� �ٸ��� ����� Ž���� �� �� �־� �߻������ 2�� ���� �Ҽ� �ִ�.
Node* DLL_searchNode(DoubleLinkedList* _pList, unsigned int _index);

// ��� ����
void DLL_insertNode(DoubleLinkedList* _pList, int _data, int _index);

// ����Ʈ ��� ������ ���
void DLL_printAllNode(DoubleLinkedList* _pList);
// ����Ʈ ����
void DLL_destroyList(DoubleLinkedList* _pList);
