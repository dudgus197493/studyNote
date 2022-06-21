#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char* ElementType;

typedef struct _tagNode {
	ElementType data;
	struct _tagNode* nextNode;
} Node;

typedef struct _tagLinkedQueue {
	int usedSize;
	Node* front;
	Node* rear;
}LinkedQueue;

// 큐 생성
LinkedQueue* createQueue();
// 큐 소멸
void destroyQueue(LinkedQueue* _pQueue);

// 큐 노드 넣기
void enQueue(LinkedQueue* _pQueue, ElementType _data);
// 큐 노드 꺼내기
Node* deQueue(LinkedQueue* _pQueue);

// 노드 생성
Node* createNode(ElementType _data);
// 노드 소멸
void destroyNode(Node* _pNode);

// 큐가 비어있는지 확인하는 함수
int isEmpty(LinkedQueue* _pQueue);
