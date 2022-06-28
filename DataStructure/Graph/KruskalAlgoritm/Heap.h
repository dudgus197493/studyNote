#include<stdio.h>
#include<stdlib.h>
typedef struct _tagPQNode {
	void* Data;
	int priority;
} PQNode;

typedef struct _tagPriorityQueue {
	PQNode* nodes;			// 큐 노드 배열
	int capacity;				// 큐 노드 배열 맥스 사이즈
	int usedSize;				// 큐 노드 배열 사용중인 사이즈
} PriorityQueue;

// 큐 생성
PriorityQueue* PQ_createQueue(int _initSize);
// 큐 노드 삽입
void PQ_enQueue(PriorityQueue* _pPQ, PQNode _newNode);

// 큐 최솟값 삭제 & 반환
void PQ_deQueue(PriorityQueue* _pPQ, PQNode* _pRoot);

// 부모 노드 위치 반환 
int H_getParent(int _index);

// 부모 자식 위치 변경
void H_swapNodes(PriorityQueue* _pPQ, int currentPos, int parentPos);

// 왼쪽 자식 인덱스 반환 - 왼쪽자식만 구하면 반환값에 +1로 오른쪽 자식 인덱스도 구할 수 있음
int H_getLeftChildPos(int _index);

// 큐 모든 노드 출력
void PQ_printAllNodes(PriorityQueue* _pPQ);

// 큐 삭제
void PQ_destroyQueue(PriorityQueue* _pPQ);

// 비어있는지 확인
int isEmpty(PriorityQueue* _pPQ);	// 정의 수정 필요
