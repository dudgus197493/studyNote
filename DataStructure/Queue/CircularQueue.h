// 순환 큐 
// 배열의 가용용량 부족 문제를 해결 하기 위해 배열의 끝과 시작을 이어붙여 만든다.
// 물리적로 붙이는것은 불가능하나 큐의 전단과 후단위치를 기억하여 개념적으로 붙일 수 있다.
// 큐의 데이터가 제거 될때마다 전단의 위치 옮김
// 큐의 데이터가 추가 될때마다 후단의 위치 옮김
// 후단이 뒤로 후퇴하다가 전단과 만나게되면 가득찬 상태
// 문제점
// 순환 큐는 비어 있는 상태와 가득 찬 상태를 구분할 수 없다.
// 해결
// 큐 배열을 생성할 때 실제의 용량보다 1만큼 더 크게 만들어서 전단과 후단(실제의 후단) 사이를 비우는 것
//	ㄴ> 비어있을때 전단과 후단이 같은 곳을 가리킴, 가득 차 있을때 후단이 전단보다 1작은값을 가짐

#include <stdio.h>
#include<stdlib.h>

typedef struct _tagNode {
	int iData;
}Node;

typedef struct _tagCircularQueue {
	int capacity;					// 용량
	int rear;						// 전단의 인덱스
	int front;						// 후단의 인덱스
	Node* nodes;						// 노드 배열
} CircularQueue;

// 큐 생성
CircularQueue* CQ_createQueue(int _initSize);
// 큐 소멸
void CQ_destroyQueue(CircularQueue* _pQueue);

// 큐 데이터 삽입
void CQ_enQueue(CircularQueue* _pQueue, int _newData);

// 큐 데이터 제거
int CQ_deQueue(CircularQueue* _pQueue);

// 큐 공백 확인
int CQ_isEmpty(CircularQueue* _pQueue);

// 큐 포화 확인
int CQ_isFull(CircularQueue* _pQueue);

// 큐 현제 데이터수 확인
int CQ_getSize(CircularQueue* _pQueue);