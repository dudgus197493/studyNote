#include <stdio.h>
#include "SimpleBinaryTree.h"

int main() {
	// 노드 생성
	SBTNode* A = SBT_createNode('A');
	SBTNode* B = SBT_createNode('B');
	SBTNode* C = SBT_createNode('C');
	SBTNode* D = SBT_createNode('D');
	SBTNode* E = SBT_createNode('E');
	SBTNode* F = SBT_createNode('F');
	SBTNode* G = SBT_createNode('G');

	// 트리에 노드 추가
	A->leftChild = B;
	B->leftChild = C;
	B->rightChild = D;

	A->rightChild = E;
	E->leftChild = F;
	E->rightChild = G;

	// 트리 출력
	printf("전위순회 출력=========\n");
	SBT_preorderPrintTree(A);
	printf("\n\n");

	printf("중위순회 출력=========\n");
	SBT_inorderPrintTree(A);
	printf("\n\n");

	printf("후위순회 출력=========\n");
	SBT_postorderPrintTree(A);
	printf("\n\n");

	SBT_destroyTree(A);
}