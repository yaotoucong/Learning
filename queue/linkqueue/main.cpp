#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkQueue.h"

void test0() {
	LinkQueue* queue = createLinkQueue();
	for (int i = 0;i < 7;++i) {
		pushLinkQueue(queue, 100 + i);
	}
	Element e;
	printf("queue num is %d\n", queue->num);
	while (popLinkQueue(queue, &e) != -1) {
		printf("%d\t", e);
	}
	releaseLinkQueue(queue);


}

int main() {
	test0();



	return 0;
}
