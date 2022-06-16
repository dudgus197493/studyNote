#include "ChainedHashTable.h"



HashTable* CHT_createTable(int _initSize)
{
	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
	newTable->tableSize = _initSize;
	newTable->table = (Node**)malloc(sizeof(Node*)*newTable->tableSize);

	memset(newTable->table, 0, sizeof(Node*)* newTable->tableSize);				// table배열의 포인터들이 메모리 할당 전에 있던 쓰레기값들을 가리키지 못하게 0(NULL)으로 초기화
	return newTable;
}

void CHT_destroyTable(HashTable* _pTable)
{
	for (int i = 0; i < _pTable->tableSize; i++) {	// 배열 인덱스마다 연결된 리스트 소멸
		CHT_destroyList(_pTable->table[i]);
	}
	free(_pTable->table);						// 자신이 가리키던 배열 공간 소멸
	free(_pTable);
}

void CHT_destroyList(Node* _pList)
{
	if (_pList == NULL) {				// 데이터가 없을 때 리턴
		return;
	}
	else {
		if (_pList->nextNode != NULL) {	// 자신이 꼬리노드가 아니라면
			CHT_destroyList(_pList->nextNode);
		}
		CHT_destroyNode(_pList);
	}
}

Node* CHT_createNode(keyType _key, ValueType* _value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = (char*)malloc(sizeof(char) * strlen(_key) + 1);
	strcpy(newNode->key, _key);

	newNode->value = (char*)malloc(sizeof(char) * strlen(_value) + 1);
	strcpy(newNode->value, _value);

	newNode->nextNode = NULL;
	return newNode;
}

void CHT_destroyNode(Node* _pNode)
{
	free(_pNode->key);
	free(_pNode->value);
	free(_pNode);
}

void CHT_set(HashTable* _pTable, keyType _key, ValueType _value)
{
	Node* newNode = CHT_createNode(_key, _value);
	int address = hash(_key, strlen(_key), _pTable->tableSize);
	if (_pTable->table[address] == NULL) {	// 해당 위치에 Node가 비어있으면
		_pTable->table[address] = newNode;
	}								
	else {									// 비어있지 않은 경우		
		newNode->nextNode = _pTable->table[address];	// 해당인덱스의 저장되어있는 주소값을 newNode의 nextNode포인터에 저장
		_pTable->table[address] = newNode;			// newNode에 주소값을 인덱스에 저장

		printf("Collision occured : Key(%s), Address(%d)\n", _key, address);
	}
}

ValueType CHT_get(HashTable* _pTable, keyType _key)
{
	int address = hash(_key, strlen(_key), _pTable->tableSize);
	Node* list = _pTable->table[address];			// 테이블에 찾고자 하는 인덱스에 있는 리스트를 가져옴
	if (list == NULL) {								// 인덱스에 데이터가 없다면 NULL 반환
		return NULL;
	}
	else {											// 데이터가 있다면
		Node* target = list;						// 헤드노드를 타겟으로 초기화
		while (strcmp(target->key, _key) != 0) {	// 타겟의 키값과 찾고자 하는 키값이 같을때까지 반복
			if (target->nextNode == NULL) {			// 더이상 비교할 노드가 없으면 NULL 반환
				return NULL;
			}
			target = target->nextNode;				// target을 다음 노드로 초기화
		}
		return target->value;								// 찾아서 반복문을 탈출했다면 target반환
	}
}

int hash(keyType _key, int _keyLength, int _tableSize)
{
	// 숫자 접기
	int hashValue = 0;
	for (int i = 0; i < _keyLength; i++) {
		hashValue = (hashValue << 3) + _key[i];
	}
	hashValue %= _tableSize;
	return hashValue;
}


