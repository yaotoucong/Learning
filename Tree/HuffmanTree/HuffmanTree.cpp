#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HuffmanTree.h"

static void findMin_index(HuffmanTree tree,int n,int *s1,int *s2) {
	int min = 0;
	for (int i = 1;i <= n;++i) {
		if (tree[i].parent == 0) {
			min = i;
			break;
		}
	}

	for (int i = 1;i <= n;++i) {
		if (tree[i].parent == 0) {
			if (tree[i].weight < tree[min].weight) {
				min = i;
			}
		}
	}
	*s1 = min;

	for (int i = 1;i <= n;++i) {
		if (tree[i].parent == 0 && i != *s1) {
			min = i;
			break;
		}
	}



	for (int i = 1;i <= n;++i) {
		if (tree[i].parent == 0 && i != *s1) {
			if (tree[i].weight < tree[min].weight) {
				min = i;
			}
		}
	}
	*s2 = min;
}

HuffmanTree createHuffmanTree(int* weight, int n)
{
	int m = 2 * n - 1;
	HuffmanTree tree = (HuffmanTree)malloc(sizeof(HuffmanNode) * (m + 1));
	for (int i = 0;i <= m;++i) {
		tree[i].parent = tree[i].lChild = tree[i].rChild = 0;
	}
	for (int i = 1;i <= n;++i) {
		tree[i].weight = weight[i-1];
	}


	int s1, s2;
	for (int i = n + 1;i <= m;++i) {
		findMin_index(tree, i - 1, &s1, &s2);
		if (s1 == 0 || s2 == 0) {
			printf("find min_index fail!\n");
		}
		tree[i].lChild = s1;
		tree[i].rChild = s2;
		tree[i].weight = tree[s1].weight + tree[s2].weight;
		tree[s1].parent = tree[s2].parent = i;
	}
	return tree;
}

char** createHuffmanNode(HuffmanTree tree, int n)
{
	char** nodes = (char**)malloc(sizeof(char*) * (n + 1));
	char* tmp = (char*)malloc(sizeof(char) * n);
	int start;
	int parent, pos;
	for (int i = 1; i <= n; ++i) {
		pos = i;
		parent = tree[pos].parent;
		start = n - 1;
		tmp[start] = '\0';
		while (parent) {
			tmp[--start] = (char)(tree[parent].lChild == pos ? '0' : '1');
			pos = parent;
			parent = tree[parent].parent;
		}
		nodes[i] = (char*)malloc(sizeof(char) * (n - start));
		strcpy_s(nodes[i], n - start, &tmp[start]);
	}
	free(tmp);
	return nodes;
}

void releaseHuffmanTree(HuffmanTree tree)
{
	if (tree) free(tree);
}
