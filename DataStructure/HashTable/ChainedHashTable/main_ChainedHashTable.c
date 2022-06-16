#include "ChainedHashTable.h"
int main() {
	HashTable* table = CHT_createTable(12289);

	CHT_set(table, "JAVA", "Sun Microsystems");
	CHT_set(table, "MSFT", "Microsoft Corporation");
	CHT_set(table, "REDH", "Red Hat Linuxs");
	CHT_set(table, "APAC", "Apache Org");
	CHT_set(table, "ZYMZZ", "Unisys Ops Check");		// APAC와 충돌
	CHT_set(table, "IBM", "IBM Ltd.");
	CHT_set(table, "ORCL", "Oracle Corporation");
	CHT_set(table, "CSCO", "Cisco Systems, Inc.");
	CHT_set(table, "GOOG", "Google Inc.");
	CHT_set(table, "YHOO", "Yahoo! Inc.");
	CHT_set(table, "NOVL", "Novell, Inc.");

	printf("데이터 저장완료");

	printf("\n");
	printf("key:%s, Value:%s\n", "MSFT", CHT_get(table, "MSFT"));
	printf("key:%s, Value:%s\n", "REDH", CHT_get(table, "REDH"));
	printf("key:%s, Value:%s\n", "APAC", CHT_get(table, "APAC"));
	printf("key:%s, Value:%s\n", "ZYMZZ", CHT_get(table, "ZYMZZ"));
	printf("key:%s, Value:%s\n", "JAVA", CHT_get(table, "JAVA"));
	printf("key:%s, Value:%s\n", "IBM", CHT_get(table, "IBM"));
	printf("key:%s, Value:%s\n", "ORCL", CHT_get(table, "ORCL"));
	printf("key:%s, Value:%s\n", "CSCO", CHT_get(table, "CSCO"));
	printf("key:%s, Value:%s\n", "GOOG", CHT_get(table, "GOOG"));
	printf("key:%s, Value:%s\n", "YHOO", CHT_get(table, "YHOO"));
	printf("key:%s, Value:%s\n", "NOVL", CHT_get(table, "NOVL"));



	CHT_destroyTable(table);
	printf("테이블이 소멸되었습니다.");

	return 0;
}