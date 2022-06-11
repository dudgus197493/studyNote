#include <stdio.h>

typedef struct _tagMyST {
	int a;			//멤버 (변수가 아님)
	float f;
} MYST;

int main() {
	// 구조체와 포인터	
	MYST s = {};

	MYST* pST = &s;

	/*(*pST).a = 100;
	(*pST).f = 3.14f;*/
	
	// 위 작성을 단순화 한게 아래

	pST->a = 100;
	pST->f = 3.14f;

	return 0;
}