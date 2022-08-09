package study.note.algorithm.practice.bruteForce;

import java.util.Scanner;

public class Back1436 {

	public static void main(String[] args) {
		// 영화감독 숌
		test();
//		test2();
	}

	public static void test() {
		
		Scanner sc = new Scanner(System.in);
		
		String targetStr = "666";
		int N = sc.nextInt();
		int count = 1;
		
		if(N == 1) {
			System.out.println(666);
			return;
		}
		
		
		int i = 667;
		while(true) {
			if(String.valueOf(i).contains(targetStr)) {
				count++;
			}
			if(N == count) {
				System.out.println(i);
				break;
			}
			i++;
		}
	}
	public static void test2() {
		String targetStr = "666";
		int i = 1666;
		
		if(String.valueOf(i).contains(targetStr)) {
			System.out.println("포함합니다.");
		}
		
		
	}
}
