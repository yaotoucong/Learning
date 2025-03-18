#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

void test() {
	AVLTree* tree = createAVLTree();
	Element a[] = { 10, 20 ,30 ,40 ,50 ,60 ,
					68, 68 , 80 ,25 ,7 ,55 };
	for (int i = 0;i < sizeof(a) / sizeof(a[0]);++i) {
		insertAVLNode(tree, a[i]);
	}
	InOrderAVLTree(tree);
	printf("\ntree high is %d\n", AVLTreeHigh(tree->root));

	deleteAVLNode(tree, 50);
	InOrderAVLTree(tree);
	printf("\ntree high is %d\n", AVLTreeHigh(tree->root));

	deleteAVLNode(tree, 60);
	InOrderAVLTree(tree);
	printf("\ntree high is %d\n", AVLTreeHigh(tree->root));

	releaseAVLTree(tree);
}

int main() {
	test();


	return 0;
}