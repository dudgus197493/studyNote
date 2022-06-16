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
	Node** table;					// (중요)리스트의 시작인 headNode의 주솟값을 담을 배열메모리의 주솟값을 담아야 하므로 더블포인트 선언
} HashTable;

// 테이블 생성
HashTable* CHT_createTable(int _initSize);
// 테이블 소멸
void CHT_destroyTable(HashTable* _pTable);
// 리스트 소멸
void CHT_destroyList(Node* _pList);


// 노드 생성
Node* CHT_createNode(keyType _key, ValueType* _value);
// 노드 소멸
void CHT_destroyNode(Node* _pNode);

// 테이블 데이터 추가
void CHT_set(HashTable* _pTable, keyType _key, ValueType _value);
// 테이블 데이터 가져오기
ValueType CHT_get(HashTable* _pTable, keyType _key);
// 해싱후 반환
int hash(keyType _key, int _keyLength, int _tableSize);
