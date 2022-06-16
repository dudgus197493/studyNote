// �ؽ� ���̺�
// ���� �迭�� �����Ͱ� ����� �ε����� ����ϰ� �ٴ��� �ʾƼ� ���������� ������ �迭�ӿ��� �ұ��ϰ� Ž���˰����� ����Ͽ� ����� �����ϰ� ���� ã��
// ���������� ������ �迭�� ������ �������. - �������� : �ε�����ȣ�� �ش� �ּҸ� �ٷ� �����ϴ� �� (ex. "apple" -> 100)
// Hash - �ǹ��ִ� ������
//	- Hash(key, Data);
//  - key % tableSize(ex=10) = 0 ~ 9 (��������)
//	- Hash���� �����ִ� �Լ�(HashFunc)

// Hash���� �ߺ��̵Ǹ� �浹�� �Ͼ
//	1. opened addrssy - �ٸ� ����ִ� ��ġ�� ã�Ƽ� �ذ� -- �̷����ΰ� �������� ������� ����(������� ������ ���� Ȯ��o - ������ �������� ��� �˰��ִٰ� 50%�� ������ ���̺������ Ȯ��)
//														  �迭 ������ �÷����� ���� ����Ǿ��ִ� ������ �ؽð�����(�ؽð��� ���ϴ� ������(���̺����) �޶���) �޶����� �ؽð��� �ٽñ��ϰ� ���Ҵ��ؾ���(���Ҵ� ���� �ʴ´ٸ� ������ ������ ã���� ���Ե�)
//	2. closed addrssy - �浹 ��ġ���� �ذ�
//	- �浹�� �Ͼ ��ġ�������� LinkedList�� ����(�迭�� ����Ұ� List�� HeadNode)	(����� �ؽ�������� Ʈ��������� �� ��Ұ� List�� RootNode)
//  - Ű���� �ε������� �������� �� ���� �ߺ������� ��������
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

// �ؽ� ���̺� ���� �Լ�
HashTable* createTable(int _initSize);

// �ؽ� ���̺� ������ ����
void set(HashTable* _pTable, KeyType _key, ValueType value);
// �ؽ� ���̺� ������ ��������
ValueType get(HashTable* _pTable, KeyType _key);
// �ؽ� ���̺� �Ҹ�
void destroyTable(HashTable* _pTable);
// �ؽ� �Լ�
int Hash(KeyType _key, int _size);