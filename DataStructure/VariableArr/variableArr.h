#pragma once
typedef struct _tabArr {
	int* pInt;			// �� �޸��� �ּ�
	int		iCount;			// ���� �� �޸��� ������ ��
	int		iMaxCount;		// ���� �ִ� ���밡���� ������ ��
} tArr;

//tArr �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr);

// ������ �߰� �Լ�
void PushBack(tArr* _pArr, int iData);

// ���� �߰� Ȯ�� �Լ�
void Reallocate(tArr* _pArr);		// �޸𸮸� �Ҵ��Ҷ� ���� ���ϴ� ���� �Ҵ���� �� ����.
									// �׷��� �̹� ����ϰ� �ִ� �� �޸𸮿� �߰��� �޸𸮸� �����ؼ� �Ҵ��� �� ����.
									// �ᱹ ���� �迭�� ũ�⸦ �ø����� ���� �ִ� ������� ��ū �������� �޸𸮸� �ٽ� �Ҵ��ϰ� 
									// �� ���Ӱ� �Ҵ��� �޸𸮿� ���� �ִ� �����͵��� �ű� ��
									// ���� �ִ� �޸𸮸� �������Ѵ�.

//tArr �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);