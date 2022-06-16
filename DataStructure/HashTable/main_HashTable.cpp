#include "HashTable.h"
int main() {
	HashTable* table = createTable(193);

	set(table, 418, 32114);
	set(table, 9, 514);
	set(table, 27, 8917);
	set(table, 1031, 286);

	printf("key:%d, Value:%d\n", 418, get(table, 418));
	printf("key:%d, Value:%d\n", 9, get(table, 9));
	printf("key:%d, Value:%d\n", 27, get(table, 27));
	printf("key:%d, Value:%d\n", 1031, get(table, 1031));

	destroyTable(table);

	return 0;
}