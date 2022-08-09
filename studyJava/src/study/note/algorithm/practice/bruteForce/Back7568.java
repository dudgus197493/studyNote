package study.note.algorithm.practice.bruteForce;

import java.util.Scanner;

public class Back7568 {

	public static void main(String[] args) {
		/* 입력 */
		// 5
		// 55 185
		// 58 183
		// 88 186
		// 60 175
		// 46 155
		
		/* 출력 */
		// 2 2 1 2 5
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[] weights = new int[N];
		int[] heights = new int[N];
		int[] bulkRank = new int[N];					// 자신보다 덩치가큰 사람의 수를 저장하는 배열
		
		
		for(int i =0; i<N; i++) {
			weights[i] = sc.nextInt();
			heights[i] = sc.nextInt();
		}
		
		
		
//		for(int i =0; i<N; i++) {
//			System.out.printf("Index : %d\nweights : %d, heights : %d\n", i, weights[i], heights[i]);
//		}
		
		for(int i =0; i<N - 1; i++) {
			for(int j = i + 1; j<N; j++) {
				if(weights[i] < weights[j] && heights[i] < heights[j]) {			// i가 작으면 bulkRank i번째 인덱스에 + 1
					bulkRank[i] += 1;
				} else if (weights[i] > weights[j] && heights[i] > heights[j]){		// i가 크면 bulkRank j번째 인덱스에 + 1
					bulkRank[j] += 1;
				}
			}
		} 
		
		for(int i = 0; i<N; i++) {
			System.out.printf("%d ",bulkRank[i] + 1);								// 덩치순위는 자신보다 덩치가큰 사람 + 1이므로 배열값에 + 1
		}

	}

}
