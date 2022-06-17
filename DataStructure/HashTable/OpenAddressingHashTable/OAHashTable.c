#include "OAHashTable.h"

OATable* OA_createTable(int _initSize)
{
	OATable* newTable = (OATable*)malloc(sizeof(OATable));
	newTable->tableSize = _initSize;
	newTable->usedSize = 0;
	newTable->table = (Node*)malloc(sizeof(Node) * newTable->tableSize);
	memset(newTable->table, 0, sizeof(Node) * newTable->tableSize);			// new테이블의 배열메모리주소를 널로 초기화
																			// 0으로 초기화 해주면 Node 구조체의 Status가 EMPTY를 가리키기 됨
	return newTable;
}

void OA_destroyTable(OATable* _pTable)
{
	// 테이블 소멸하기전에 테이블 안에있는 배열의 요소들 전부 소멸
	// 1. 배열 인덱스 0 부터 tableSize까지 돌면서 노드 소멸
	for (int i = 0; i < _pTable->tableSize; i++) {
		OA_destroyNode(&_pTable->table[i]);
	}
	// 2. table 모든 인덱스의 노드를 소멸했으면 자기 자신 소멸
	free(_pTable->table);
	free(_pTable);
}

void OA_destroyNode(Node* _pNode)
{
	if (_pNode->status == EMPTY) {  // 노드가 이미 비어있다면 리턴
		return;
	}
	// 1. 노드의 상태를 EMPTY로 갱신
	_pNode->status = EMPTY;

	// key포인터 변수의 주소가 가리키는 메모리를 소멸
	free(_pNode->key);
	
	// value포인터 변수의 주소가 가리키는 메모리를 소멸
	free(_pNode->value);
}

void OA_set(OATable** _ppTable, KeyType _key, ValueType _value)
{
	// 0. 배열의 점유율이 50%이상일경우 배열의 크기를 2배 늘림
	double usage = (double)(*_ppTable)->usedSize / (*_ppTable)->tableSize;
	if (usage >= 0.5) {		// 점유율이 50%이상이면
		OA_reHash(_ppTable);
	}
	// 1. hash함수를 통해 address를 구함
	int address = OA_hash(_key, strlen(_key), (*_ppTable)->tableSize);
	// 2. hash2함수를 통해 address인덱에 데이터충돌이 일어났을때 건너뛸 칸수를 구함
	int stepSize = OA_hash(_key, strlen(_key), (*_ppTable)->tableSize);
	// 3. address인덱스에 접근했을때 비어있으면 데이터저장
	// 4. 비어있지 않다면 비어있는 공간을 찾을때가지 stepSize를 반복적으로 더하면서 접근 
	while ((*_ppTable)->table[address].status != EMPTY) {
		printf("Collision occured! : Key(%s, Address(%d), StepSize(%d)\n", _key, address, stepSize);
		address = (address + stepSize) % (*_ppTable)->tableSize;
	}
	// 데이터 저장 처리
	// 1. key값 저장
	(*_ppTable)->table[address].key = (KeyType)malloc(strlen(_key) + 1);
	strcpy((*_ppTable)->table[address].key, _key);
	// 2. value값 저장
	(*_ppTable)->table[address].value = (ValueType)malloc(strlen(_value) + 1);
	strcpy((*_ppTable)->table[address].value, _value);
	// 3. Status 갱신
	(*_ppTable)->table[address].status = OCCUPIED;
	// _ppTable의 usedSize++
	(*_ppTable)->usedSize++;
	printf("Key(%s) entered at address(%d)\n", _key, address);
}

ValueType OA_get(OATable* _pTable, KeyType _key)
{
	// key값을 해싱하여 address와 stepSize를 구함
	int address = OA_hash(_key, strlen(_key), _pTable->tableSize);
	int stepSize = OA_hash2(_key, strlen(_key), _pTable->tableSize);
	// address에 데이터가 key값과 일치하는지 확인, 일치 하지 않으면 stepSize만큼 이동하면서 일치할때까지 확인
	while (_pTable->table[address].status == EMPTY && strcmp(_pTable->table[address].key, _key) != 0) {
		address = (address + stepSize) % _pTable->tableSize;
	}
	return _pTable->table[address].value;
}

void OA_reHash(OATable** _ppTable)
{
	OATable* oldTable = (*_ppTable);	// 기존 테이블을 임시 변수에 저장
	// 새로운 테이블 생성 (기존테이블의 크기 2배)
	OATable* newTable = OA_createTable(oldTable->tableSize * 2);
	printf("\nRehashed. New table size is : %d\n\n", newTable->tableSize);
	// oldTable 배열의 0부터 끝가지 돌면서 EMPTY가 아니면 newTable에 값 복사
	for (int i = 0; i < oldTable->tableSize; i++) {
		if (oldTable->table[i].status != EMPTY) {
			OA_set(&newTable, oldTable->table[i].key, oldTable->table[i].value);

		}
	}
	// 기존 테이블 소멸
	OA_destroyTable(oldTable);
	// 메인에 있는 OATable* 포인터 변수에 새로운 OATable 객체의 주소 저장
	(*_ppTable) = newTable;
}

int OA_hash(KeyType _key, int keyLen, int _tableSize)
{
	int hashValue = 0;
	for (int i = 0; i < keyLen; i++) {
		hashValue = (hashValue << 3) + _key[i];
	}
	hashValue %= _tableSize;
	return hashValue;
}

int OA_hash2(KeyType _key, int keyLen, int _tableSize)
{
	int hashValue = 0;
	for (int i = 0; i < keyLen; i++) {
		hashValue = (hashValue << 2) + _key[i];
	}
	hashValue %= (_tableSize - 3);
	return hashValue + 1;
}

