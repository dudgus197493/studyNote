#include "LCRSTree.h"
int main() {
	// 노드 생성
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

	// 트리에 노드 추가

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

	// 트리 출력
	LCRS_printTree(Root, 0);
	printf("========레벨 별 출력========\n");
	LCRS_PrintNodesAtLevel(Root, 4);
	// 트리 소멸
	LCRS_destroyTree(Root);
	
	return 0;
}