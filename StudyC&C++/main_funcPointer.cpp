int calculate(int a, int b, int(*pFunc)(int, int)) {
	int result = pFunc(a, b);

	return result;
}

int plus(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int div(int a, int b) {
	return a / b;
}

int main() {
	// 함수 포인터 (콜백기능에 많이 쓰임)
	// 함수 포인터를 받는 방법
	// void(*pFunc)(void) = nullptr;
	// pFunc = Test;
	// pFunc(); == Test();


	// 결국 계산을 할텐데 
	// 함수 포인터를 사용해서
	// 어떤방식으로 계산할지 기능을 인자로 넘겨줄 수 있다.
	int iPlus = calculate(6, 3, plus);
	int iSub = calculate(6, 3, sub);
	int iMul = calculate(6, 3, mul);
	int iDiv = calculate(6, 3, div);

	return 0;
}