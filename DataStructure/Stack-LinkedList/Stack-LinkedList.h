// 링크드 리스트를 이용하여 구현한 스택
// 배열과 다르게 스택의 용량에 제한을 두지 않아도 됨 - capacity 멤버 필요없음
// 링크드 리스트는 인덱스연산으로 노드에 접근할 수 없음	- top 멤버 필요없음
// 따라서 스택을 구현하려면 자신의 위에 위치하는 노드(nextNode)에 대한 포인터를 갖고 있어야 함.


#include <stdio.h>
#include <stdlib.h>

typedef struct _tagNode {
	char* Data;
	_tagNode* nextNode;
} Node;

typedef struct _tagLinkedListStack {
	int count;
	Node* head;					// 리스트가 노드에 접근할 수 있게 노드의 헤드를 알고있어야 함
	Node* top;					// 리스트로치면 꼬리노드 - 이것을 알고있으면 4byte를 지불하여 꼬리노드를 알기위해 순차탐색이라는 비용을 지불하지 않아도 됨
} LinkedListStack;


// 스택 생성
LinkedListStack* LLS_createStack();
// 스택 소멸
void LLS_destroyStack(LinkedListStack* _pStack);

// 스택 노드 추가
void LLS_push(LinkedListStack* _pStack, const char* _newData);
// 스택 노드 제거
Node* LLS_pop(LinkedListStack* _pStack);

// 노드 생성
Node* LLS_createNode(const char* _newData);
// 노드 소멸
void LLS_destroyNode(Node* _remove);


// 스택의 최상위 노드 확인
Node* LLS_top(LinkedListStack* _pStack);

// 스택의 현재 노드 수 확인
int LLS_getSize(LinkedListStack* _pStack);

// 스택이 비었는지 확인
int LLS_isEmpty(LinkedListStack* _pStack);
