#include <stdio.h>
#include <wchar.h>
int main() {

	// 문자 자료형
	//char(1), wchar(2)
	char c = 'a';			// 1바이트, 정수타입
	wchar_t wc = L'a';		// 2바이트, 정수타입 앞에 L을 붙어야함


	// 문자 자료형을 배열로 선언
	char szChar[10] = "coffee";

	wchar_t szWChar[10] = L"abcdef";
	/*wchar_t szWChar[10] = { 97, 98, 99, 100, 101, 102 }; 위와 같음*/

	short arrShort[10] = { 97, 98, 99, 100, 101, 102 };

	// 배열과 포인터
	// 포인터 변수로 문자열을 받을 수 있다.
	const wchar_t* pChar = L"abcdef"; // 문자열의 정체는 주소값이다
	/*wchar_t* pChar = L"abcdef";*/   // 문자열 주소의 반환타입은 const 타입이다 컴파일 오류
	// 코드영역(읽기전용 영역-데이터초기화 영역)의 있는 문자열의 주소값을 받아오는것이다.
	// 코드를 바꾸면 안되므로 const 타입 자료형으로 받아와야함
	{
		// 위 코드
		wchar_t szWChar[10] = L"abcdef";
		// 의 정체는 메모리의 생성된 abcdef 주소값의 저장된 배열 값 하나하나를
		// 내가만든 szWChar[10] 배열에 복사해서 넣겠다는 뜻이다.
	}
	szWChar[1] = 'z';		// szWChar배열의 'b'를 'z'로 변경
	// pChar[1] = 'z';		// 원본 배열의 'b'를 'z'로 변경
	
	
	// 멀티바이트 문자 - 표준으로 쓰이지 않는 방식(잘 안쓰임)
	char szTest[10] = "abc한글";
	// 1바이트로 표현가능한 문자는 1바이트
	// 2바이트로 표현해야하는 문자는 2바이트로 표현
	// 멀티바이트 문자표현의 문제점
	// 1. 가독성이 떨어짐
	// 2. 문자를 읽을때 2바이트 문자르 체크하기위해 비트값까지 따져야함
	//    결국 통일성이 떨어짐
	{
		wchar_t szName[10] = L"Raimond"; // 문자의 갯수는 7개다라고 바로 알 수 있음
		int iLen = wcslen(szName);			 // 문자열의 길이를 알려주는 함수
											 // 배열의 시작 주소를 인자로 줘야함
											 // 이 함수는 인자의 주소를 const 포인터 변수로 받기때문에
		return 0;											 // 데이터의 변경이 없다는 의도를 밝히고 있다.
	}

	// 와이드바이트 문자
	// 모든 문자를 2바이트로 표현
	wchar_t szTestW[10] = L"abc한글";


	return 0;
}