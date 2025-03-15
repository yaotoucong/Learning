#include <stdio.h>
#include <stdlib.h>
#include "ThreadBTree.h"

ThreadBTree* initThreadBTree() {
	ThreadBTree* tree = createThreadBTree();
	TreeNode* nodeA = createTreeNode('A');
	initTreeRoot(tree, nodeA);
	TreeNode* nodeB = createTreeNode('B');
	TreeNode* nodeC = createTreeNode('C');
	TreeNode* nodeD = createTreeNode('D');
	TreeNode* nodeE = createTreeNode('E');
	TreeNode* nodeF = createTreeNode('F');
	TreeNode* nodeG = createTreeNode('G');
	TreeNode* nodeH = createTreeNode('H');
	TreeNode* nodeK = createTreeNode('K');

	insertTreeNode(tree, nodeA, nodeB, nodeE);
	insertTreeNode(tree, nodeB, NULL, nodeC);
	insertTreeNode(tree, nodeC, nodeD, NULL);
	insertTreeNode(tree, nodeE, NULL, nodeF);
	insertTreeNode(tree, nodeF, nodeG, NULL);
	insertTreeNode(tree, nodeG, nodeH, nodeK);


	return tree;
}

void test() {
	ThreadBTree* tree = initThreadBTree();
	printf("num is %d\n", tree->num);
	inOrderThreadedTree(tree);
	printf("tree tag is %d\n", tree->tag);
	inOrederTree(tree);
	printf("\n");









	releaseThreadBTree(tree);
}

int main() {
	test();
	return 0;
}