#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* KeyType;
typedef char* ValueType;

enum Status {
	EMPTY = 0,
	OCCUPIED = 1
};

typedef struct _tagNode {
	KeyType key;
	ValueType value;

	enum Status status;
} Node;

typedef struct _tagOpenAddressingHashTable {
	int tableSize;
	int usedSize;
	Node* table;
} OATable;

// ���̺� ���� �Լ�
OATable* OA_createTable(int _initSize);
// ���̺� �Ҹ� �Լ�
void OA_destroyTable(OATable* _pTable);
// ��� �Ҹ� �Լ�
void OA_destroyNode(Node* _pNode);

// ���̺� ��� ���� �Լ�
void OA_set(OATable** _ppTable, KeyType _key, ValueType _value);
// ���̺� ��� ������ ��������
ValueType OA_get(OATable* _pTable, KeyType _key);


// �迭���� �ø���
void OA_reHash(OATable** _ppTable);
// key -> address �ؽ�
int OA_hash(KeyType _key, int keyLen, int _tableSize);
// key -> stepSize �ؽ�
int OA_hash2(KeyType _key, int keyLen, int _tableSize);
