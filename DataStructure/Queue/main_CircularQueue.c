#include "CircularQueue.h"
int main() {
	CircularQueue* queue = CQ_createQueue(10);

	CQ_enQueue(queue, 1);
	CQ_enQueue(queue, 2);
	CQ_enQueue(queue, 3);
	CQ_enQueue(queue, 4);

	for (int i = 0; i < 3; i++) {
		printf("Dequeue: %d, ", CQ_deQueue(queue));
		printf("Front:%d, Rear:%d\n", queue->front, queue->rear);
	}
	int i = 100;
	while (CQ_isFull(queue) == 0) {
		CQ_enQueue(queue, i++);
	}
	
	

	printf("Capacity: %d, Size: %d\n\n", queue->capacity, CQ_getSize(queue));
	
	while (CQ_isEmpty(queue) == 0) {
		printf("Dequeue: %d, ", CQ_deQueue(queue));
		printf("Front: %d, Rear:%d\n", queue->front, queue->rear);
	}

	CQ_destroyQueue(queue);
	return 0;
}