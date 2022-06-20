#include "LinkedList.h"
// ���� Ž���� �⺻(������ ����Ʈ Ȱ��)
int SequentialSearch(LinkedList* _pList, int _target) {
	Node* current = _pList->pHeadNode;
	while (current != NULL) {
		if (current->iData == _target) {
			printf("���ϴ� ���� ã�ҽ��ϴ�.\n");
			return current->iData;
		}
		current = current->pNextNode;
	}
	printf("���ϴ� ���� ã�� ���߽��ϴ�.\n");
	return -1;
}

// �ڱ� ���� ���� Ž��(Self-Organizing Sequential Search)
// ����ã�� �׸�, ���� ����ϴ� �׸���� �ٸ� �׸񺸴� �켱�Ͽ� ������ �� �ְ� ��ġ
// 1. ���� �̵���(Move To Front)
// - ��� �׸��� �ѹ� Ž������ ����, �� �׸��� ������ ������ ���� �տ� ��ġ��Ű�� ���
// - �ѹ� Ž���� �׸��� �� �̾ �� �ٽ� �˻��� ���ɼ��� ���� ������ ���տ����� ���
Node* MovetoFront(LinkedList* list, int _target) {
	Node* current = list->pHeadNode;
	Node* prev = NULL;

	while (current != NULL) {				// �����尡 NULL�϶����� �ݺ�
		if (current->iData == _target) {	// �����尡 Ÿ�ٰ� ��ġ�ϸ�
			break;
		}
		prev = current;						// ������带 ������� ����
		current = current->pNextNode;		// �����带 �������� ����
	}

	if (prev == NULL) {						// ã�� ��尡 ����� �� ��
		return current;
	}
	else {									// ã�� ��尡 ����尡 �ƴ� ��													
		prev->pNextNode = current->pNextNode; // ã�� ����� nextNode�� ���� ����� nextNode�� ����
		current->pNextNode = list->pHeadNode; // ����带 ã�� ����� nextNode�� ����Ű��
		list->pHeadNode = current;			  // ã����带 ����Ʈ�� ������ ����Ŵ
		return current;
	}
}

// 2. ������
// - Ž���� �׸��� �ٷ� ���� �׸�� ��ȯ
// - Ž���� �׸��� ������ ������ �ű�µ� ����, �������� '����' Ž���� �׸��� ���������� ������ �ű�
// - ���� Ž���Ǵ� �׸���� ������ ������ �������� ���̰� ��
// - "���� ������ �޴� �����͸� ������ ������ �������� ������"

Node* Transpose(LinkedList* _pList, int _target) {
	Node* current = _pList->pHeadNode;
	Node* prev = NULL;
	Node* pprev = NULL;
	
	while (current != NULL) {							// �����尡 NULL�϶����� �ݺ�
		if (current->iData == _target) {				// �����尡 Ÿ�ٰ� ��ġ�ϸ� break;
			if (prev != NULL) {							// ó���ؾ��� prev��尡 ������
				if (pprev != NULL) {					// pprev��尡 ������
					pprev->pNextNode = current;			// pprev�� �������� ������ ����
				}
				else {									// pprev�� ������ list�� ������ �����带 ����
					_pList->pHeadNode = current;
				}
														// prev�� current�� �ڸ��ٲ� ��ó��
				prev->pNextNode = current->pNextNode;	// prev�� ������带 current�� �������� ����
				current->pNextNode = prev;				// current�� ������带 prev�� ����
			}
			break;
		}
		pprev = prev;						// ��ĭ�� ������ ����
		prev = current;
		current = current->pNextNode;
	}
	return current;
}
void Test_MovetoFront() {
	LinkedList list;
	InitList(&list);

	PushBack(&list, 2);
	PushBack(&list, 23);
	PushBack(&list, 6);
	PushBack(&list, 9);
	PushBack(&list, 7);
	PushBack(&list, 29);

	printList(&list);
	Node* searchNode = MovetoFront(&list, 9);
	printf("ã�� ������ : %d\n", searchNode->iData);
	printList(&list);

	ReleaseList(&list);
}

void Test_Transpose() {
	LinkedList list;
	InitList(&list);

	PushBack(&list, 2);
	PushBack(&list, 23);
	PushBack(&list, 6);
	PushBack(&list, 9);
	PushBack(&list, 7);
	PushBack(&list, 29);

	Node* searchNode = NULL;

	printList(&list);
	printf("\n");

	searchNode = Transpose(&list, 9);
	printf("ã�� ������ : %d\n", searchNode->iData);
	printList(&list);
	printf("\n");

	searchNode = Transpose(&list, 9);
	printf("ã�� ������ : %d\n", searchNode->iData);
	printList(&list);
	printf("\n");

	searchNode = Transpose(&list, 9);
	printf("ã�� ������ : %d\n", searchNode->iData);
	printList(&list);
	printf("\n");

	ReleaseList(&list);
}

int main() {
	
	Test_Transpose();
	return 0;
}