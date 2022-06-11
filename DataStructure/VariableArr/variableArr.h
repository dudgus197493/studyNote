#pragma once
typedef struct _tabArr {
	int* pInt;			// 힙 메모리의 주소
	int		iCount;			// 현재 힙 메모리의 데이터 수
	int		iMaxCount;		// 현재 최대 수용가능한 데이터 수
} tArr;

//tArr 초기화 함수
void InitArr(tArr* _pArr);

// 데이터 추가 함수
void PushBack(tArr* _pArr, int iData);

// 공간 추가 확장 함수
void Reallocate(tArr* _pArr);		// 메모리를 할당할때 내가 원하는 곳을 할당받을 수 없다.
									// 그래서 이미 사용하고 있는 힙 메모리에 추가로 메모리를 연결해서 할당할 수 없다.
									// 결국 가변 배열의 크기를 늘리려면 원레 있던 사이즈보다 더큰 사이즈의 메모리를 다시 할당하고 
									// 그 새롭게 할당한 메모리에 원레 있던 데이터들을 옮긴 후
									// 원레 있던 메모리를 릴리즈한다.

//tArr 메모리 해제 함수
void ReleaseArr(tArr* _pArr);