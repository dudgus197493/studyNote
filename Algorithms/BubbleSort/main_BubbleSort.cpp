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