#include <iostream>
#include "variableArr.h";
int main() {
	// ���� �迭
	int a = 100;

	/*int arr[a] = {};*/		// �������� �޸𸮰� �������� �ٲ� �� ����. ������ ����
								// �迭 ������ ������ ������ ������ ��� �� �� ����.

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