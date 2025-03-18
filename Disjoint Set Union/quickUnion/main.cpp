#include <stdio.h>
#include <stdlib.h>
#include "quickUnion.h"

void test() {
	quickUnionSet* set = createquickUnionSet(20);
	Element data[9];
	for (int i = 0;i < sizeof(data) / sizeof(data[0]);++i) {
		data[i] = '0' + i;
	}
	initquickUnionSet(set, data, sizeof(data) / sizeof(data[0]));
	UnionParent(set, '3','4');
	UnionParent(set, '8','0');
	UnionParent(set, '2','3');
	UnionParent(set, '5','6');
	if (isSameParent(set, '0', '2')) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	if (isSameParent(set, '2', '4')) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	UnionParent(set, '5', '1');
	UnionParent(set, '7', '3');
	UnionParent(set, '1', '6');
	UnionParent(set, '4', '8');
	if (isSameParent(set, '0', '2')) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	if (isSameParent(set, '2', '4')) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	releasequickUnionSet(set);
}


int main() {
	test();
	return 0;
}