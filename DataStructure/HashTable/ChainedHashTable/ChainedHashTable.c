#include "ChainedHashTable.h"



HashTable* CHT_createTable(int _initSize)
{
	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
	newTable->tableSize = _initSize;
	newTable->table = (Node**)malloc(sizeof(Node*)*newTable->tableSize);

	memset(newTable->table, 0, sizeof(Node*)* newTable->tableSize);				// table�迭�� �����͵��� �޸� �Ҵ� ���� �ִ� �����Ⱚ���� ����Ű�� ���ϰ� 0(NULL)���� �ʱ�ȭ
	return newTable;
}

void CHT_destroyTable(HashTable* _pTable)
{
	for (int i = 0; i < _pTable->tableSize; i++) {	// �迭 �ε������� ����� ����Ʈ �Ҹ�
		CHT_destroyList(_pTable->table[i]);
	}
	free(_pTable->table);						// �ڽ��� ����Ű�� �迭 ���� �Ҹ�
	free(_pTable);
}

void CHT_destroyList(Node* _pList)
{
	if (_pList == NULL) {				// �����Ͱ� ���� �� ����
		return;
	}
	else {
		if (_pList->nextNode != NULL) {	// �ڽ��� ������尡 �ƴ϶��
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
	if (_pTable->table[address] == NULL) {	// �ش� ��ġ�� Node�� ���������
		_pTable->table[address] = newNode;
	}								
	else {									// ������� ���� ���		
		newNode->nextNode = _pTable->table[address];	// �ش��ε����� ����Ǿ��ִ� �ּҰ��� newNode�� nextNode�����Ϳ� ����
		_pTable->table[address] = newNode;			// newNode�� �ּҰ��� �ε����� ����

		printf("Collision occured : Key(%s), Address(%d)\n", _key, address);
	}
}

ValueType CHT_get(HashTable* _pTable, keyType _key)
{
	int address = hash(_key, strlen(_key), _pTable->tableSize);
	Node* list = _pTable->table[address];			// ���̺� ã���� �ϴ� �ε����� �ִ� ����Ʈ�� ������
	if (list == NULL) {								// �ε����� �����Ͱ� ���ٸ� NULL ��ȯ
		return NULL;
	}
	else {											// �����Ͱ� �ִٸ�
		Node* target = list;						// ����带 Ÿ������ �ʱ�ȭ
		while (strcmp(target->key, _key) != 0) {	// Ÿ���� Ű���� ã���� �ϴ� Ű���� ���������� �ݺ�
			if (target->nextNode == NULL) {			// ���̻� ���� ��尡 ������ NULL ��ȯ
				return NULL;
			}
			target = target->nextNode;				// target�� ���� ���� �ʱ�ȭ
		}
		return target->value;								// ã�Ƽ� �ݺ����� Ż���ߴٸ� target��ȯ
	}
}

int hash(keyType _key, int _keyLength, int _tableSize)
{
	// ���� ����
	int hashValue = 0;
	for (int i = 0; i < _keyLength; i++) {
		hashValue = (hashValue << 3) + _key[i];
	}
	hashValue %= _tableSize;
	return hashValue;
}


