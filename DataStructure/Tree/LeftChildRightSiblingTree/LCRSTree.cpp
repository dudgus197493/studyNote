#include "LCRSTree.h"

LCRSNode* LCRS_createNode(int _newData)
{
	LCRSNode* newNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	newNode->iData = _newData;
	newNode->leftChild = NULL;
	newNode->rightSibling = NULL;

	return newNode;
}

void LCRS_addChildNode(LCRSNode* _pParentNode, LCRSNode* _pChildNode)
{
	// parentNode�� �ڽĳ�尡 ����ִ��� Ȯ��
	if (_pParentNode->leftChild == NULL) {			// ����ִٸ� ù��° �ڽĳ��(leftChild)�� _pChildNode �ּ� ����
		_pParentNode->leftChild = _pChildNode;
	}
	else {
		LCRSNode* lastChildNode = _pParentNode->leftChild; // ������ �ڽĳ�带 �߰��ҋ����� �ݺ�
		while (lastChildNode->rightSibling != NULL) {
			lastChildNode = lastChildNode->rightSibling;
		}
		lastChildNode->rightSibling = _pChildNode;		   // �߰��ߴٸ� ������ �ڽĳ���� �������� _pChildNode�� ����
	}
}

void LCRS_printTree(LCRSNode* _pNode, int _depth)
{
	// ���̸�ŭ �鿩����
	for (int i = 0; i < _depth; i++) {
		printf(" ");
	}

	// ��忡 ��� ������ ���
	printf("%c\n", _pNode->iData);

	if (_pNode->leftChild != NULL) {		// ���� ����� �ڽ��� �ִٸ� �ڽĳ�带 ���ڷ� print�Լ� ȣ�� �̶� ������� + 1
		LCRS_printTree(_pNode->leftChild, _depth + 1);
	}

	if (_pNode->rightSibling != NULL) {		// ���� ����� ������ �ִٸ� ������带 ���ڷ� print�Լ� ȣ��
		LCRS_printTree(_pNode->rightSibling, _depth);
	}
}
void LCRS_destroyNode(LCRSNode* remove)
{
	free(remove);
}

void LCRS_destroyTree(LCRSNode* _pRoot)
{
	if (_pRoot->leftChild != NULL) {		// ���� ����� �ڽ��� �ִٸ� �ڽĳ�带 ���ڷ� destroy�Լ� ȣ��
		LCRS_destroyTree(_pRoot->leftChild);
	}
	if (_pRoot->rightSibling != NULL) {		// ���� ����� ������ �ִٸ� ������带 ���ڷ� destroy�Լ� ȣ��
		LCRS_destroyTree(_pRoot->rightSibling);
	}

	LCRS_destroyNode(_pRoot);			// �� 2������ ���� �ڽ��� �ڽĵ�� �������� ��� �����ٸ� �ڽ��� �޸� �Ҵ� ����
}

void LCRS_PrintNodesAtLevel(LCRSNode* _pRoot, int _level)
{
	if (_level > 0) {						// ��ǥ ������ �������� ���ߴٸ�
		if (_pRoot->leftChild != NULL) {	// �ڽ� ��尡 �ִٸ�
			LCRS_PrintNodesAtLevel(_pRoot->leftChild, _level-1);
		}
		if (_pRoot->rightSibling != NULL) { // ���� ��尡 �ִٸ�
			LCRS_PrintNodesAtLevel(_pRoot->rightSibling, _level);
		}
	}

	if (_level == 0) {						// �ش� ������ ���������� 
		printf("%c", _pRoot->iData);
		if (_pRoot->rightSibling != NULL) { // ���� ��尡 �ִٸ�
			LCRS_PrintNodesAtLevel(_pRoot->rightSibling, _level);
		}
	}

	//LCRSNode* currentlevNode = _pRoot;
	//for (int i = 0; i < _level; i++) {	// �ش� ������ ù��° �ڽĳ�� ã��
	//	currentlevNode = currentlevNode->leftChild;
	//	if (currentlevNode == NULL) {	// Ʈ���� ���̰� �Է¹��� �������� ���ٸ� return
	//		printf("Ʈ���� ���̰� �Է°����� �����ϴ�.");
	//		return;
	//	}
	//}
	//while (currentlevNode != NULL) {
	//	printf("�� : %c [lev=%d]\n", currentlevNode->iData, _level);
	//	currentlevNode = currentlevNode->rightSibling;
	//}
}
