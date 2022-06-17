#include "OAHashTable.h"
int main() {
	OATable* table = OA_createTable(11);

	OA_set(&table, "MSFT", "Microsoft Corporation");
	OA_set(&table, "JAVA", "Sun Microsystems");
	OA_set(&table, "REDH", "Red Hat Linuxs");
	OA_set(&table, "APAC", "Apache Org");
	OA_set(&table, "ZYMZZ", "Unisys Ops Check");		// APAC와 충돌
	OA_set(&table, "IBM", "IBM Ltd.");
	OA_set(&table, "ORCL", "Oracle Corporation");
	OA_set(&table, "CSCO", "Cisco Systems, Inc.");
	OA_set(&table, "GOOG", "Google Inc.");
	OA_set(&table, "YHOO", "Yahoo! Inc.");
	OA_set(&table, "NOVL", "Novell, Inc.");

	printf("데이터 저장완료");

	printf("\n");
	printf("key:%s, Value:%s\n", "MSFT", OA_get(table, "MSFT"));
	printf("key:%s, Value:%s\n", "REDH", OA_get(table, "REDH"));
	printf("key:%s, Value:%s\n", "APAC", OA_get(table, "APAC"));
	printf("key:%s, Value:%s\n", "ZYMZZ", OA_get(table, "ZYMZZ"));
	printf("key:%s, Value:%s\n", "JAVA", OA_get(table, "JAVA"));
	printf("key:%s, Value:%s\n", "IBM", OA_get(table, "IBM"));
	printf("key:%s, Value:%s\n", "ORCL", OA_get(table, "ORCL"));
	printf("key:%s, Value:%s\n", "CSCO", OA_get(table, "CSCO"));
	printf("key:%s, Value:%s\n", "GOOG", OA_get(table, "GOOG"));
	printf("key:%s, Value:%s\n", "YHOO", OA_get(table, "YHOO"));
	printf("key:%s, Value:%s\n", "NOVL", OA_get(table, "NOVL"));



	OA_destroyTable(table);
	printf("테이블이 소멸되었습니다.");

	return 0;
}