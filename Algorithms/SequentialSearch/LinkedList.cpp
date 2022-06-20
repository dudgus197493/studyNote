#include <iostream>
#include "LinkedList.h";

void InitList(LinkedList* _pList)
{
	_pList->iCount = 0;
	_pList->pHeadNode = nullptr;
}

void PushBack(LinkedList* _pList, int _iData)
{
	// 1. Node를 만들고 데이터 채우기
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->iData = _iData;
	pNewNode->pNextNode = nullptr;

	// 2. 첫번째 노드인지 확인
	if (_pList->iCount == 0) {
		_pList->pHeadNode = pNewNode;
	}
	else {
		// 가장 마지막 노드를 찾아서,
		// 그 노드의 다음 노드로 자신의 주소값을 연결
		Node* pTailNode = _pList->pHeadNode;
		while (pTailNode->pNextNode) {	// bool 기준에서 null은 false / null이 아니면 true
			pTailNode = pTailNode->pNextNode;
		}
		pTailNode->pNextNode = pNewNode;
	}
	// 3. 카운트 증가
	++_pList->iCount;
}

void PushFront(LinkedList* _pList, int _iData)
{
	// 데이터 노드 생성
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->iData = _iData;						// Data 삽입
	pNewNode->pNextNode = _pList->pHeadNode;		// 새로운 노드의 next로 list의 헤드노드를 연결
	_pList->pHeadNode = pNewNode;					// 리스트의 헤드노드 포인터를 새로운 노드로 갱신
	
	
	// list의 데이터 카운트 증가
	++_pList->iCount;
}

// 재귀로 노드 메모리 free 구현 해보기
// 스택메모리가 많지 않아서 스택이 4000개 이상 쌓이면 터짐
void Release(Node* _pNode) {
	if (!_pNode) {
		return;
	}
	Release(_pNode->pNextNode);

	free(_pNode);
}




void ReleaseList(LinkedList* _pList)
{
	Node* pDelNode = _pList->pHeadNode;			// 첫번째 노드를 지울 노드로 선택
	while (pDelNode) {							// 지울노드가 null이면 break
		Node* pTmpNode = pDelNode->pNextNode;	// 첫번째 노드를 바로 지우면 그 다음 노드의 주소값을 알지 못하므로
												// 지역변수에 임시로 저장
		free(pDelNode);							// 노드 삭제
		pDelNode = pTmpNode;					// 임시로 저장했던 노드를 처형대에 올림
		
		--_pList->iCount;						// 리스트의 카운터 감소
	}
}

void printList(LinkedList* _pList)
{
	Node* current = _pList->pHeadNode;

	while (current != NULL) {
		printf("%d, ", current->iData);
		current = current->pNextNode;
	}
}
