package study.note.algorithm.sort;

public class CountingSort {

	// 카운팅 정렬
	// 시간 복잡도(On + k)
	
	public static void main(String[] args) {
		
		System.out.println("=============test");
		test();
		System.out.println("=============test");
		
		
		
		
		
		int[] arr = {7, 2, 3, 5, 7, 1, 4, 6, 7, 5, 0, 1 };

		// 1. 최댓값 찾기
		int maxVar = getMax(arr);
		System.out.println(maxVar);
		
		// 2. 최댓값 + 1크기의 배열 생성 (countingArray)
		int[] counting = new int[maxVar + 1];
		
		// 3. 배열의 값을 인덱스로 count배열에 ++;
		for (int i = 0; i<arr.length; i++) {
			counting[arr[i]]++;
		}
		
		printArr(counting);
		
		// 4. count배열을 누적합 배열로 변경 (arr[n+1] = arr[n] + arr[n+1)
		// -> 누적합 배열의 의미 : 누적합 배열의 값 - 1은 해당인덱스 자체의 값보다 작은 값이 누적합 배열의 값 - 1개 있다는 뜻이다.
		counting = accumulateArr(counting);
		System.out.println();
		printArr(counting);
		
		// 5. 배열의 맨 끝단부터 저장된 값을 count배열의 인덱스로 들어가 그 인덱스의 저장된값을 1씩 줄이면서
		//    정렬할 새로운 배열에 저장
		int[] resultArr = new int[arr.length];
		
		
		
		for(int i = arr.length - 1; i >= 0; i--) {				// arr의 맨 끝단부터 검사
			// arr의 해당 인덱스를 아이디로하는 count배열의 값이 0이면 건너뛰기
			if(counting[arr[i]] == 0) {
				continue;
			}
			// 그 외
			
			resultArr[--counting[arr[i]]] = arr[i];
			// arr[i]의 값을 인덱스로하는 count배열에 값을 1감소
			// 그 감소한 count배열의 값을 인덱스로 하는 result배열에 arr[i]의 값 대입
		}
		
		System.out.println("======== 정렬 전 배열 ========");
		printArr(arr);
		
		System.out.println("======== 카운팅 정렬 후 배열 ========");
		printArr(resultArr);
	}

	// 최댓값 찾기
	public static int getMax(int[] arr ) {					
		int max = arr[0];
		for(int i = 1; i<arr.length; i++) {
			if(max < arr[i]) {
				max = arr[i];
			}
		}

		return max;
	}
	
	// 배열 출력
	public static void printArr(int[] arr) {
		for(int i =0; i<arr.length; i++) {
			System.out.printf("%d ", arr[i]);
		}
		System.out.println();
	}
	
	public static int[] accumulateArr(int[] arr){
		int[] returnArr = new int[arr.length];
		
		returnArr[0] = arr[0];
		
		for(int i =0; i<arr.length - 1; i++) {
			returnArr[i+1]	= returnArr[i] + arr[i+1];
		}
		return returnArr;
	}
	
	public static void test() {
		int[] testArr = {1, 2, 3};
		int[] printArr = {1, 2, 3};
		
		System.out.println("testArr[1] : " + testArr[1]);
		System.out.println(printArr[--testArr[1]]); 		// 2
		printArr(testArr);
	}
	
	
}
