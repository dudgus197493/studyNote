#include "DisjointSet.h"

void UnionSet(DisjointSet* _pSet1, DisjointSet* _pSet2)
{
	//set2�� �����ִ� ������ ����
	_pSet2 = FindSet(_pSet2);
	_pSet2->parent = _pSet1;
}

DisjointSet* FindSet(DisjointSet* _pNode)
{
	DisjointSet* parentSet = _pNode;
	// �ڽ��� parent�� NULLd�϶����� ���� �ö�
	while (parentSet->parent != NULL) {
		parentSet = parentSet->parent;
	}
	return parentSet;
}

DisjointSet* createNode(void* _Data)
{
	DisjointSet* newNode = (DisjointSet *) malloc(sizeof(DisjointSet));
	newNode->parent = NULL;
	newNode->Data = _Data;

	return newNode;
}

void destroyNode(DisjointSet* _remove)
{
	free(_remove);
}
