package study.tonic.note.dataStructure.queue;


class LinkedNode {
	public Object data;
	public LinkedNode nextNode;
	
	
	// 기본 생성자
	public LinkedNode (Object data) {
		this.data = data;
		this.nextNode = null;
	}
}

public class LinkedQueue {
	private LinkedNode front;
	public int size;
	
	// 기본 생성자
	public LinkedQueue() {
		this.front = null;
		
		this.size = 0;
	}
	
	// 노드 추가
	public void enQueue(Object data) {
		LinkedNode newNode = new LinkedNode(data);
		
		if(isEmpty()) {									// 큐가 비어있다면
			// 노드추가후 헤드노드 갱신
			this.front = newNode;
			
		} else {										// 큐가 비어있지 않다면
			// 큐의 꼬리노드를 찾기
			LinkedNode rearNode = this.front;
			
			while(rearNode.nextNode != null) {
				rearNode = rearNode.nextNode;
			}
			
			// 꼬리노드의 nextNode로 newNode 연결
			rearNode.nextNode = newNode;
		}
		this.size++;
	}
	
	// 노드 제거
	public LinkedNode deQueue() {
		if(isEmpty()) {							// 큐가 비어있다면
			System.out.println("큐가 비어있습니다.");
			return null;						// null 리턴
		}
		LinkedNode pop = this.front;
		
		// 큐의 front를 현재 front의 nextNode로 갱신
		this.front = this.front.nextNode;
		this.size--;
		
		return pop;
		
	}
	
	
	// 큐 출력
	public void printQueue() {
		LinkedNode currentNode = this.front;
		
		for(int i =0; i<this.size; i++) {
			System.out.println("Data : " + currentNode.data);
			currentNode = currentNode.nextNode;
		}
	}
	
	// Empty 확인
	public boolean isEmpty() {
		return this.size == 0 && this.front == null;
	}
	
	public static void main(String[] args) {
		LinkedQueue queue = new LinkedQueue();
		
		queue.enQueue(1423);
		queue.enQueue(31);
		queue.enQueue(12);
		queue.enQueue(414);
		
		queue.printQueue();
		
		LinkedNode pop = queue.deQueue();
		System.out.println("Pop : " + pop.data);
		System.out.println("Size : " + queue.size);
		
		queue.printQueue();
	}
}
