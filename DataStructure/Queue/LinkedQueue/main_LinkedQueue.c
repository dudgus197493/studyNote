#include "LinkedQueue.h"
int main() {

	Node* Popped = NULL;
	LinkedQueue* Queue = createQueue();

	enQueue(Queue, "abc");
	enQueue(Queue, "def");
	enQueue(Queue, "efg");
	enQueue(Queue, "hij");
	printf("Queue Size : %d\n", Queue->usedSize);

	while (isEmpty(Queue) == 0) {
		Popped = deQueue(Queue);

		printf("Dequeue: %s \n", Popped->data);

		destroyNode(Popped);
	}
	destroyQueue(Queue);
	return 0;
}