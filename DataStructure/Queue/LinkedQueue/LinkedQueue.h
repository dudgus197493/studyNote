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

// ť ����
LinkedQueue* createQueue();
// ť �Ҹ�
void destroyQueue(LinkedQueue* _pQueue);

// ť ��� �ֱ�
void enQueue(LinkedQueue* _pQueue, ElementType _data);
// ť ��� ������
Node* deQueue(LinkedQueue* _pQueue);

// ��� ����
Node* createNode(ElementType _data);
// ��� �Ҹ�
void destroyNode(Node* _pNode);

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
int isEmpty(LinkedQueue* _pQueue);
