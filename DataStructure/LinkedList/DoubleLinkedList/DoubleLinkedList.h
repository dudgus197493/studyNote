#include<iostream>
typedef struct _tagNode {
	// 자신의 앞 노드
	_tagNode* prevNode;
	// 자신의 뒷 노드
	_tagNode* nextNode;
	// 데이터
	int iData;
} Node;

typedef struct _tagDoubleLinkedList {
	// 헤드 노드
	Node* headNode;
	// 테일 노드
	Node* tailNode;
	// 저장 되어 있는 데이터 카운트
	unsigned int count;
} DoubleLinkedList;

// list 생성
DoubleLinkedList* DLL_createList();

// 노드 생성 / 소멸
Node* createNode(int _data);
void destroyNode(Node* _pTarget);

// 노드 추가
void DLL_appendBack(DoubleLinkedList* _pList, int _data);
void DLL_appendFront(DoubleLinkedList* _pList, int _data);

// 노드 탐색	- 기존 LinkedList와 다르게 양방향 탐색을 할 수 있어 발생비용을 2배 절약 할수 있다.
Node* DLL_searchNode(DoubleLinkedList* _pList, unsigned int _index);

// 노드 삽입
void DLL_insertNode(DoubleLinkedList* _pList, int _data, int _index);

// 리스트 모든 데이터 출력
void DLL_printAllNode(DoubleLinkedList* _pList);
// 리스트 삭제
void DLL_destroyList(DoubleLinkedList* _pList);
