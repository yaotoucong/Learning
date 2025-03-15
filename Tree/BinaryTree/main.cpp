#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BinaryTree* initBinaryTree() {
	BinaryTree* tree = createBinaryTree();
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
	BinaryTree* tree = initBinaryTree();
	printf("Tree num is %d\n", tree->num);
	levelOrderBinaryTree(tree);
	printf("\n");

	PreOrderBinaryTree(tree);
	printf("\n");

	inOrderBinaryTree(tree);
	printf("\n");

	postOrderBinaryTree(tree);
	printf("\nNo Secur\n");

	PreOrderBinaryTree_Norecur(tree);
	printf("\n");

	inOrderBinaryTree_Norecur(tree);
	printf("\n");

	printf("\n");
	postOrderBinaryTree_Norecur(tree);
	printf("\n");

	releaseBinaryTree(tree);

}

int main() {
	test();

	return 0;
}
	