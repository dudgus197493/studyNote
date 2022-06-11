void Output(const int* pI) {
	int iData = *pI; // 원본의 값을 가져와 사용할 수 있음
	/**pI = 100;*/	 // 원본의 값을 바꿀 수는 없음 컴파일 오류

	/*int* pInt = (int*)pI;	// 억지로 바꾼다면 바꿀 수 있지만
	*pInt = 1000;*/			// 구현하는 사람의 입장에서 데이터를 가져와 읽기만 할 것이라는 의도를 파악 할 수 있다.
}

int main() {


	// const
	const int cint = 100;

	// 상수화
	// 10 = 11 : X
	// r-value : 바뀔 수 없는 값 (상수)
	// l-value : 바뀔 수 있는 값 (변수)

	/*cint = 100; <-> 100 = 100; : X -> 컴파일 에러
	하지만 문법적으로 안될뿐이지 절대적인 것은 아님*/

	// const 와 포인터
	int a = 0;			// 일반적인 변수는 자신이 담고 있는 값만 변경 가능
	int* pInt = &a;

	// 포인터 변수의 특징
	*pInt = 10;			// 1. 포인터 변수가 가리키는 주소의 원본을 변경	
	pInt = nullptr;		// 2. 포인터 변수가 가리키는 주소를 변경


	// ===========
	// const 포인터 (가리킨 주소의 원본을 바꿀 수 없음)
	// ===========
	const int* pConstInt = &a; // 포인터 변수가 가리키는 주소의 원본을 상수화
	/**pConstInt = 20;	*/	   // 원본을 바꾸려해서 컴파일 오류
	int b = 0;
	pConstInt = &b;

	// ===========
	// 포인터 const (초기화 시 가리킨 대상만 가리킴)
	// ===========

	int* const pIntConst = &a;	// 포인터 변수 자체를 상수화
	*pIntConst = 400;			// 원본은 바꿀 수 있으나
	// pIntConst = &b;			// 가리키는 주소의 값은 변경 불가 컴파일 오류

	// 둘 다 사용
	// 초기화 시 가리킨 대상만 가리킴, 가리키는 원본을 수정 할 수 없음.
	const int* const pConstIntConst = nullptr;

	{
		int a = 0;
		const int* pInt = &a;	// 포인터의 기능을 제한한 것
								// 포인터 변수를 통해 접근한 원본을 수정하는 것을 막은것이지
								// 변수 a 를 상수화 한 것이 아님.
		a = 100;				// 정상적으로 컴파일 됨
	}

	// cosnt 포인터 & 포인터 const 사용 예시
	{
		int a = 10;
		// 함수에 매개변수를 전달하고 함수를 실행하기엔 
		// 복사할 데이터가 너무 커서 원본의 주소를 전달해야할때
		// 원본의 데이터는 던져주지만 포인터변수가 원본을 수정하는 것은 막아야 할때 사용

		Output(&a);
	}


	// void 포인터
	{
		void* pVoid = nullptr;
		float* pFloat = nullptr;

		int a = 0;				// void 포인터는 자신이 가지고 있는 
		float f = 0.f;			// 주소의 원본을 어떤 자료형으로 볼건지 정하지 않은상태
		double d = 0.f;			
		long long ll = 0;

		pVoid = &a;				// 그러므로 모든 자료형의 주소를 저장할 수 있다.
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;

		// *pVoid;				// 하지만 역참조는 불가능하다. 컴파일 오류
		// pVoid + 1;			// 주소연산도 불가능하다.
	}
		
	
	

	return 0;
}