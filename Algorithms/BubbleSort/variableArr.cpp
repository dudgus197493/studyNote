#include <iostream>
#include "variableArr.h";

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int)*2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

void PushBack(tArr* _pArr, int iData)
{
	// 1. 예외 처리 - 저장공간이 꽉차있으면 공간 늘려줌
	if (_pArr->iMaxCount == _pArr->iCount) {
		Reallocate(_pArr);
	}
	// 2. 실제 데이터 저장
	_pArr->pInt[_pArr->iCount++] = iData;

	// 3. iCount증가
	/*_pArr->iCount++;*/
}

void Reallocate(tArr* _pArr)
{
	/*_pArr->iMaxCount * 2*/ // 원레 가지고 있던 저장공간의 2배
	int* tNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));
	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < _pArr->iCount; ++i) {
		tNew[i] = _pArr->pInt[i];
	}
	// 3. 기존 할당한 공간을 해제 시켜야함.
	free(_pArr->pInt);
	// 4. 배열이 새로만든 공간을 가리키게한다.
	_pArr->pInt = tNew;
	// 5. MaxCount 변경점 적용
	_pArr->iMaxCount *= 2;
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void PrintArr(tArr* _pArr)
{
	for (int i = 0; i < _pArr->iCount; i++) {
		printf("%d ",_pArr->pInt[i]);
	}
}
