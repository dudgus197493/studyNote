package study.tonic.note.dataStructure.queue;

public class CircularQueue {
	private Object[] queue;
	public int front;
	public int rear;
	public int capacity;
	public int usedSize;
	
	
	public CircularQueue(int initSize) {
		this.queue = new Object[initSize + 1];								// 큐가 포화상태임을 나타내기위한 자리 한개를 추가 생성
		this.capacity = initSize;
		this.usedSize = 0;
		this.front = 0;
		this.rear = 0;
		
	}
	
	// 데이터 추가
	public void enQueue(Object data) {
		if(isFull()) {														// 큐가 포화상태라면
			System.out.println("큐가 가득 차있습니다.");
			return;
		}
		
		this.queue[rear++] = data;
		if(this.rear >= this.capacity) {											// rear커서가 capacity 보다 크다면  
			this.rear = 0;														// 배열 인덱스 0으로 리셋											
		}
		this.usedSize++;
		
	}
	
	// 데이터 삭제
	public Object deQueue() {
		if(isEmpty()) {
			System.out.println("큐가 비어있습니다.");
			return null;
		}
		// front인덱스에 있는 요소 반환
		// front인덱스 1 증가
		Object pop = this.queue[front];
		this.queue[front++] = null;
		this.usedSize--;
		if(front > this.capacity) {											// front커서가 capacity 보다 크다면
			this.front = 0;
		}
		return pop;
	}
	
	
	// 큐 출력
	public void printQueue() {
		System.out.printf("Capacity : %d, UsedSize : %d\n", this.capacity, this.usedSize);
		for(int i =0; i<this.capacity; i++) {
			System.out.println("Index : " + i + ", Data : " + this.queue[i]);
		}
	}
	// Empty확인
	public boolean isEmpty() {
		return this.front == this.rear;   							// front커서와 rear커서가 같은 인덱스를 가리키면 true;
	}
	
	// full 확인
	public boolean isFull() {
		if(this.front < this.rear) {								// front커서가 rear커서보다 앞에 있을 때
			return this.rear - this.front == this.capacity;			// rear커서 - front커서의 값이 큐의 총 용량과 같으면 true;			
		} else if(this.front > this.rear) {							// front커서가 rear커서보다 뒤에 있을 때
			return this.front - this.rear == 1;						// front커서 - rear커서의 값이 1이면 true;
		} else {
			return false;											// 그 외 경우 false;
		}
	}
	
	public static void main(String[] args) {
		CircularQueue queue = new CircularQueue(5);
		
		queue.enQueue(1);
		queue.enQueue(2);
		queue.enQueue(3);
		queue.deQueue();
		queue.deQueue();
		queue.printQueue();
		
		queue.enQueue(4);
		queue.enQueue(5);
		System.out.printf("Front : %d, Rear : %d\n", queue.front, queue.rear);
		

		
		
		queue.enQueue(6);
		queue.printQueue();
		
	}

}
