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
	// 전위순회 - 루트->왼쪽하위트리->오른쪽하위트리
	if (_pNode == NULL) {
		return;
	}

	// 루트 노드 출력
	printf("%c ", _pNode->iData);

	// 왼쪽 하위 트리 출력
	SBT_preorderPrintTree(_pNode->leftChild);

	// 오른쪽 하위 트리 출력
	SBT_preorderPrintTree(_pNode->rightChild);
}

void SBT_inorderPrintTree(SBTNode* _pNode)
{
	// 중위순회 - 왼쪽하위트리->루트->오른쪽하위트리
	if (_pNode == NULL) {
		return;
	}

	// 왼쪽 하위 트리 출력
	SBT_inorderPrintTree(_pNode->leftChild);

	// 루트 노드 출력
	printf("%c ", _pNode->iData);

	// 오른쪽 하위 트리 출력
	SBT_inorderPrintTree(_pNode->rightChild);
}

void SBT_postorderPrintTree(SBTNode* _pNode)
{
	// 후위순회 - 왼쪽하위트리->오른쪽하위트리->루트
	if (_pNode == NULL) {
		return;
	}

	// 왼쪽 하위 트리 출력
	SBT_postorderPrintTree(_pNode->leftChild);

	// 오른쪽 하위 트리 출력
	SBT_postorderPrintTree(_pNode->rightChild);

	// 루트 노드 출력
	printf("%c ", _pNode->iData);
}

void SBT_destroyTree(SBTNode* _pRoot)
{
	if (_pRoot == NULL) {
		return;
	}
	// 왼쪽 하위 트리 삭제
	SBT_destroyTree(_pRoot->leftChild);

	// 오른쪽 하위 트리 삭제
	SBT_destroyTree(_pRoot->rightChild);

	// 자신의 모든 하위트리를 삭제했으면 자신 삭제
	SBT_destroyNode(_pRoot);
}
