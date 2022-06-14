#include "LCRSTree.h"
int main() {
	// ��� ����
	LCRSNode* Root = LCRS_createNode('A');

	LCRSNode* B = LCRS_createNode('B');
	LCRSNode* C = LCRS_createNode('C');
	LCRSNode* D = LCRS_createNode('D');
	LCRSNode* E = LCRS_createNode('E');
	LCRSNode* F = LCRS_createNode('F');
	LCRSNode* G = LCRS_createNode('G');
	LCRSNode* H = LCRS_createNode('H');
	LCRSNode* I = LCRS_createNode('I');
	LCRSNode* J = LCRS_createNode('J');
	LCRSNode* K = LCRS_createNode('K');

	// Ʈ���� ��� �߰�

	LCRS_addChildNode(Root, B);
		LCRS_addChildNode(B, C);
		LCRS_addChildNode(B, D);
			LCRS_addChildNode(D, E);
			LCRS_addChildNode(D, F);
	LCRS_addChildNode(Root, G);
		LCRS_addChildNode(G, H);
	LCRS_addChildNode(Root, I);
		LCRS_addChildNode(I, J);
			LCRS_addChildNode(J, K);

	// Ʈ�� ���
	LCRS_printTree(Root, 0);
	printf("========���� �� ���========\n");
	LCRS_PrintNodesAtLevel(Root, 4);
	// Ʈ�� �Ҹ�
	LCRS_destroyTree(Root);
	
	return 0;
}