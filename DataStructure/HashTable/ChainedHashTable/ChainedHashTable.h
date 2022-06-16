#include<stdio.h>
#include<stdlib.h>

typedef char* keyType;
typedef char* ValueType;

typedef struct _tagNode {
	keyType key;
	ValueType value;
	struct _tagNode* nextNode;
} Node;

//typedef struct _tagList {
//	Node* head;
//} List;

typedef struct _tagHashTable {
	int tableSize;
	Node** table;					// (�߿�)����Ʈ�� ������ headNode�� �ּڰ��� ���� �迭�޸��� �ּڰ��� ��ƾ� �ϹǷ� ��������Ʈ ����
} HashTable;

// ���̺� ����
HashTable* CHT_createTable(int _initSize);
// ���̺� �Ҹ�
void CHT_destroyTable(HashTable* _pTable);
// ����Ʈ �Ҹ�
void CHT_destroyList(Node* _pList);


// ��� ����
Node* CHT_createNode(keyType _key, ValueType* _value);
// ��� �Ҹ�
void CHT_destroyNode(Node* _pNode);

// ���̺� ������ �߰�
void CHT_set(HashTable* _pTable, keyType _key, ValueType _value);
// ���̺� ������ ��������
ValueType CHT_get(HashTable* _pTable, keyType _key);
// �ؽ��� ��ȯ
int hash(keyType _key, int _keyLength, int _tableSize);
