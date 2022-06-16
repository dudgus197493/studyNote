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
	// ��� ����
	Node* newNode = createNode(_data); 
	if (_pList->count == 0) {						// ����Ʈ�� ������� ��
		_pList->headNode = newNode;
		_pList->tailNode = newNode;
	}
	else {											// ������� ���� ��
		_pList->tailNode->nextNode = newNode;		// 1. list�� ���� ����� nextNode�� newNode�� ����
		newNode->prevNode = _pList->tailNode;		// 2. newNode�� prevNode�� list�� ������带 ����
		_pList->tailNode = newNode;					// 3. list�� ���� ��带 newNode�� ����
	}
	_pList->count++;								// list�� ������ ī��Ʈ ����
}

void DLL_appendFront(DoubleLinkedList* _pList, int _data)
{
	// ��� ����
	Node* newNode = createNode(_data);
	if (_pList->count == 0) {						// ����Ʈ�� ������� ��
		_pList->headNode = newNode;
		_pList->tailNode = newNode;
	}
	else {											// ������� ���� ��
		_pList->headNode->prevNode = newNode;		// 1. list�� ��� ����� prevNode�� newNode�� ����
		newNode->nextNode = _pList->headNode;		// 2. newNode�� nextNode�� list�� ����带 ����
		_pList->headNode = newNode;					// 3. list�� ����带 newNode�� ����
	}
	_pList->count++;
}

Node* DLL_searchNode(DoubleLinkedList* _pList, unsigned int _index)
{
	// ���� ó�� - ã���� �ϴ� �ε����� _pList �������� �� ���� ���� Ŭ�� return
	if (_index > _pList->count) {
		printf("�ε��� ���� �ʰ� [���� : %d, �Է°� : %d]", _pList->count, _index);
		return NULL;
	}

	int midIndex = _pList->count / 2;				// list�� ����Ǿ��ִ� �������� �߰� �ε����� ����
	Node* pCurrentNode;
	if (_index <= midIndex) {						// ã�����ϴ� ����� �ε����� �߰� �ε������� �۰ų� ���� ��	
		pCurrentNode = _pList->headNode;			// list�� ����Ʈ���� ��ġ
		for (int i = 0; i < _index; i++) {
			pCurrentNode = pCurrentNode->nextNode;
		}
	}
	else {											// ã�����ϴ� ����� �ε����� �߰� �ε������� Ŭ ��
		pCurrentNode = _pList->tailNode;			// list�� ������Ʈ���� ��ġ
		for (int i = 0; i < _index; i++) {
			pCurrentNode = pCurrentNode->prevNode;
		}
	}
	return pCurrentNode;
}

void DLL_insertNode(DoubleLinkedList* _pList, int _data, int _index)
{
	
	Node* newNode = createNode(_data);					// ���ο� ��� ����
	
	Node* targetNode = DLL_searchNode(_pList, _index);	// index�� �ִ� ��� ã��(���ε� ����� nextNode�� �� ���)

	Node* indexPrev = targetNode->prevNode;				// index�� �ִ� ����� prev��� ã��(���ε� ����� prevNode�� �� ���)

	indexPrev->nextNode = newNode;						// prev�� newNode�� ���� ����
	newNode->prevNode = indexPrev;

	newNode->nextNode = targetNode;						// newNode�� next�� ���� ����
	targetNode->prevNode = newNode;
	_pList->count++;									// ����Ʈ ������ ī��Ʈ ����
}

void DLL_printAllNode(DoubleLinkedList* _pList)
{
	Node* printNode = _pList->headNode;					// ��� ������ ���
	for (int i = 0; i < _pList->count; i++) {
		printf("%d. : %d\n", i, printNode->iData);
		printNode = printNode->nextNode;
	}
	printf("������ ���� : %d\n", _pList->count);
}

void DLL_destroyList(DoubleLinkedList* _pList)
{
	
	Node* removeNode = _pList->headNode;				// ����Ʈ�� �������� �ݺ��ϸ� �޸� �Ҵ� ����
	while (_pList->count != 0) {						// count�� 0�� �Ǹ� �ݺ�����
		Node* tmpNode = removeNode->nextNode;			// �����ϱ��� ������ ����� ���� ��带 �ӽ� ������ ����
		free(removeNode);							// ��� ����
		removeNode = tmpNode;							// �ӽ÷� ������ ��带 ���� ������ ���� ����

		--_pList->count;								// ����Ʈ�� ������ ��ī��Ʈ
	}
	if (_pList->count == 0) {							// count�� 0�̸� list�ڽ� �޸� �Ҵ� ����
		free(_pList);
		printf("����Ʈ�� �����Ǿ����ϴ�.");
	}
}
