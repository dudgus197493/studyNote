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
	// parentNode의 자식노드가 비어있는지 확인
	if (_pParentNode->leftChild == NULL) {			// 비어있다면 첫번째 자식노드(leftChild)에 _pChildNode 주소 연결
		_pParentNode->leftChild = _pChildNode;
	}
	else {
		LCRSNode* lastChildNode = _pParentNode->leftChild; // 마지막 자식노드를 발견할떄까지 반복
		while (lastChildNode->rightSibling != NULL) {
			lastChildNode = lastChildNode->rightSibling;
		}
		lastChildNode->rightSibling = _pChildNode;		   // 발견했다면 마지막 자식노드의 형제노드로 _pChildNode를 연결
	}
}

void LCRS_printTree(LCRSNode* _pNode, int _depth)
{
	// 깊이만큼 들여쓰기
	for (int i = 0; i < _depth; i++) {
		printf(" ");
	}

	// 노드에 담긴 데이터 출력
	printf("%c\n", _pNode->iData);

	if (_pNode->leftChild != NULL) {		// 현재 노드의 자식이 있다면 자식노드를 인자로 print함수 호출 이때 현재깊이 + 1
		LCRS_printTree(_pNode->leftChild, _depth + 1);
	}

	if (_pNode->rightSibling != NULL) {		// 현재 노드의 형제가 있다면 형제노드를 인자로 print함수 호출
		LCRS_printTree(_pNode->rightSibling, _depth);
	}
}
void LCRS_destroyNode(LCRSNode* remove)
{
	free(remove);
}

void LCRS_destroyTree(LCRSNode* _pRoot)
{
	if (_pRoot->leftChild != NULL) {		// 현재 노드의 자식이 있다면 자식노드를 인자로 destroy함수 호출
		LCRS_destroyTree(_pRoot->leftChild);
	}
	if (_pRoot->rightSibling != NULL) {		// 현재 노드의 형제가 있다면 형제노드를 인자로 destroy함수 호출
		LCRS_destroyTree(_pRoot->rightSibling);
	}

	LCRS_destroyNode(_pRoot);			// 위 2과정을 통해 자신의 자식들과 형제들을 모두 지웠다면 자신의 메모리 할당 해제
}

void LCRS_PrintNodesAtLevel(LCRSNode* _pRoot, int _level)
{
	if (_level > 0) {						// 목표 레벨에 도달하지 못했다면
		if (_pRoot->leftChild != NULL) {	// 자식 노드가 있다면
			LCRS_PrintNodesAtLevel(_pRoot->leftChild, _level-1);
		}
		if (_pRoot->rightSibling != NULL) { // 형제 노드가 있다면
			LCRS_PrintNodesAtLevel(_pRoot->rightSibling, _level);
		}
	}

	if (_level == 0) {						// 해당 레벨에 도착했으면 
		printf("%c", _pRoot->iData);
		if (_pRoot->rightSibling != NULL) { // 형제 노드가 있다면
			LCRS_PrintNodesAtLevel(_pRoot->rightSibling, _level);
		}
	}

	//LCRSNode* currentlevNode = _pRoot;
	//for (int i = 0; i < _level; i++) {	// 해당 레벨의 첫번째 자식노드 찾기
	//	currentlevNode = currentlevNode->leftChild;
	//	if (currentlevNode == NULL) {	// 트리의 깊이가 입력받은 레벨보다 낮다면 return
	//		printf("트리의 깊이가 입력값보다 적습니다.");
	//		return;
	//	}
	//}
	//while (currentlevNode != NULL) {
	//	printf("값 : %c [lev=%d]\n", currentlevNode->iData, _level);
	//	currentlevNode = currentlevNode->rightSibling;
	//}
}
