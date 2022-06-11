#include<stdio.h>
#include "common.h";
#include "func.h";
static int global_i = 0;
int Add(int a, int b) {

	printf("g_iExternÀÇ °ª : %d", g_iExtern);

	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}

int Mul(int a, int b) {
	return a * b;
}