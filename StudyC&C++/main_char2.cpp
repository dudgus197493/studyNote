#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include <cassert>

// wsclen 함수 직접 구현해보기
unsigned int GetLength(const wchar_t* _pStr) {							// 반환할 글자의 개수가 음수일 수 없으므로 unsigned 로 선언
	// 문자 개수 체크
	int i = 0;

	// 널문자가 나올때까지 반복해서 카운트
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

// wcscat_s함수 직접 구현해보기
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc) {
	// 복사 받을 곳의 최대공간을 매개변수로 입력받는 이유
		// ㄴ 복사받을 공간의 최대공간이 100 이고
		//	  이미 원본에 50이 차있는데
		//    70을 더 붙이려 하면 안되기때문에 미리 막기위해

	// 1. 예외 처리
	// 이어붙인 최종 문자열 길이가, 원본 저장 공간을 넘어서려는 경우
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);
	if (_iBufferSize < iDestLen + iSrcLen + 1) // Null 문자 공간가지 계산
	{
		assert(nullptr);
	}

	// 2. 문자열 이어붙이기
	// 1) Null 문자의 위치 찾기 ( 문자열이 이어붙을 시작 위치)
	/*iDestLen;*/
	// 2) 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
	for (int i = 0; i < iSrcLen; ++i) { //_pSrc의 널 문자까지 가져오기 위해 +1 을 해줌
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int CompareStr(const wchar_t* _pStrA, const wchar_t* _pStrB) {
	int iStrALen = GetLength(_pStrA);
	int iStrBLen = GetLength(_pStrB);
	int iShorter = (iStrALen < iStrBLen ? iStrALen : iStrBLen);	

	// 2. 첫글자부터 반복적으로 비교해서 같으면 continue
	// 다르면 1, -1 리턴
	//  1) 반복조건은 문자열의 길이 (두 문자열중 짧은 문자열을 반복 조건으로)
	for (int i = 0; i < iShorter + 1; ++i) {
		if ((int)_pStrA[i] > (int)_pStrB[i]) {
			return -1;
		}
		else if ((int)_pStrA[i] < (int)_pStrB[i]) {
			return 1;
		}
	}
	// 3. 반복문을 정상적으로 빠져나오면 (두 문자열이 같다는 것을 뜻함)
	// 4. 두 문자가 같을때 더 짧은 문자열이 우선
	if (iStrALen < iStrBLen) {	// A가 더 짧으면
		return -1;
	}
	else if (iStrALen > iStrBLen) {	// B가 더 짧으면
		return 1;
	}
	else {
		return 0;
	}
	
}

int main() {
	wchar_t szName[10] = L"Raimond";

	// 문자열 길이 구하기
	// int iLen = wcslen(szName);
	int iLen = GetLength(szName);	// iLen이 7을 받아야함

	

	// 문자열 이어 붙이기
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



	// wcscmp() 함수 구현해보기 (전달된 두 문자열이 일치하면 0 반환)
	// 첫번째 문자열이 더 크면 1 반환
	// 두번째 문자열이 더 크면 2 반환
}