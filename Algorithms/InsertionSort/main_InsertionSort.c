// 삽입 정렬
// 데이터 집합을 순회하면서 정렬이 필요한 요소를 뽑아내어 이를 다시 적당한 곳에 삽입해 나가는 알고리즘.
// 버블 정렬보단 무조건 삽입 정렬이 좋다.
// 구현
// 1. 데이터 집합에서 정렬 대상이 되는 요소들을 선택. 이 정렬 대상은 왼쪽부터 선택해 나가며, 
// 그 범위가 처음에는 2개지만, 알고리즘 반복 횟수가 늘어날 때마다 1개씩 커짐. 
// 정렬 대상의 최대 범위는 '데이터 집합의 크기 - 1' 이 된다.

// 2. 정렬 대상의 가장 오른쪽에 있는 요소가 정렬 대상 중 가장 큰 값을 갖고 있는지 확인.
// 만약 그렇지 않다면, 이 요소를 정렬 대상에서 뽑아내고, 이 요소가 위치할 적절한 곳을 정렬 대상 내에서 찾음.
// 적절한 곳이라 함은, 데이터 집합의 가장 왼쪽을 기준으로 했을 때 자신보다 더 작은 요소가 없는 위치를 말함.

// 3. 뽑아 든 요소를 삽입할 적절한 곳을 찾았다면, 정렬 대상 내에서 삽입할 값보다 큰 값을 갖는 모든 요소를 한 자리씩 오른쪽으로 이동
// (이러면 요소가 뽑힌 자리가 채워지고, 새로이 위치할 곳이 비워짐), 새로 생긴 빈 자리에 삽입.

// 4. 전체 데이터 집합의 정렬이 완료될 떄까지 1~3을 반복.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertionSort(int dataSet[], int length) {
	for (int i = 1; i < length; i++) {				// n - 1 만큼 반복
		if (dataSet[i] >= dataSet[i - 1]) {
			continue;
		}
		// 정렬할 데이터 저장
		int value = dataSet[i];

		// 반복문 돌면서 데이터가 들어갈 위치 찾기
		for (int j = 0; j < i; j++) {
			// 데이터보다 j 인덱스의 값이 더 크다면 그곳이 데이터가 들어갈 자리
			if (value < dataSet[j]) {
				// 데이터가 들어갈 자리부터 데이터가 원레 있던 자리만큼의 메모리를 한칸 앞으로 이동
				memmove(&dataSet[j+1], &dataSet[j], sizeof(dataSet[0]) * (i-j));
				// 데이터 정렬
				dataSet[j] = value;
				break;
			}
		}
	}
}


int main() {
	printf("Hello World");
	int dataSet[] = { 6, 4, 2, 3, 1, 5 };
	int length = sizeof(dataSet) / sizeof(dataSet[0]);
		
	insertionSort(dataSet, length);

	for (int i = 0; i < length; i++) {
		printf("%d ", dataSet[i]);
	}

	printf("\n");

	return 0;
}