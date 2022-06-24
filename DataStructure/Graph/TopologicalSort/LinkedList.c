#include "LinkedList.h";

void InitList(LinkedList* _pList)
{
	_pList->iCount = 0;
	_pList->pHeadNode = NULL;
}

void PushBack(LinkedList* _pList, Vertex* _Data)
{
	// 1. Node�� ����� ������ ä���
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = _Data;
	pNewNode->pNextNode = NULL;

	// 2. ù��° ������� Ȯ��
	if (_pList->iCount == 0) {
		_pList->pHeadNode = pNewNode;
	}
	else {
		// ���� ������ ��带 ã�Ƽ�,
		// �� ����� ���� ���� �ڽ��� �ּҰ��� ����
		Node* pTailNode = _pList->pHeadNode;
		while (pTailNode->pNextNode) {	// bool ���ؿ��� null�� false / null�� �ƴϸ� true
			pTailNode = pTailNode->pNextNode;
		}
		pTailNode->pNextNode = pNewNode;
	}
	// 3. ī��Ʈ ����
	++_pList->iCount;
}

void PushFront(LinkedList* _pList, Vertex* _Data)
{
	// ������ ��� ����
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = _Data;						// Data ����
	pNewNode->pNextNode = _pList->pHeadNode;		// ���ο� ����� next�� list�� ����带 ����
	_pList->pHeadNode = pNewNode;					// ����Ʈ�� ����� �����͸� ���ο� ���� ����
	
	
	// list�� ������ ī��Ʈ ����
	++_pList->iCount;
}

// ��ͷ� ��� �޸� free ���� �غ���
// ���ø޸𸮰� ���� �ʾƼ� ������ 4000�� �̻� ���̸� ����
void Release(Node* _pNode) {
	if (!_pNode) {
		return;
	}
	Release(_pNode->pNextNode);

	free(_pNode);
}




void ReleaseList(LinkedList* _pList)
{
	Node* pDelNode = _pList->pHeadNode;			// ù��° ��带 ���� ���� ����
	while (pDelNode) {							// �����尡 null�̸� break
		Node* pTmpNode = pDelNode->pNextNode;	// ù��° ��带 �ٷ� ����� �� ���� ����� �ּҰ��� ���� ���ϹǷ�
												// ���������� �ӽ÷� ����
		free(pDelNode);							// ��� ����
		pDelNode = pTmpNode;					// �ӽ÷� �����ߴ� ��带 ó���뿡 �ø�
		
		--_pList->iCount;						// ����Ʈ�� ī���� ����
	}
}
