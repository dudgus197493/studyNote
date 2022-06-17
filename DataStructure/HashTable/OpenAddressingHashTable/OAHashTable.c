#include "OAHashTable.h"

OATable* OA_createTable(int _initSize)
{
	OATable* newTable = (OATable*)malloc(sizeof(OATable));
	newTable->tableSize = _initSize;
	newTable->usedSize = 0;
	newTable->table = (Node*)malloc(sizeof(Node) * newTable->tableSize);
	memset(newTable->table, 0, sizeof(Node) * newTable->tableSize);			// new���̺��� �迭�޸��ּҸ� �η� �ʱ�ȭ
																			// 0���� �ʱ�ȭ ���ָ� Node ����ü�� Status�� EMPTY�� ����Ű�� ��
	return newTable;
}

void OA_destroyTable(OATable* _pTable)
{
	// ���̺� �Ҹ��ϱ����� ���̺� �ȿ��ִ� �迭�� ��ҵ� ���� �Ҹ�
	// 1. �迭 �ε��� 0 ���� tableSize���� ���鼭 ��� �Ҹ�
	for (int i = 0; i < _pTable->tableSize; i++) {
		OA_destroyNode(&_pTable->table[i]);
	}
	// 2. table ��� �ε����� ��带 �Ҹ������� �ڱ� �ڽ� �Ҹ�
	free(_pTable->table);
	free(_pTable);
}

void OA_destroyNode(Node* _pNode)
{
	if (_pNode->status == EMPTY) {  // ��尡 �̹� ����ִٸ� ����
		return;
	}
	// 1. ����� ���¸� EMPTY�� ����
	_pNode->status = EMPTY;

	// key������ ������ �ּҰ� ����Ű�� �޸𸮸� �Ҹ�
	free(_pNode->key);
	
	// value������ ������ �ּҰ� ����Ű�� �޸𸮸� �Ҹ�
	free(_pNode->value);
}

void OA_set(OATable** _ppTable, KeyType _key, ValueType _value)
{
	// 0. �迭�� �������� 50%�̻��ϰ�� �迭�� ũ�⸦ 2�� �ø�
	double usage = (double)(*_ppTable)->usedSize / (*_ppTable)->tableSize;
	if (usage >= 0.5) {		// �������� 50%�̻��̸�
		OA_reHash(_ppTable);
	}
	// 1. hash�Լ��� ���� address�� ����
	int address = OA_hash(_key, strlen(_key), (*_ppTable)->tableSize);
	// 2. hash2�Լ��� ���� address�ε��� �������浹�� �Ͼ���� �ǳʶ� ĭ���� ����
	int stepSize = OA_hash(_key, strlen(_key), (*_ppTable)->tableSize);
	// 3. address�ε����� ���������� ��������� ����������
	// 4. ������� �ʴٸ� ����ִ� ������ ã�������� stepSize�� �ݺ������� ���ϸ鼭 ���� 
	while ((*_ppTable)->table[address].status != EMPTY) {
		printf("Collision occured! : Key(%s, Address(%d), StepSize(%d)\n", _key, address, stepSize);
		address = (address + stepSize) % (*_ppTable)->tableSize;
	}
	// ������ ���� ó��
	// 1. key�� ����
	(*_ppTable)->table[address].key = (KeyType)malloc(strlen(_key) + 1);
	strcpy((*_ppTable)->table[address].key, _key);
	// 2. value�� ����
	(*_ppTable)->table[address].value = (ValueType)malloc(strlen(_value) + 1);
	strcpy((*_ppTable)->table[address].value, _value);
	// 3. Status ����
	(*_ppTable)->table[address].status = OCCUPIED;
	// _ppTable�� usedSize++
	(*_ppTable)->usedSize++;
	printf("Key(%s) entered at address(%d)\n", _key, address);
}

ValueType OA_get(OATable* _pTable, KeyType _key)
{
	// key���� �ؽ��Ͽ� address�� stepSize�� ����
	int address = OA_hash(_key, strlen(_key), _pTable->tableSize);
	int stepSize = OA_hash2(_key, strlen(_key), _pTable->tableSize);
	// address�� �����Ͱ� key���� ��ġ�ϴ��� Ȯ��, ��ġ ���� ������ stepSize��ŭ �̵��ϸ鼭 ��ġ�Ҷ����� Ȯ��
	while (_pTable->table[address].status == EMPTY && strcmp(_pTable->table[address].key, _key) != 0) {
		address = (address + stepSize) % _pTable->tableSize;
	}
	return _pTable->table[address].value;
}

void OA_reHash(OATable** _ppTable)
{
	OATable* oldTable = (*_ppTable);	// ���� ���̺��� �ӽ� ������ ����
	// ���ο� ���̺� ���� (�������̺��� ũ�� 2��)
	OATable* newTable = OA_createTable(oldTable->tableSize * 2);
	printf("\nRehashed. New table size is : %d\n\n", newTable->tableSize);
	// oldTable �迭�� 0���� ������ ���鼭 EMPTY�� �ƴϸ� newTable�� �� ����
	for (int i = 0; i < oldTable->tableSize; i++) {
		if (oldTable->table[i].status != EMPTY) {
			OA_set(&newTable, oldTable->table[i].key, oldTable->table[i].value);

		}
	}
	// ���� ���̺� �Ҹ�
	OA_destroyTable(oldTable);
	// ���ο� �ִ� OATable* ������ ������ ���ο� OATable ��ü�� �ּ� ����
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

