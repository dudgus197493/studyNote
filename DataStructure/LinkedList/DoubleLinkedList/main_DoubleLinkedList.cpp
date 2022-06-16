#include<stdio.h>
#include"DoubleLinkedList.h";

int main() {
	
	DoubleLinkedList* list = DLL_createList();
	DLL_appendBack(list, 1);
	DLL_appendBack(list, 2);
	DLL_appendBack(list, 3);
	DLL_appendBack(list, 4);
	DLL_appendFront(list, 5);
	DLL_appendFront(list, 6);
	DLL_printAllNode(list);

	Node* searchNode = DLL_searchNode(list, 3);			// data 2가진 노드가 반환되어야함.
	printf("3번째 : %d\n", searchNode->iData);

	DLL_insertNode(list, 100, 2);
	printf("2번째 인덱스에 노드삽입 후\n");						
	DLL_printAllNode(list);									// 6, 5, 100, 1, 2, 3, 4

	DLL_destroyList(list);

	return 0;

}