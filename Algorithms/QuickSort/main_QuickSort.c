// 퀵 정렬
// 전쟁 전략 중의 하나인 '분할 정복(Divide and Conquer)'에 기반한 알고리즘
// 분할 정복 - 전체를 공략하는 대신, 전체를 구성하는 구성 요소들을 나누어 잘게 쪼개진 적을 공략하는 전법.
// 구현
// 1. 데이터 집합 내에서 임의의 기준 요소를 선택하고, 기준 요소보다 작은 요소들은 순서에 관계없이 무조건 기준 요소의 왼편에, 큰값은 오른편에 위치
// 2. 기준 요소 왼편에는 기준요소보다 작은 요소들이 모여있고 오른편에는 큰 요소들이 모여있음,
// 이렇게 나눈 집합들을 다시 1에서와 같이 임의의 기준 요소를 선택하고 같은 방법으로 데이터집합 분할
// 3. 1과 2의 과정을 더 이상 데이터 집합을 나눌 수 없을 때까지 반복하면 정렬완료

// 문제점
// 1. 배열에서의 퀵정렬은 리스트와 달리 요소를 삽입 / 삭제하는 과정에서 큰 비용이 생김(다른 요소들을 한칸씩 밀거나 당겨야 하기 때문)
// 2. 반복되는 분할 과정을 어떻게 처리할 것인가

// 1번 문제점 해결
// 1. 왼쪽과 오른쪽에서 동시에 데이터를 검사하면서 왼쪽은 기준보다큰값, 오른쪽은 기준보다 작은값을 찾는다.
// 2. 찾으면 서로 데이터를 교환
// 3. 왼쪽과 오른쪽이 만나면 기준 데이터와 왼쪽오른쪽이 가리키는 데이터를 교환

#include<stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int dataSet[], int left, int right) {
	int first = left;				// 기준값의 인덱스를 저장
	int pivot = dataSet[first];		// 기준값

	++left;							// 기준값 + 1 부터 비교시작

	while (left < right) {			// left와 right가 만나지 않았다면 반복
		while (dataSet[left] <= pivot) {	// left인덱스의 값이 기준값보다 클 때까지 반복
			if (left >= right) {
				break;
			}
			++left;
		}
		while (dataSet[right] > pivot) {	// right인덱스의 값이 기준값보다 작을 때까지 반복
			--right;
		}
		if (left >= right) {		// left와 right가 만났다면 break;
			break;
		}
		swap(&dataSet[left], &dataSet[right]);						// left인덱스의 값과 right인덱스의 값 교환
	}
	// 해당블록의 정렬이 끝났다면 기준인덱스와 right인덱스의 값 교환
	swap(&dataSet[first], &dataSet[right]);

	// 해당 블록의 가운대 인덱스 반환
	return right;
}

void quickSort(int dataSet[], int left, int right) {
	if (left < right) {							  // 왼쪽 포인트와 오른쪽 포인트의 위치가 최소 1이상 차이나면
		int index = partition(dataSet, left, right);

		quickSort(dataSet, left, index - 1);      // index를 기준으로 왼쪽 정렬
		quickSort(dataSet, index+1, right);	  // index를 기준으로 오른쪽 정렬
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