// �� ����
// ���� ���� ���� �ϳ��� '���� ����(Divide and Conquer)'�� ����� �˰���
// ���� ���� - ��ü�� �����ϴ� ���, ��ü�� �����ϴ� ���� ��ҵ��� ������ �߰� �ɰ��� ���� �����ϴ� ����.
// ����
// 1. ������ ���� ������ ������ ���� ��Ҹ� �����ϰ�, ���� ��Һ��� ���� ��ҵ��� ������ ������� ������ ���� ����� ����, ū���� ������ ��ġ
// 2. ���� ��� ������ ���ؿ�Һ��� ���� ��ҵ��� ���ְ� �������� ū ��ҵ��� ������,
// �̷��� ���� ���յ��� �ٽ� 1������ ���� ������ ���� ��Ҹ� �����ϰ� ���� ������� ���������� ����
// 3. 1�� 2�� ������ �� �̻� ������ ������ ���� �� ���� ������ �ݺ��ϸ� ���ĿϷ�

// ������
// 1. �迭������ �������� ����Ʈ�� �޸� ��Ҹ� ���� / �����ϴ� �������� ū ����� ����(�ٸ� ��ҵ��� ��ĭ�� �аų� ��ܾ� �ϱ� ����)
// 2. �ݺ��Ǵ� ���� ������ ��� ó���� ���ΰ�

// 1�� ������ �ذ�
// 1. ���ʰ� �����ʿ��� ���ÿ� �����͸� �˻��ϸ鼭 ������ ���غ���ū��, �������� ���غ��� �������� ã�´�.
// 2. ã���� ���� �����͸� ��ȯ
// 3. ���ʰ� �������� ������ ���� �����Ϳ� ���ʿ������� ����Ű�� �����͸� ��ȯ

#include<stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int dataSet[], int left, int right) {
	int first = left;				// ���ذ��� �ε����� ����
	int pivot = dataSet[first];		// ���ذ�

	++left;							// ���ذ� + 1 ���� �񱳽���

	while (left < right) {			// left�� right�� ������ �ʾҴٸ� �ݺ�
		while (dataSet[left] <= pivot) {	// left�ε����� ���� ���ذ����� Ŭ ������ �ݺ�
			if (left >= right) {
				break;
			}
			++left;
		}
		while (dataSet[right] > pivot) {	// right�ε����� ���� ���ذ����� ���� ������ �ݺ�
			--right;
		}
		if (left >= right) {		// left�� right�� �����ٸ� break;
			break;
		}
		swap(&dataSet[left], &dataSet[right]);						// left�ε����� ���� right�ε����� �� ��ȯ
	}
	// �ش����� ������ �����ٸ� �����ε����� right�ε����� �� ��ȯ
	swap(&dataSet[first], &dataSet[right]);

	// �ش� ����� ����� �ε��� ��ȯ
	return right;
}

void quickSort(int dataSet[], int left, int right) {
	if (left < right) {							  // ���� ����Ʈ�� ������ ����Ʈ�� ��ġ�� �ּ� 1�̻� ���̳���
		int index = partition(dataSet, left, right);

		quickSort(dataSet, left, index - 1);      // index�� �������� ���� ����
		quickSort(dataSet, index+1, right);	  // index�� �������� ������ ����
	}
}

int main() {

	int dataSet[] = { 6,4,2,3,1,5 };
	int length = sizeof dataSet / sizeof dataSet[0];
	quickSort(dataSet, 0, length - 1);

	for (int i = 0; i < length; i++) {
		printf("%d ", dataSet[i]);
	}

	printf("\n");


	return 0;
}