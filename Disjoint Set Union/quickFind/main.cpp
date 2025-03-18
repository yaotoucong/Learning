#include <stdio.h>
#include <stdlib.h>
#include "quickfind.h"

void test() {
	QuickFindSet* set = createQuickFindSet(20);
	Element data[9];
	for (int i = 0;i < sizeof(data) / sizeof(data[0]);++i) {
		data[i] = '0' + i;
	}
	initQuickFindSet(set, data, sizeof(data) / sizeof(data[0]));
	UnionGroup(set, '3','4');
	UnionGroup(set, '8','0');
	UnionGroup(set, '2','3');
	UnionGroup(set, '5','6');
	if (isSameGroup(set, '0', '2')) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	if (isSameGroup(set, '2', '4')) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	UnionGroup(set, '5', '1');
	UnionGroup(set, '7', '3');
	UnionGroup(set, '1', '6');
	UnionGroup(set, '4', '8');
	if (isSameGroup(set, '0', '2')) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	if (isSameGroup(set, '2', '4')) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	releaseQuickFindSet(set);
}


int main() {
	test();
	return 0;
}