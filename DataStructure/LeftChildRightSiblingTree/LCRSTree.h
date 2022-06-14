#include<stdio.h>
#include<stdlib.h>

typedef struct _tagLCRSNode {
	int iData;
	_tagLCRSNode* leftChild;
	_tagLCRSNode* rightSibling;
} LCRSNode;

// 노드 생성 함수
LCRSNode* LCRS_createNode(int _newData);

// 자식 노드 연결 함수
void LCRS_addChildNode(LCRSNode* _pParentNode, LCRSNode* _pChildNode);

// 트리 출력 함수
void LCRS_printTree(LCRSNode* _pNode, int Depth);

// 노드 소멸 함수
void LCRS_destroyNode(LCRSNode* remove);

// 트리 소멸 함수
void LCRS_destroyTree(LCRSNode* _pRoot);

// 특정레벨의 모든 노드 출력 함수
void LCRS_PrintNodesAtLevel(LCRSNode* _pRoot, int _level);