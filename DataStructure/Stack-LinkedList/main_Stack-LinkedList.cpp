#include "Stack-LinkedList.h"

int main() {

	Node* popped;

	LinkedListStack* stack = LLS_createStack();
	LLS_push(stack, "���");
	LLS_push(stack, "����");
	LLS_push(stack, "������");
	LLS_push(stack, "����");

	printf("Size: %d, Top: %s\n\n", stack->count, LLS_top(stack)->Data);

	while (!LLS_isEmpty(stack)) {
		popped = LLS_pop(stack);
		printf("Popped: %s, ", popped->Data);
		LLS_destroyNode(popped);

		if (!LLS_isEmpty(stack)) {
			printf("Current Top: %s\n", LLS_top(stack)->Data);
		}
		else {
			printf("Stack Is Empty");
		}
	}

	LLS_destroyStack(stack);
	return 0;
}