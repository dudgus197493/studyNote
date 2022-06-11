#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include <cassert>

// wsclen �Լ� ���� �����غ���
unsigned int GetLength(const wchar_t* _pStr) {							// ��ȯ�� ������ ������ ������ �� �����Ƿ� unsigned �� ����
	// ���� ���� üũ
	int i = 0;

	// �ι��ڰ� ���ö����� �ݺ��ؼ� ī��Ʈ
	//while (true) {
	//	wchar_t c = *(_pStr + i); // -> wchar_t c = *(_pStr[1])
	//	if (c == 0) {			  // 0 == '\0'
	//		break;
	//	}			
	//	++i;
	//}
	while (_pStr[i] != '\0') {
		++i;
	}
	return i;
}

// wcscat_s�Լ� ���� �����غ���
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc) {
	// ���� ���� ���� �ִ������ �Ű������� �Է¹޴� ����
		// �� ������� ������ �ִ������ 100 �̰�
		//	  �̹� ������ 50�� ���ִµ�
		//    70�� �� ���̷� �ϸ� �ȵǱ⶧���� �̸� ��������

	// 1. ���� ó��
	// �̾���� ���� ���ڿ� ���̰�, ���� ���� ������ �Ѿ���� ���
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);
	if (_iBufferSize < iDestLen + iSrcLen + 1) // Null ���� �������� ���
	{
		assert(nullptr);
	}

	// 2. ���ڿ� �̾���̱�
	// 1) Null ������ ��ġ ã�� ( ���ڿ��� �̾���� ���� ��ġ)
	/*iDestLen;*/
	// 2) �ݺ������� Src ���ڿ��� Dest �� ��ġ�� �����ϱ�
	for (int i = 0; i < iSrcLen; ++i) { //_pSrc�� �� ���ڱ��� �������� ���� +1 �� ����
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int CompareStr(const wchar_t* _pStrA, const wchar_t* _pStrB) {
	int iStrALen = GetLength(_pStrA);
	int iStrBLen = GetLength(_pStrB);
	int iShorter = (iStrALen < iStrBLen ? iStrALen : iStrBLen);	

	// 2. ù���ں��� �ݺ������� ���ؼ� ������ continue
	// �ٸ��� 1, -1 ����
	//  1) �ݺ������� ���ڿ��� ���� (�� ���ڿ��� ª�� ���ڿ��� �ݺ� ��������)
	for (int i = 0; i < iShorter + 1; ++i) {
		if ((int)_pStrA[i] > (int)_pStrB[i]) {
			return -1;
		}
		else if ((int)_pStrA[i] < (int)_pStrB[i]) {
			return 1;
		}
	}
	// 3. �ݺ����� ���������� ���������� (�� ���ڿ��� ���ٴ� ���� ����)
	// 4. �� ���ڰ� ������ �� ª�� ���ڿ��� �켱
	if (iStrALen < iStrBLen) {	// A�� �� ª����
		return -1;
	}
	else if (iStrALen > iStrBLen) {	// B�� �� ª����
		return 1;
	}
	else {
		return 0;
	}
	
}

int main() {
	wchar_t szName[10] = L"Raimond";

	// ���ڿ� ���� ���ϱ�
	// int iLen = wcslen(szName);
	int iLen = GetLength(szName);	// iLen�� 7�� �޾ƾ���

	

	// ���ڿ� �̾� ���̱�
	wchar_t szString[100] = L"abc";
	/*wcscat_s(szString, 100, L"def");
	wcscat_s(szString, 100, L"ghi");*/

	StrCat(szString, 100, L"def");



	int iCmp1 = CompareStr(L"agc", L"abc");		// -1
	int iCmp2 = CompareStr(L"abc", L"abf");		// 1
	int iCmp3 = CompareStr(L"abcsdf", L"abc");	// -1
	int iCmp4 = CompareStr(L"abc", L"abcasdf"); // 1
	int iCmp5 = CompareStr(L"abc", L"abc");		// 0
	int iCmp6 = CompareStr(L"agc", L"abcasdf");	// -1


	return 0;



	// wcscmp() �Լ� �����غ��� (���޵� �� ���ڿ��� ��ġ�ϸ� 0 ��ȯ)
	// ù��° ���ڿ��� �� ũ�� 1 ��ȯ
	// �ι�° ���ڿ��� �� ũ�� 2 ��ȯ
}