#include<stdio.h>
#include<stdlib.h>

typedef struct _tagLCRSNode {
	int iData;
	_tagLCRSNode* leftChild;
	_tagLCRSNode* rightSibling;
} LCRSNode;

// ��� ���� �Լ�
LCRSNode* LCRS_createNode(int _newData);

// �ڽ� ��� ���� �Լ�
void LCRS_addChildNode(LCRSNode* _pParentNode, LCRSNode* _pChildNode);

// Ʈ�� ��� �Լ�
void LCRS_printTree(LCRSNode* _pNode, int Depth);

// ��� �Ҹ� �Լ�
void LCRS_destroyNode(LCRSNode* remove);

// Ʈ�� �Ҹ� �Լ�
void LCRS_destroyTree(LCRSNode* _pRoot);

// Ư�������� ��� ��� ��� �Լ�
void LCRS_PrintNodesAtLevel(LCRSNode* _pRoot, int _level);