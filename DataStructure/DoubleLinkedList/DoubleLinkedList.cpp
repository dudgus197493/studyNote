#include"DoubleLinkedList.h";

DoubleLinkedList* DLL_createList()
{
	DoubleLinkedList* newList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	newList->headNode = NULL;
	newList->tailNode = NULL;
	newList->count = 0;

	return newList;
}

Node* createNode(int _data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->prevNode = NULL;
	newNode->nextNode = NULL;
	newNode->iData = _data;
	return newNode;
}

void destroyNode(Node* _pTarget)
{
	free(_pTarget);
}

void DLL_appendBack(DoubleLinkedList* _pList, int _data)
{
	// 노드 생성
	Node* newNode = createNode(_data); 
	if (_pList->count == 0) {						// 리스트가 비어있을 때
		_pList->headNode = newNode;
		_pList->tailNode = newNode;
	}
	else {											// 비어있지 않을 때
		_pList->tailNode->nextNode = newNode;		// 1. list의 꼬리 노드의 nextNode로 newNode를 연결
		newNode->prevNode = _pList->tailNode;		// 2. newNode의 prevNode로 list의 꼬리노드를 연결
		_pList->tailNode = newNode;					// 3. list의 꼬리 노드를 newNode로 갱신
	}
	_pList->count++;								// list의 데이터 카운트 증가
}

void DLL_appendFront(DoubleLinkedList* _pList, int _data)
{
	// 노드 생성
	Node* newNode = createNode(_data);
	if (_pList->count == 0) {						// 리스트가 비어있을 때
		_pList->headNode = newNode;
		_pList->tailNode = newNode;
	}
	else {											// 비어있지 않을 때
		_pList->headNode->prevNode = newNode;		// 1. list의 헤드 노드의 prevNode로 newNode를 연결
		newNode->nextNode = _pList->headNode;		// 2. newNode의 nextNode로 list의 헤드노드를 연결
		_pList->headNode = newNode;					// 3. list의 헤드노드를 newNode로 갱신
	}
	_pList->count++;
}

Node* DLL_searchNode(DoubleLinkedList* _pList, unsigned int _index)
{
	// 예외 처리 - 찾고자 하는 인덱스가 _pList 데이터의 총 갯수 보다 클때 return
	if (_index > _pList->count) {
		printf("인덱스 범위 초과 [범위 : %d, 입력값 : %d]", _pList->count, _index);
		return NULL;
	}

	int midIndex = _pList->count / 2;				// list에 저장되어있는 데이터의 중간 인덱스를 구함
	Node* pCurrentNode;
	if (_index <= midIndex) {						// 찾고자하는 노드의 인덱스가 중간 인덱스보다 작거나 같을 때	
		pCurrentNode = _pList->headNode;			// list의 헤드노트부터 서치
		for (int i = 0; i < _index; i++) {
			pCurrentNode = pCurrentNode->nextNode;
		}
	}
	else {											// 찾고자하는 노드의 인덱스가 중간 인덱스보다 클 때
		pCurrentNode = _pList->tailNode;			// list의 꼬리노트부터 서치
		for (int i = 0; i < _index; i++) {
			pCurrentNode = pCurrentNode->prevNode;
		}
	}
	return pCurrentNode;
}

void DLL_insertNode(DoubleLinkedList* _pList, int _data, int _index)
{
	
	Node* newNode = createNode(_data);					// 새로운 노드 생성
	
	Node* targetNode = DLL_searchNode(_pList, _index);	// index에 있는 노드 찾기(새로들어갈 노드의 nextNode가 될 노드)

	Node* indexPrev = targetNode->prevNode;				// index에 있는 노드의 prev노드 찾기(새로들어갈 노드의 prevNode가 될 노드)

	indexPrev->nextNode = newNode;						// prev와 newNode를 서로 연결
	newNode->prevNode = indexPrev;

	newNode->nextNode = targetNode;						// newNode와 next를 서로 연결
	targetNode->prevNode = newNode;
	_pList->count++;									// 리스트 데이터 카운트 증가
}

void DLL_printAllNode(DoubleLinkedList* _pList)
{
	Node* printNode = _pList->headNode;					// 헤드 노드부터 출력
	for (int i = 0; i < _pList->count; i++) {
		printf("%d. : %d\n", i, printNode->iData);
		printNode = printNode->nextNode;
	}
	printf("데이터 갯수 : %d\n", _pList->count);
}

void DLL_destroyList(DoubleLinkedList* _pList)
{
	
	Node* removeNode = _pList->headNode;				// 리스트의 헤드노드부터 반복하며 메모리 할당 해제
	while (_pList->count != 0) {						// count가 0이 되면 반복종료
		Node* tmpNode = removeNode->nextNode;			// 삭제하기전 삭제할 노드의 다음 노드를 임시 변수에 저장
		free(removeNode);							// 노드 삭제
		removeNode = tmpNode;							// 임시로 저장한 노드를 다음 삭제할 노드로 갱신

		--_pList->count;								// 리스트의 데이터 디스카운트
	}
	if (_pList->count == 0) {							// count가 0이면 list자신 메모리 할당 해제
		free(_pList);
		printf("리스트가 삭제되었습니다.");
	}
}
