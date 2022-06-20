#include <stdio.h>


// 가변배열과 연결형 리스트는 겉보기는 유사하지만
// 가변 배열은 힙 메모리에 연속된 메모리를 잡아놓고
// 데이터를 저장한다.

// 연결형 리스트는 데이터를 추가할때마다 힙 메모리 어딘가에 데이터를 저장하고
// 데이터(노드)끼리 연결한다.

typedef struct _tagNode {
	int iData;					// 자신이 가지는 데이터
	_tagNode* pNextNode;		// 자신의 다음 노드(데이터)
} Node;


typedef struct _tagList {
	int iCount;					// 연결형 리스트의 데이터 갯수

	// int iMaxCount;			// 한번에 메모리공간을 잡고 데이터를 추가하는 배열과 다르게
								// 링크드 리스트는 데이터를 추가할때마다 메모리를 할당하므로 저장공간의 한계가 없다.
	
	Node* pHeadNode;			// 리스트 자신이 노드(데이터)가 아니므로
								// 노드들을 확인하려면 첫번째 노드의 주소를 알고 있어햐 한다.

} LinkedList;

// 리스트 초기화 함수
void InitList(LinkedList* _pList);

// 연결형 리스트 데이터 추가
void PushBack(LinkedList* _pList, int _iData);

void PushFront(LinkedList* _pList, int _iData);

// 리스트 메모리 해제
void ReleaseList(LinkedList* _pList);

// 리스트 출력
void printList(LinkedList* _pList);