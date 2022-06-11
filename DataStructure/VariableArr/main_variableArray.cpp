#include <iostream>
#include "variableArr.h";
int main() {
	// 가변 배열
	int a = 100;

	/*int arr[a] = {};*/		// 지역변수 메모리가 동적으로 바뀔 수 없다. 컴파일 오류
								// 배열 개수를 선언할 때에는 변수를 사용 할 수 없다.

	tArr arr;
	
	InitArr(&arr);

	for (int i = 0; i < 10; ++i) {
		PushBack(&arr, i);
	}
	
	for (int i = 0; i < arr.iCount; ++i) {
		printf("%d\n", arr.pInt[i]);
	}

	ReleaseArr(&arr);

	return 0;
}