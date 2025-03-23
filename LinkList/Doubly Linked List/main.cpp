#include <stdio.h>
#include <stdlib.h>
#include "Doubly Linked List.h"

void test() {
	Double_List* list = createDouble_List();
	for (int i = 0;i < 10;++i) {
		insertRear(list, i + 50);
	}
	visitList(list);
	deleteHead(list);

	visitList(list);
	deleteRear(list);

	visitList(list);
	releaseDouble_List(list);
}

int main() {

	test();
	return 0;
}