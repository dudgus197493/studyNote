package study.note.dataStructure.stack;


// 가변 배열을 이용한 스택 구현
public class  ArrayStack {
	private int[] arr;
	private int top;
	public int capacity;
	
	public ArrayStack (int initSize) {
		this.arr = new int[initSize];
		this.capacity = initSize;
		this.top = 0;
		this.top = 0;
	}
	
	// 스택 추가
	public void push(int data) {
		// 스택이 이미 가득 차있는지 확인
		if(this.top >= this.capacity - 1) {				// 배열 재할당
			reallocate1();	
		}
		this.arr[top++] = data;
	}
	
	
	// 스택 제거
	public int pop() {
		// 스택 비어있으면 리턴
		if(isEmpty()){
			System.out.println("스택이 비어있습니다.");
			return -1;
		}
		
		int pop = this.arr[top - 1];
		this.arr[top - 1] = 0;
		this.top--;
		return pop;
	}
	
	// 스택 데이터 출력
	public void printStack() {
		System.out.println("Top : " +this.top);
		for(int i =0; i<this.capacity; i++){
			System.out.printf("Index : %d, Value : %d\n", i, this.arr[i]);
		}
	}
	
	// 스택 데이터 유무 확인
	public boolean isEmpty() {
		return this.top == 0 && this.top == 0;					// 사이즈, top커서가 0이면 true
	}
	
	
	// 스택 배열 공간 재할당 (증가)
	public void reallocate1() {
		
		// 임시 배열 생성 후 데이터 저장
		int[] temp = this.arr;
		
		// 스택 용량 2배 증가
		this.capacity *= 2;
		
		// arr멤버에 배열 크기 재할당 
		this.arr = new int[this.capacity];
		
		// 데이터 복사
		for(int i =0; i<this.top; i++) {
			this.arr[i] = temp[i];
		}
		temp = null;
	}
	
	// 스택 배열 공간 재할당 (감소)
	public void reallocate2() {
		
		// 임시 배열 생성 후 데이터 저장
		int[] temp = this.arr;
		
		// 스택 용량 2배 감소
		this.capacity /= 2;
		
		// arr멤버에 배열 크기 재할당 
		this.arr = new int[this.capacity];
		
		for(int i = 0; i<this.top; i++) {
			this.arr[i] = temp[i];
		}
		temp = null;
	}
	
	// 사용중인 스택 크기 반환
	public int getSize() {

		return this.top;
	}
	
	public static void main(String[] args) {
		
		ArrayStack stack = new ArrayStack(5);
		
		stack.push(1);
		stack.push(2);
		stack.push(3);
		stack.push(4);
		stack.push(5);
		System.out.println("데이터 추가후 ===============");
		stack.printStack();
		
		
//		stack.pop();
//		stack.pop();
//		stack.pop();
//		stack.pop();
//		stack.pop();
//		System.out.println("데이터 삭제후 ===============");
//		stack.printStack();
		
		for(int i =0; i<5; i++) {		
			int poped = stack.pop();
			System.out.printf("Index : %d, poped : %d\n", i, poped);
		}
		stack.printStack();
	}
}
