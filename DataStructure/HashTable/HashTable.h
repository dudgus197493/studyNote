// 해시 테이블
// 기존 배열은 데이터가 저장된 인덱스를 기억하고 다니지 않아서 임의접근이 가능한 배열임에도 불구하고 탐색알고리즘을 사용하여 비용을 지불하고 값을 찾음
// 임의접근이 가능한 배열의 장점을 살려보자. - 임의접근 : 인덱스번호로 해당 주소를 바로 접근하는 것 (ex. "apple" -> 100)
// Hash - 의미있는 범위값
//	- Hash(key, Data);
//  - key % tableSize(ex=10) = 0 ~ 9 (나눗셈법)
//	- Hash값을 구해주는 함수(HashFunc)

// Hash값이 중복이되면 충돌이 일어남
//	1. opened addrssy - 다른 비어있는 위치를 찾아서 해결 -- 이론적인것 실전에선 사용하지 못함(빈공간이 나오지 않을 확률o - 데이터 점유율을 계속 알고있다가 50%가 넘으면 테이블공간을 확장)
//														  배열 공간을 늘렸을때 기존 저장되어있던 값들의 해시값들이(해시값을 구하는 기준이(테이블공간) 달라짐) 달라져서 해시값을 다시구하고 재할당해야함(재할당 하지 않는다면 기존의 값들을 찾을수 없게됨)
//	2. closed addrssy - 충돌 위치에서 해결
//	- 충돌이 일어난 위치에서부터 LinkedList를 연결(배열의 각요소가 List의 HeadNode)	(레드블렉 해쉬같은경우 트리같은경우 각 요소가 List의 RootNode)
//  - 키값의 인덱스까진 임의접근 그 이후 중복값부턴 순차접근
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct _tagNode {
	KeyType key;
	ValueType value;
} Node;

typedef struct _tagHashTable {
	int TableSize;
	Node* Table;
}HashTable;

// 해시 테이블 생성 함수
HashTable* createTable(int _initSize);

// 해시 테이블 데이터 저장
void set(HashTable* _pTable, KeyType _key, ValueType value);
// 해시 테이블 데이터 가져오기
ValueType get(HashTable* _pTable, KeyType _key);
// 해시 테이블 소멸
void destroyTable(HashTable* _pTable);
// 해시 함수
int Hash(KeyType _key, int _size);