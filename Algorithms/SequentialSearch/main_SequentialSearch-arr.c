#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ����Ž�� - �迭�� �����غ���.

// ����Ž�� ����
int ARR_SequentialSearch(int* _pArr, int _target, int _len) {
	
	for (int i = 0; i < _len; i++) {
		if (_pArr[i] == _target) {
			return _pArr[i];
		}
	}
	printf("ã���� �ϴ� �����Ͱ� �����ϴ�.");
	return -1;
}

void printArr(int* _pArr, int _len) {

	for (int i = 0; i < _len; i++) {
		printf("%d ", _pArr[i]);
	}
	printf("\n");
}

// ���� �̵���
int ARR_MovetoFront(int* _pArr, int _target, int _len) {

	int match = 0;
	for (int i = 0; i < _len; i++) {
		if (_pArr[i] == _target) {
			match = _pArr[i];
			memmove(&_pArr[1], &_pArr[0], sizeof(int)*(i-0));
			_pArr[0] = match;
			return match;
		}
	}
	printf("ã���� �ϴ� �����Ͱ� �����ϴ�.");
	return -1;
}

void Test_MovetoFront() {
	int arr[6] = { 2, 13, 23, 3, 4, 6 };

	printArr(arr, 6);


	int iSearch = ARR_MovetoFront(arr, 3, 6);
	printf("%d�˻�===========\n", iSearch);
	printArr(arr, 6);
	printf("%d\n", iSearch);

	iSearch = ARR_MovetoFront(arr, 6, 6);
	printf("%d�˻�===========\n", iSearch);
	printArr(arr, 6);
	printf("%d\n", iSearch);

	iSearch = ARR_MovetoFront(arr, 23, 6);
	printf("%d�˻�===========\n", iSearch);
	printArr(arr, 6);
	printf("%d\n", iSearch);
}

// ������
int ARR_Transpose(int* _pArr, int _target, int _len) {
	int preIndex = -1;
	int match = 0;
	for (int i = 0; i < _len; i++) {
		if (_pArr[i] == _target) {							// Ÿ���� ã���� ��
			int match = _pArr[i];
			if (preIndex > -1) {
				int tmp = 0;
				tmp = _pArr[i];
				_pArr[i] = _pArr[preIndex];
				_pArr[preIndex] = tmp;
				return match;
			}
		}
		preIndex++;
	}
	printf("ã���� �ϴ� �����Ͱ� �����ϴ�.");
}

void Test_Transpose() {
	int arr[6] = { 2, 13, 23, 3, 4, 6 };

	printArr(arr, 6);

	int iSearch = ARR_Transpose(arr, 3, 6);
	printf("%d�˻�===========\n", iSearch);
	printArr(arr, 6);
	printf("%d\n", iSearch);

	iSearch = ARR_Transpose(arr, 6, 6);
	printf("%d�˻�===========\n", iSearch);
	printArr(arr, 6);
	printf("%d\n", iSearch);

	iSearch = ARR_Transpose(arr, 23, 6);
	printf("%d�˻�===========\n", iSearch);
	printArr(arr, 6);
	printf("%d\n", iSearch);

}

int main() {
	/*printf("MovetoMove Algorithm...\n");
	Test_MovetoFront();

	printf("\n\n");*/

	printf("Transpose Algorithm...\n");
	Test_Transpose();

	return 0;
}