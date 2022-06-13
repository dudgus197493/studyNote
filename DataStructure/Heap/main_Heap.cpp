#include<stdio.h>
#include "Heap.h";
int main() {
	
	Heap* H = H_createHeap(3);
	HeapNode minNode;

	H_insert(H, 12);
	H_insert(H, 87);
	H_insert(H, 111);
	H_insert(H, 34);
	H_insert(H, 16);
	H_insert(H, 75);
	H_printAllNodes(H);
	printf("\n");

	H_delMinNode(H, &minNode);
	H_printAllNodes(H);
	printf("\n");

	H_delMinNode(H, &minNode);
	H_printAllNodes(H);
	printf("\n");

	H_delMinNode(H, &minNode);
	H_printAllNodes(H);
	printf("\n");

	H_delMinNode(H, &minNode);
	H_printAllNodes(H);
	printf("\n");

	H_delMinNode(H, &minNode);
	H_printAllNodes(H);
	printf("\n");

	return 0;
}