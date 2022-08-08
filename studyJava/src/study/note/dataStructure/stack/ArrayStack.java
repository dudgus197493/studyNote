package study.note.dataStructure.stack;


// 가변 배열을 이용한 스택 구현
public class ArrayStack {
	private Object[] arr;
	private int top;
	public int capacity;
	public int usedSize;
	
	public ArrayStack(int initSize) {
		this.arr = new Object[initSize];
		this.capacity = initSize;
		this.usedSize = 0;
		this.top = 0;
	}
	
	public static void main(String[] args) {
		
	}
	
	
}
