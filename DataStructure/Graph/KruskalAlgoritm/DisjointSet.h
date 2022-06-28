// 분리 집합
// 분리 집합은 원소 또는 개체가 어느 집합에 소속되어 있는가? 라는 정보를 바탕으로 하는 알고리즘
// 위 가정에서처럼 어떤 한 원소가 소속되어 있는 집합을 알아내는 것을 집합 탐색이라고 함
// 루트 노드는 집합 그 자체이고, 루트 노드 자신을 포함한 트리 내의 모든 노드들은 그 집합에 소속된다.
// 분리집합의 목적은 원소가 어느 집합에 귀속되어 있는지를 쉽게 알아낼 수 있도록 하는 것.

// 합집합
// 두 집합을 더하는 것. 분리집합a, b가 있다면 b의 최상위 노드의 부모로 a를 연결하면 됨.

// 집합 탐색
// 원소를 찾는 것이 아니라. 원소가 속해 있는 집합을 찾는 것.
// 원소가 속해있는 트리의 루트 노드를 알면 됨.

#include<stdio.h>
#include<stdlib.h>

typedef struct _tagDisjointSet {
	struct _tagDisjointSet* parent;
	void* Data;
} DisjointSet;

// 합 집합
void UnionSet(DisjointSet* _pSet1, DisjointSet* _pSet2);

// 집합 탐색
DisjointSet* FindSet(DisjointSet* _pNode);

// 노드생성
DisjointSet* createNode(void* _Data);
// 노드소멸
void destroyNode(DisjointSet* _remove);