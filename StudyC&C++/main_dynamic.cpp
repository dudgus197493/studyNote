#include<stdio.h>
#include<iostream>

// 변수
// 지역 - (스택)
// 전역, 정적, 외부 - (데이터)


// 메모리 영역
// 스택
// 데이터
// ROM
// 힙 영역(동적할당) 런타임중에 대응가능한 메모리영역

void Test(int a) {
	printf("%d\n", a);
}

int main() {

	int* pInt = (int*)malloc(100);
	// malloc 의 리턴값이 '보이드 포인터'형 주소값인 이유
	// ㄴ이 메모리를 어떻게 사용할지 사용자가 정할 수 있도록 하기 위해

	// 동적 할당
	// 1. 런타임 중에 대응 가능
	// 2. 사용자가 직접 관리해야함(할당 해제)

	free(pInt);		// 메모리를 풀어줌 힙 메모리 주소값을 가진 변수를 넣어줘야함
							// free로 동적할당한 메모리를 풀어주지 않으면 메모리 누수가 일어남.
	return 0;
}