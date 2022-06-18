#include "DisjointSet.h"

int main() {
	int a = 1, b = 2, c = 3, d = 4;

	DisjointSet* set1 = createNode(&a);
	DisjointSet* set2 = createNode(&b);
	DisjointSet* set3 = createNode(&c);
	DisjointSet* set4 = createNode(&d);

	printf("Set1 == Set2 : %d\n", FindSet(set1) == FindSet(set2));

	UnionSet(set1, set3);

	printf("Set1 == Set3 : %d\n", FindSet(set1) == FindSet(set3));

	UnionSet(set3, set4);

	printf("Set3 == Set4 : %d\n", FindSet(set3) == FindSet(set4));

	/*destroyNode(&a);
	destroyNode(&b);
	destroyNode(&c);
	destroyNode(&d);*/

	return 0;
}