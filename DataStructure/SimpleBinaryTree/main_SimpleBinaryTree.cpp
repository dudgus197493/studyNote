#include <stdio.h>
#include "SimpleBinaryTree.h"

int main() {
	// ��� ����
	SBTNode* A = SBT_createNode('A');
	SBTNode* B = SBT_createNode('B');
	SBTNode* C = SBT_createNode('C');
	SBTNode* D = SBT_createNode('D');
	SBTNode* E = SBT_createNode('E');
	SBTNode* F = SBT_createNode('F');
	SBTNode* G = SBT_createNode('G');

	// Ʈ���� ��� �߰�
	A->leftChild = B;
	B->leftChild = C;
	B->rightChild = D;

	A->rightChild = E;
	E->leftChild = F;
	E->rightChild = G;

	// Ʈ�� ���
	printf("������ȸ ���=========\n");
	SBT_preorderPrintTree(A);
	printf("\n\n");

	printf("������ȸ ���=========\n");
	SBT_inorderPrintTree(A);
	printf("\n\n");

	printf("������ȸ ���=========\n");
	SBT_postorderPrintTree(A);
	printf("\n\n");

	SBT_destroyTree(A);
}