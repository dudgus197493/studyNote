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

// 테이블 생성 함수
OATable* OA_createTable(int _initSize);
// 테이블 소멸 함수
void OA_destroyTable(OATable* _pTable);
// 노드 소멸 함수
void OA_destroyNode(Node* _pNode);

// 테이블 노드 삽입 함수
void OA_set(OATable** _ppTable, KeyType _key, ValueType _value);
// 데이블 노드 데이터 가져오기
ValueType OA_get(OATable* _pTable, KeyType _key);


// 배열공간 늘리기
void OA_reHash(OATable** _ppTable);
// key -> address 해싱
int OA_hash(KeyType _key, int keyLen, int _tableSize);
// key -> stepSize 해싱
int OA_hash2(KeyType _key, int keyLen, int _tableSize);
