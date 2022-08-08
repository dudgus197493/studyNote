package study.note.algorithm.practice.bruteForce;

import java.util.Scanner;

public class Back2798 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int[] cards = new int[N];
		
		for(int i =0; i<N; i++) {
			cards[i] = sc.nextInt();
		}
		for (int i =0; i< N; i++) {
			System.out.printf("Index : %d, Value : %d\n", i, cards[i]);
		}
		
		
		// 카드 3장을 합한 결과
		int result = search(cards, M, N);
		System.out.println(result);
		
	}
	
	public static int search(int[] arr, int M, int N) {
		int result = 0;
		
		for(int i =0; i<N - 2; i++) {
			for(int j = i + 1; j<N-1; j++) {
				for(int k= j + 1; k<N; k++) {
					
					int tmp = arr[i] + arr[j] + arr[k];
					
					if(M == tmp) {
						return tmp; 
					}
					
//					if(M - tmp < M - result) {				// tmp이 M에 더 가까우면
//						result = tmp;
//					}
					if(result < tmp && tmp <M) {
						result = tmp;
					}
				}
			}
		}
		return result;
	}

}
