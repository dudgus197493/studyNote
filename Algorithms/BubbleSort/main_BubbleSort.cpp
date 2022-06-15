#include <stdio.h>
#include "variableArr.h"

void BubbleSort(tArr* arr) {
	int arrLen = arr->iCount;
	for (int i = 1; i < arrLen; i++) {
		for (int j = 0; j < arrLen - i; j++) {
			if (arr->pInt[j] > arr->pInt[j + 1]) {	// left가 right보다 크면 
				int tmp = arr->pInt[j + 1];			// 두 값의 위치 변경
				arr->pInt[j + 1] = arr->pInt[j];
				arr->pInt[j] = tmp;
			}
		}
	}
}
// 버블 정렬은 이미 데이터들이 정렬되어있어도 계속해서 비교연산을 진행한다.
// 이것을 계선한 버블정렬
void ImproveBubbleSort(tArr* arr) {
	int arrLen = arr->iCount;
	for (int i = 1; i < arrLen; i++) {
		bool noSwap = true;						// 외부 포문에 불갑 초기화
		for (int j = 0; j < arrLen - i; j++) {	// left가 right보다 크면 
			noSwap = false;						// 두 값의 위치 변경을 위해 if문 안으로 들어왔다면 noSwap false로 갱신
			int tmp = arr->pInt[j + 1];			// 두 값의 위치 변경
			arr->pInt[j + 1] = arr->pInt[j];
			arr->pInt[j] = tmp;
		}
		if (noSwap) {							// 한 사이클이 끝났을 때 어떠한 위치도 변경되지 않았다면 for문 탈출
			break;
		}
	}
}

int main() {
	tArr arr;

	InitArr(&arr);

	PushBack(&arr, 6);
	PushBack(&arr, 4);
	PushBack(&arr, 2);
	PushBack(&arr, 3);
	PushBack(&arr, 1);
	PushBack(&arr, 5);

	PrintArr(&arr);

	printf("\n오름차순 정렬 후 ============\n");
	BubbleSort(&arr);
	PrintArr(&arr);

	ReleaseArr(&arr);

	return 0;
}