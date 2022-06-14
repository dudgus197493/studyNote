#include <stdio.h>
#include "variableArr.h"

void BubbleSort(tArr* arr) {
	int arrLen = arr->iCount;
	for (int i = 1; i < arrLen; i++) {
		for (int j = 0; j < arrLen - i; j++) {
			if (arr->pInt[j] > arr->pInt[j + 1]) {	// left�� right���� ũ�� 
				int tmp = arr->pInt[j + 1];			// �� ���� ��ġ ����
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

	printf("\n�������� ���� �� ============\n");
	BubbleSort(&arr);
	PrintArr(&arr);

	ReleaseArr(&arr);

	return 0;
}