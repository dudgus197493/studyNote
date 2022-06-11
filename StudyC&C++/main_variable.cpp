#include<stdio.h>

// 변수의 종류
//1. 지역변수
//2. 전역변수
//3. 정적변수
//4. 외부변수

// 메모리 영역
//1. 스택영역 (지역변수)
//2. 데이터 영역 (전역변수, 정적변수, 외부변수)
//3. 읽기 전용(코드, ROM)
//4. 힙 영역


// 전역 변수
int g_i = 0; // Data 영역

// 정적(파일에서 움직이지 않음) 변수

// Data영역 특징 
//1. 프로그램 시작 시 생성
//2. 프로그램 종료 시 해제
//		ㄴ> 프로그램 실행하는 동안 계속 존재
#include "func.h"; // 해당 파일의 코드를 이 파일로 복붙;
#include "common.h";

static int global_i = 0;
int g_iExtern;
int Test() {
	static int i = 0; // 함수 안의 정적 (데이터 영역 사용)
					  // 함수 안에서만 사용 가능하나 스택영역이 아닌 데이터 영역을 사용하므로 함수 호출이 끝나도 변수는 사라지지 않는다.
					  // 함수안에 정적변수를 초기화를 하면 다음변 함수를 호출했을때 조기화 구문은 건너 뛴다.
	++i;

	return i;
}

int main() {

	/*Test();
	Test();
	Test();
	Test();
	int iCall = Test();
	printf("%d", iCall);*/
	g_iExtern = 300;

	Add(0, 0);

	return 0;
}
