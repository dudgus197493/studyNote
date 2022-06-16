#include "HashTable.h"

HashTable* createTable(int _initSize)
{
	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
	newTable->TableSize = _initSize;
	newTable->Table = (Node*)malloc(sizeof(Node)*_initSize);

	return newTable;
}

void set(HashTable* _pTable, KeyType _key, ValueType _value)
{
	// key값을 Hash함수를 사용하여 index번호 얻어오기
	int address = Hash(_key, _pTable->TableSize);

	_pTable->Table[address].key = _key;
	_pTable->Table[address].value = _value;
}

ValueType get(HashTable* _pTable, KeyType _key)
{
	int address = Hash(_key, _pTable->TableSize);
	return _pTable->Table[address].value;
}

void destroyTable(HashTable* _pTable)
{
	free(_pTable->Table);
	free(_pTable);
}

int Hash(KeyType _key, int _size)
{
	return _key % _size;
}
