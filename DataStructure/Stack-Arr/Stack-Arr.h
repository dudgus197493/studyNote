// 스택 (Stack)
// 처음에 들어간 데이터가 가장 마지막에 나오는 자료구조
// FILO(First Input Last Out) or LIFO(Last Input First Out)
// 요소의 삽입과 삭제가 자료구조의 한쪽 끝에서만 이루어짐
// 중간에 데이터를 삽입하거나 삭제하는것을 허락하지 않음

// 배열을 이용하여 구현한 스택
// 장점
// 구현이 간단함
// 단점
// 동적으로 스택의 용량을 조절하기 어렵다는 단점이있음
// 스택 생성 초기에 사용자가 붕한 용량만큼의 노드를 한꺼번에 생성후 최상위 노드의 위치를 나타내는 변수를 이용해 삽입/제거 연산 수행

#include <stdio.h>
#include <stdlib.h>
typedef struct _tagNode {
	int Data;
} Node;

typedef struct _tagArrayStack {
	int capacity;			// 스택의 용량
	int top;				// 최상위 노드의 위치
	Node* nodes;			// 노드들을 저장할 배열
} ArrayStack;

// 스택 생성
ArrayStack* AS_createStack(int _initSize);

// 스택 소멸
void AS_destroyStack(ArrayStack* _remove);

// 삽입 연산
void AS_push(ArrayStack* _pStack, int newData);

// 제거 연산
int AS_pop(ArrayStack* _pStack);

// 스택의 사이즈 확인 연산 - top멤버가 곧 사이즈
int AS_getSize(ArrayStack* _pStack);

// 최상위 노드 확인 연산
int AS_top(ArrayStack* _pStack);

// 스택이 꽉차있는지 확인
int AS_isFull(ArrayStack* _pStack);

// 스택이 비어있는지 확인
int AS_isEmpty(ArrayStack* _pStack);