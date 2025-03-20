#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanTree.h"

void test() {
	int weight[] = { 5,29,7,8,14,23,3,11 };
	char show[] = { 'a','b','c','d','e','f','g','h' };
	int length = sizeof(weight) / sizeof(weight[0]);

	HuffmanTree tree = createHuffmanTree(weight,length);
	for (int i = 0;i <= 2 * length - 1;++i) {
		printf("%d %d %d %d\n", tree[i].weight, tree[i].parent, tree[i].lChild, tree[i].rChild);
	}
	printf("==============\n");
	char** nodes = createHuffmanNode(tree, length);
	for (int i = 1;i <= length;++i) {
		printf("%c¡ª¡ª>%s\n",show[i-1], nodes[i]);
	}
	releaseHuffmanTree(tree);
}

int main() {
	test();

	return 0;
}