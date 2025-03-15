#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

void test0() {
	LinkStack* stack = createLinkStack();
	for (int i = 0;i < 7;++i) {
		pushLinkStack(stack, i + 100);
	}
	Element e;
	showStack(stack);

	popLinkStack(stack, &e);
	printf("\n%d",e);

	releaseLinkStack(stack);
}

int main() {
	test0();
	return 0;
}