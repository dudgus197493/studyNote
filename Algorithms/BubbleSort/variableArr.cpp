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
	// 1. ���� ó�� - ��������� ���������� ���� �÷���
	if (_pArr->iMaxCount == _pArr->iCount) {
		Reallocate(_pArr);
	}
	// 2. ���� ������ ����
	_pArr->pInt[_pArr->iCount++] = iData;

	// 3. iCount����
	/*_pArr->iCount++;*/
}

void Reallocate(tArr* _pArr)
{
	/*_pArr->iMaxCount * 2*/ // ���� ������ �ִ� ��������� 2��
	int* tNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));
	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < _pArr->iCount; ++i) {
		tNew[i] = _pArr->pInt[i];
	}
	// 3. ���� �Ҵ��� ������ ���� ���Ѿ���.
	free(_pArr->pInt);
	// 4. �迭�� ���θ��� ������ ����Ű���Ѵ�.
	_pArr->pInt = tNew;
	// 5. MaxCount ������ ����
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
