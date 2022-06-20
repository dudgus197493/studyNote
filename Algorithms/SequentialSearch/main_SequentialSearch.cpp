#include "LinkedList.h"
// 순차 탐색의 기본(연결형 리스트 활용)
int SequentialSearch(LinkedList* _pList, int _target) {
	Node* current = _pList->pHeadNode;
	while (current != NULL) {
		if (current->iData == _target) {
			printf("원하는 값을 찾았습니다.\n");
			return current->iData;
		}
		current = current->pNextNode;
	}
	printf("원하는 값을 찾지 못했습니다.\n");
	return -1;
}

// 자기 구성 순차 탐색(Self-Organizing Sequential Search)
// 자주찾는 항목, 자주 사용하는 항목들을 다른 항목보다 우선하여 접근할 수 있게 배치
// 1. 전진 이동법(Move To Front)
// - 어느 항목이 한번 탐새괴고 나면, 그 항목을 데이터 집합의 가장 앞에 위치시키는 방법
// - 한번 탐색된 항목이 곧 이어서 또 다시 검색될 가능성이 높은 데이터 집합에서만 사용
Node* MovetoFront(LinkedList* list, int _target) {
	Node* current = list->pHeadNode;
	Node* prev = NULL;

	while (current != NULL) {				// 현재노드가 NULL일때까지 반복
		if (current->iData == _target) {	// 현재노드가 타겟과 일치하면
			break;
		}
		prev = current;						// 이전노드를 현재노드로 갱신
		current = current->pNextNode;		// 현재노드를 다음노드로 갱신
	}

	if (prev == NULL) {						// 찾은 노드가 헤드노드 일 때
		return current;
	}
	else {									// 찾은 노드가 헤드노드가 아닐 때													
		prev->pNextNode = current->pNextNode; // 찾은 노드의 nextNode를 이전 노드의 nextNode로 갱신
		current->pNextNode = list->pHeadNode; // 헤드노드를 찾은 노드의 nextNode로 가리키고
		list->pHeadNode = current;			  // 찾은노드를 리스트의 헤드노드로 가리킴
		return current;
	}
}

// 2. 전위법
// - 탐색된 항목을 바로 이전 항목과 교환
// - 탐색된 항목을 무조건 앞으로 옮기는데 반해, 전위법은 '자주' 탐색된 항목을 점진적으로 앞으로 옮김
// - 자주 탐색되는 항목들이 데이터 집합의 앞쪽으로 모이게 됨
// - "많은 선택을 받는 데이터를 데이터 집합의 앞쪽으로 보낸다"

Node* Transpose(LinkedList* _pList, int _target) {
	Node* current = _pList->pHeadNode;
	Node* prev = NULL;
	Node* pprev = NULL;
	
	while (current != NULL) {							// 현재노드가 NULL일때까지 반복
		if (current->iData == _target) {				// 현재노드가 타겟과 일치하면 break;
			if (prev != NULL) {							// 처리해야할 prev노드가 있으면
				if (pprev != NULL) {					// pprev노드가 있으면
					pprev->pNextNode = current;			// pprev의 다음노드로 현재노드 갱신
				}
				else {									// pprev가 없으면 list의 헤드노드로 현재노드를 갱신
					_pList->pHeadNode = current;
				}
														// prev와 current의 자리바꿈 후처리
				prev->pNextNode = current->pNextNode;	// prev의 다음노드를 current의 다음노드로 갱신
				current->pNextNode = prev;				// current의 다음노드를 prev로 갱신
			}
			break;
		}
		pprev = prev;						// 한칸씩 앞으로 갱신
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
	printf("찾은 데이터 : %d\n", searchNode->iData);
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
	printf("찾은 데이터 : %d\n", searchNode->iData);
	printList(&list);
	printf("\n");

	searchNode = Transpose(&list, 9);
	printf("찾은 데이터 : %d\n", searchNode->iData);
	printList(&list);
	printf("\n");

	searchNode = Transpose(&list, 9);
	printf("찾은 데이터 : %d\n", searchNode->iData);
	printList(&list);
	printf("\n");

	ReleaseList(&list);
}

int main() {
	
	Test_Transpose();
	return 0;
}