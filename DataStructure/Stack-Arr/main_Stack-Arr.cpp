#include "Stack-Arr.h"
int main() {

	int i = 0;
	ArrayStack* stack = AS_createStack(5);

	AS_push(stack, 3);
	AS_push(stack, 37);
	AS_push(stack, 11);
	AS_push(stack, 12);
	
	printf("Capacity: %d, Size: %d, Top: %d\n", stack->capacity, AS_getSize(stack), AS_top(stack));

	printf("Is the stack full ? : %d\n", AS_isFull(stack));


	while (true) {
		if (AS_isEmpty(stack)) {
			break;
		}

		printf("Popped: %d, ",AS_pop(stack));

		if (!AS_isEmpty(stack)) {
			printf("Current Top: %d\n", AS_top(stack));
		}
		else {
			printf("Stack Is Empty");
		}

	}

	AS_destroyStack(stack);

	return 0;
}