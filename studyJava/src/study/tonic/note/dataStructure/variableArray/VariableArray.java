package sutdy.tonic.note.dataStructure.variableArray;

public class VariableArray {
	private Object[] arr;
	public int capacity;
	public int usedSize;
	
	// 기본 생성자
	public VariableArray(int initSize) {
		this.arr = new Object[initSize];
		this.capacity = initSize;
		this.usedSize = 0;
	}
	
	// 요소 추가
	public void add(Object obj) {
		if(this.usedSize >= this.capacity) {
			reSize();
		}
		this.arr[this.usedSize] = obj;
		this.usedSize++;
	}
	
	// 가져 오기
	public Object get(int index) {
		return this.arr[index];
	}
	
	// 출력 함수
	public void printArray() {
		for(int i =0; i<this.capacity; i++) {
			System.out.println("Index : " + i + ", Object : " + this.arr[i]);
		}
	}
	
	
	
	// 리사이징 함수
	private void reSize() {
		Object[] tmpArr = this.arr;
		this.capacity *= 2;
		
		this.arr = new Object[this.capacity];
		for(int i = 0; i<this.usedSize; i++) {
			this.arr[i] = tmpArr[i];
		}
		tmpArr = null;
	}
	public static void main(String[] args) {
		VariableArray arr = new VariableArray(3);
		arr.add(33);
		arr.add(53);
		arr.add(23);
		arr.add(22);
		arr.printArray();
		
		int result = (int)arr.get(2);
		System.out.println("result : " + result);
	}
}

