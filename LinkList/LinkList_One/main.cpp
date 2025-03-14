#include <stdint.h>
#include <stdlib.h>
#include "LinkList.h"

void test() {
	LinkList* list = createLinkList();
	for (int i = 0;i < 5;++i) {
		header_insert(list,i + 100);
	}
	showLinkList(list);
	
	back_insert(list, 77);
	showLinkList(list);

	index_insert(list, 3, 9);
	showLinkList(list);

	header_delete(list);
	showLinkList(list);

	index_delete(list, 2);
	showLinkList(list);

	releaseLinkList(list);
}


int main() {
	test();
	return 0;
}