#include <stdio.h>
#include "LinkedList.h";

int main()
{
	LinkedList list;

	InitList(&list);

	/*PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);*/

	PushFront(&list, 1);
	PushFront(&list, 2);
	PushFront(&list, 3);
	PushFront(&list, 4);
	PushFront(&list, 5);

	Node* printNode = list.pHeadNode;
	for (int i = 0; i < list.iCount; ++i) {
		printf("%d\n", printNode->iData);
		printNode = printNode->pNextNode;
	}

	ReleaseList(&list);
	
	return 0;
}