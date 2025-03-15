#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

void test0() {
	ArrayStaack* stack = createArrayStack();
	for (int i = 0;i < 7;++i) {
		pushArrayStack(stack, 100 + i);
	}
	showArrrayStack(stack);

	releaseArrayStack(stack);
}

void test1() {
	int stack[20];
	int pos = 0;
	for (int i = 0;i < 7;++i) {
		stack[pos++] = i + 100;
	}
	printf("%d\n", pos);
	for (int i = pos;i > 0;) {
		printf("%d\t", stack[--i]);
		pos = i;
	}
	printf("\n%d", pos);
}


int main() {
	test1();
	return 0;
}