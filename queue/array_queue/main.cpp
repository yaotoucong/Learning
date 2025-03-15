#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayQueue.h"

void test() {
	ArrayQueue* queue = createArrayQueue();
	for (int i = 0;i < 6;++i) {
		if (pushArrayQueue(queue, i + 100) == -1) 
			break;
	}
	Element e;
	pushArrayQueue(queue, 7);

	while (popArrayQueue(queue, &e) != -1) {
		printf("%d\t", e);
	}

	releaseArrayQueue(queue);
}

int main() {
	test();

	return 0;
}