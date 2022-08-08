package study.note.dataStructure.linkedList;

class SingleNode {
	public Object data;
	public SingleNode nextNode;
	
	public SingleNode(Object data) {
		this.data = data;
		this.nextNode = null;
	}	
}


public class SingleLinkedList {
	private SingleNode head;
	public int size;
	
	// 생성자
	public SingleLinkedList() {
		this.head = null;
		this.size = 0;
	}
	
	// 리스트가 비어있는지 확인
	public boolean isEmpty() {
		return this.size == 0 && this.head == null; 
	}
	
	// 노드 추가
	public void appendBack(Object data) {
		SingleNode newNode = new SingleNode(data);								// 새로운 노드 생성
		if(isEmpty()) {												// LinkedList가 비어있다면
			this.head = newNode;
		} else {
			SingleNode currentNode = this.head;
			while(currentNode.nextNode != null) {					// currentNode가 LinkedList의 마지막 노드가 아니라면
				currentNode = currentNode.nextNode;					// 마지막 노드일때까지 다음노드로 갱신
			}
			currentNode.nextNode = newNode;
		}
		this.size++;
	}
	public void appendFront(Object data) {
		SingleNode newNode = new SingleNode(data);
		if(isEmpty()) {
			this.head = newNode;
		} else {
			SingleNode tmpNode = this.head;								// 현재 헤드노드를 임시 변수에 저장(tmpNode)
			
			this.head = newNode;									// 리스트의 헤드노드를 newNode로 갱신
			
			newNode.nextNode = tmpNode;								// newNode의 nextNode로 tmpNode를 지정
		}
		this.size++;
	}
	public void insertNode(Object data, int index) {
		if(index > this.size) {										// 찾고자하는 인덱스가 LinkedList의 현재 size보다 크면 리턴
			System.out.println("찾고자하는 범위가 리스트의 크기보다 큽니다");
			return;
		}
		
		SingleNode newNode = new SingleNode(data);
		if(isEmpty()) {
			this.head = newNode;
		} else {
			SingleNode currentNode = null;
			SingleNode prevNode = null;
			
			prevNode = searchNode(index - 1);						// currentNode의 앞 노드 찾기 (prevNode)
			
			currentNode = prevNode.nextNode;						// index번호에 위치한 노드 찾기(currentNode)
			
			prevNode.nextNode = newNode;							// prevNode 의 다음노드로 newNode를 연결
			
			newNode.nextNode = currentNode;							// newNode의 다음노드로 currentNode를 연결
		}
		
		// list의 size를 1 증가
		this.size++;
	}
	
	// 노드 찾기
	public SingleNode searchNode(int index) {
		if(index > this.size) {										// 찾고자하는 인덱스가 LinkedList의 현재 size보다 크면 리턴
			System.out.println("찾고자하는 범위가 리스트의 크기보다 큽니다");
			return null;
		}
		SingleNode currentNode = this.head;
		
		for(int i =0; i<index; i++) {
			currentNode = currentNode.nextNode;
		}
		
		return currentNode;
	}
	
	// 리스트 출력
	public void printList() {
		if(isEmpty()) {
			System.out.println("리스트가 비어있습니다.");
			return;
		}
		
		SingleNode currentNode = this.head;
		for(int i =0; i<this.size; i++) {
			System.out.println("Index : " + i + ", Object : " + currentNode.data);
			currentNode = currentNode.nextNode;
		}
	}
	
	public static void main(String[] args) {
		SingleLinkedList list = new SingleLinkedList();
		
		list.appendBack(23);
		list.appendBack(42);
		list.appendBack(61);
		
		list.insertNode(314, 1);
		
		list.appendFront(34234);
		
		list.printList();
		
	}

	
	
}

