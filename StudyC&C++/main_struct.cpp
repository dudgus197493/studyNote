#include <stdio.h>

typedef struct _tagMyST {
	int a;			//��� (������ �ƴ�)
	float f;
} MYST;

int main() {
	// ����ü�� ������	
	MYST s = {};

	MYST* pST = &s;

	/*(*pST).a = 100;
	(*pST).f = 3.14f;*/
	
	// �� �ۼ��� �ܼ�ȭ �Ѱ� �Ʒ�

	pST->a = 100;
	pST->f = 3.14f;

	return 0;
}