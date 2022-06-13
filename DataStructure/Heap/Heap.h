#include<stdio.h>
#include<stdlib.h>
typedef struct _tagHeapNode {
	int iData;
} HeapNode;

typedef struct _tagHeap {
	HeapNode* nodes;			// �� ��� �迭
	int capacity;				// �� ��� �迭 �ƽ� ������
	int usedSize;				// �� ��� �迭 ������� ������
} Heap;

// �� ����
Heap* H_createHeap(int _initSize);
// �� ��� ����
void H_insert(Heap* _pHeap, int _newData);

// �� �ּڰ� ���� & ��ȯ
void H_delMinNode(Heap* _pHeap, HeapNode* _pRoot);

// �θ� ��� ��ġ ��ȯ 
int H_getParent(int _index);

// �θ� �ڽ� ��ġ ����
void H_swapNodes(Heap* _pHeap, int currentPos, int parentPos);

// ���� �ڽ� �ε��� ��ȯ - �����ڽĸ� ���ϸ� ��ȯ���� +1�� ������ �ڽ� �ε����� ���� �� ����
int H_getLeftChildPos(int _index);

// �� ��� ��� ���
void H_printAllNodes(Heap* _pHeap);

// �� ����
void H_destroyHeap(Heap* _pHeap);
