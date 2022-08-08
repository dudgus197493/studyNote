package study.tonic.note.dataStructure.linkedList;

class DoubleNode{
	public Object data;
	public DoubleNode prevNode;									// 앞 노드
	public DoubleNode nextNode;									// 다음 노드
	
	// 생성자
	public DoubleNode(Object data) {
		this.data = data;
		this.prevNode = null;
		this.nextNode = null;
	}
}


public class DoubleLinkedList {
	private DoubleNode head;									// 리스트의 처음 노드
	public DoubleNode tail;									// 리스트의 마지막 노드
	public int size;											// 리스트의 크기(노드 갯수)
	
	// 생성자
	public DoubleLinkedList() {
		this.head = null;
		this.tail = null;
		this.size = 0;
	}
	
	// 맨앞 노드 추가
	public void appendFront(Object data) {
		DoubleNode newNode = new DoubleNode(data);
	
		// 리스트가 비어있으면
		if(isEmpty()) {
			this.head = newNode;
			this.tail = newNode;
		} else {
			// 현재 헤드노드의 prevNode에 newNode를 저장
			this.head.prevNode = newNode;
			
			// newNode의 nextNode에 현재 헤드노드를 저장
			newNode.nextNode = this.head;
			
			// 리스트의 헤드노드를 newNode로 갱신
			this.head = newNode;
		}
		
		this.size++;
	}
	
	// 맨뒤 노드 추가
	public void appendBack(Object data) {
		DoubleNode newNode = new DoubleNode(data);
		
		// 리스트가 비어있으면
		if(isEmpty()) {
			this.head = newNode;
			this.tail = newNode;
		} else {
			// 현재 꼬리노드의 nextNode에 newNode를 저장
			this.tail.nextNode = newNode;
			
			// newNode의 prevNode에 현재 꼬리노드를 저장
			newNode.prevNode = this.tail;

			// 리스트의 꼬리노드를 newNode로 갱신
			this.tail = newNode;
		}
		this.size++;
	}
	
	// 사이에 노드 추가
	public void insertNode(Object data, int index) {
		// 예외 처리
		if(index > this.size) {
			System.out.println("찾는 범위가 리스트의 크기보다 큽니다.");
			return;
		}
		
		DoubleNode newNode = new DoubleNode(data);
		// 리스트가 비어있으면
		if(isEmpty()) {
			this.head = newNode;
			this.tail = newNode;
		} else {
			return;
		}
		
	}
	
	
	// 노드 탐색
	public DoubleNode searchNode(int index) {
		
		// 예외 처리
		if(index > this.size) {						// index가 리스트의 크기보다 크면
			return null;							// null 반환
		}
		
		DoubleNode currentNode;
		if(index <= this.size / 2) {				// index가 리스트의 중간보다 작으면
			System.out.println("중간보다 작음");
			currentNode = this.head;				// 리스트의 헤드노드부터 탐색
			for(int i =0; i<index; i++) {
				currentNode = currentNode.nextNode;
			}
			
		} else {
			System.out.println("중간보다 큼");
			currentNode = this.tail;				// 리스트의 꼬리노드부터 탐색
			int count = this.size - (index + 1);	
			
			for(int i =0; i<count; i++) {
				currentNode = currentNode.prevNode;
			}
		}
		
		
		return currentNode;
	}
	
	
	// 리스트 출력
	public void printList() {
		
		DoubleNode currentNode = this.head;
		for(int i =0; i<this.size; i++) {
			System.out.println("Index : " + i + ", Data : " + currentNode.data);
			currentNode = currentNode.nextNode;
		}
	}
	
	// 리스트 빈 상태 확인
	private boolean isEmpty() {
		return this.head == null && this.tail == null && this.size == 0;
	}
	
	public static void main(String[] args) {
		DoubleLinkedList list = new DoubleLinkedList();
		
		list.appendBack(1);
		list.appendBack(2);
		list.appendBack(3);
		list.appendBack(4);
		list.appendBack(5);
		list.appendBack(6);
		list.appendBack(7);
		list.appendBack(8);
		list.appendBack(9);
		list.appendBack(10);
		
		list.printList();
		
		DoubleNode searchNode = list.searchNode(9);
		
		System.out.println("searchNode : " + searchNode.data);
	}

}
