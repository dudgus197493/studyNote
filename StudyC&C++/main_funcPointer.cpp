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
	// �Լ� ������ (�ݹ��ɿ� ���� ����)
	// �Լ� �����͸� �޴� ���
	// void(*pFunc)(void) = nullptr;
	// pFunc = Test;
	// pFunc(); == Test();


	// �ᱹ ����� ���ٵ� 
	// �Լ� �����͸� ����ؼ�
	// �������� ������� ����� ���ڷ� �Ѱ��� �� �ִ�.
	int iPlus = calculate(6, 3, plus);
	int iSub = calculate(6, 3, sub);
	int iMul = calculate(6, 3, mul);
	int iDiv = calculate(6, 3, div);

	return 0;
}