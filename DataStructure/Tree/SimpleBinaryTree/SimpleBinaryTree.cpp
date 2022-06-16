#include "SimpleBinaryTree.h"

SBTNode* SBT_createNode(int _newData)
{
	SBTNode* newNode = (SBTNode*)malloc(sizeof(SBTNode));
	newNode->iData = _newData;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

void SBT_destroyNode(SBTNode* _pRemove)
{
	printf("remove[%c]\n", _pRemove->iData);
	free(_pRemove);
}

void SBT_preorderPrintTree(SBTNode* _pNode)
{
	// ������ȸ - ��Ʈ->��������Ʈ��->����������Ʈ��
	if (_pNode == NULL) {
		return;
	}

	// ��Ʈ ��� ���
	printf("%c ", _pNode->iData);

	// ���� ���� Ʈ�� ���
	SBT_preorderPrintTree(_pNode->leftChild);

	// ������ ���� Ʈ�� ���
	SBT_preorderPrintTree(_pNode->rightChild);
}

void SBT_inorderPrintTree(SBTNode* _pNode)
{
	// ������ȸ - ��������Ʈ��->��Ʈ->����������Ʈ��
	if (_pNode == NULL) {
		return;
	}

	// ���� ���� Ʈ�� ���
	SBT_inorderPrintTree(_pNode->leftChild);

	// ��Ʈ ��� ���
	printf("%c ", _pNode->iData);

	// ������ ���� Ʈ�� ���
	SBT_inorderPrintTree(_pNode->rightChild);
}

void SBT_postorderPrintTree(SBTNode* _pNode)
{
	// ������ȸ - ��������Ʈ��->����������Ʈ��->��Ʈ
	if (_pNode == NULL) {
		return;
	}

	// ���� ���� Ʈ�� ���
	SBT_postorderPrintTree(_pNode->leftChild);

	// ������ ���� Ʈ�� ���
	SBT_postorderPrintTree(_pNode->rightChild);

	// ��Ʈ ��� ���
	printf("%c ", _pNode->iData);
}

void SBT_destroyTree(SBTNode* _pRoot)
{
	if (_pRoot == NULL) {
		return;
	}
	// ���� ���� Ʈ�� ����
	SBT_destroyTree(_pRoot->leftChild);

	// ������ ���� Ʈ�� ����
	SBT_destroyTree(_pRoot->rightChild);

	// �ڽ��� ��� ����Ʈ���� ���������� �ڽ� ����
	SBT_destroyNode(_pRoot);
}
