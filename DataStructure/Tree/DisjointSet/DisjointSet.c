#include "DisjointSet.h"

void UnionSet(DisjointSet* _pSet1, DisjointSet* _pSet2)
{
	//set2가 속해있는 집합을 구함
	_pSet2 = FindSet(_pSet2);
	_pSet2->parent = _pSet1;
}

DisjointSet* FindSet(DisjointSet* _pNode)
{
	DisjointSet* parentSet = _pNode;
	// 자신의 parent가 NULLd일때까지 위로 올라감
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
