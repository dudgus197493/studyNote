#include<stdio.h>
#include<iostream>

// ����
// ���� - (����)
// ����, ����, �ܺ� - (������)


// �޸� ����
// ����
// ������
// ROM
// �� ����(�����Ҵ�) ��Ÿ���߿� ���������� �޸𸮿���

void Test(int a) {
	printf("%d\n", a);
}

int main() {

	int* pInt = (int*)malloc(100);
	// malloc �� ���ϰ��� '���̵� ������'�� �ּҰ��� ����
	// ���� �޸𸮸� ��� ������� ����ڰ� ���� �� �ֵ��� �ϱ� ����

	// ���� �Ҵ�
	// 1. ��Ÿ�� �߿� ���� ����
	// 2. ����ڰ� ���� �����ؾ���(�Ҵ� ����)

	free(pInt);		// �޸𸮸� Ǯ���� �� �޸� �ּҰ��� ���� ������ �־������
							// free�� �����Ҵ��� �޸𸮸� Ǯ������ ������ �޸� ������ �Ͼ.
	return 0;
}