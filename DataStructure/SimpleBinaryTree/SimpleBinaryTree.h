// 이진트리
//	- 모든 노드가 최대 2개의 자식을 가질 수 있는 트리
//	- 일반 트리처럼 데이터를 담기 위한 자료구조가 아닌 수식계산, 자료 검색에 사용 됨

// 이진트리의 여러 형태
//	1. 포화 이진 트리 (Full Binary Tree)
//		- 잎 노드를 제외한 모든 노드가 자식를 둘씩 가지고 있는 이진트리
//	2. 완전 이진 트리 (Complete Binary Tree)
//		- 포화 이진 트리를 이루기 전 단계
//		- 잎 노드들이 트리의 왼쪽부터 차곡차곡 채워진 것이 특징
//  * 이진트리를 이용한 검색에서는 높은 성능을 위해 트리의 노드들을 가능한 '완전한' 모습으로 배치하는 것이 필수
//	3. 높이 균형 트리
//		- 루트 노드를 기준으로 왼쪽 하위 트리와 오른쪽 하위 트리의 높이가 1이상 차이나지 않는 이진 트리
//  3. 완전 높이 균형 트리
//		- 루트 노드를 기준으로 왼쪽 하위 트리와 오른쪽 하위 트리의 높이가 같은 이진 트리

// 이진 트리의 순회

#include<stdio.h>
#include<stdlib.h>
typedef struct _tagSBTNode {
	int iData;
	_tagSBTNode* leftChild;
	_tagSBTNode* rightChild;
} SBTNode;

// 이진 트리 노드 생성
SBTNode* SBT_createNode(int _newData);

// 이진 트리 노드 소멸
void SBT_destroyNode(SBTNode* _pRemove);

// 이진 트리 전위 순회 출력 - 루트->왼쪽하위트리->오른쪽하위트리
void SBT_preorderPrintTree(SBTNode* _pNode);

// 이진 트리 중위 순회 출력 - 왼쪽하위트리->루트->오른쪽하위트리
void SBT_inorderPrintTree(SBTNode* _pNode);

// 이진 트리 후위 순회 출력 - 왼쪽하위트리->오른쪽하위트리->루트
void SBT_postorderPrintTree(SBTNode* _pNode);

// 트리 소멸 함수 - 트리를 소멸 시킬때는 잎노드부터 소멸해야 하므로 후위순회를 사용하여 구현
void SBT_destroyTree(SBTNode* _pRoot);