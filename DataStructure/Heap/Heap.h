#include<stdio.h>
#include<stdlib.h>
typedef struct _tagHeapNode {
	int iData;
} HeapNode;

typedef struct _tagHeap {
	HeapNode* nodes;			// 힙 노드 배열
	int capacity;				// 힙 노드 배열 맥스 사이즈
	int usedSize;				// 힙 노드 배열 사용중인 사이즈
} Heap;

// 힙 생성
Heap* H_createHeap(int _initSize);
// 힙 노드 삽입
void H_insert(Heap* _pHeap, int _newData);

// 힙 최솟값 삭제 & 반환
void H_delMinNode(Heap* _pHeap, HeapNode* _pRoot);

// 부모 노드 위치 반환 
int H_getParent(int _index);

// 부모 자식 위치 변경
void H_swapNodes(Heap* _pHeap, int currentPos, int parentPos);

// 왼쪽 자식 인덱스 반환 - 왼쪽자식만 구하면 반환값에 +1로 오른쪽 자식 인덱스도 구할 수 있음
int H_getLeftChildPos(int _index);

// 힙 모든 노드 출력
void H_printAllNodes(Heap* _pHeap);

// 힙 삭제
void H_destroyHeap(Heap* _pHeap);
