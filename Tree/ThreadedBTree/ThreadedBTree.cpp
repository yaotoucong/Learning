#include <stdio.h>
#include <stdlib.h>
#include "ThreadBTree.h"

ThreadBTree* createThreadBTree()
{
	ThreadBTree* tree = (ThreadBTree*)malloc(sizeof(ThreadBTree));
	tree->num = 0;
	tree->root = NULL;
	tree->tag = 0;
	return tree;
}

TreeNode* createTreeNode(Element e)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = e;
	node->left = node->right = NULL;
	node->Ltag = node->Rtag = 0;
	return node;
}

void initTreeRoot(ThreadBTree* tree, TreeNode* node)
{
	if (tree && node) {
		tree->root = node;
		tree->num++;
	}
}

void insertTreeNode(ThreadBTree* tree, TreeNode* parent, TreeNode* left, TreeNode* right)
{
	if (tree && parent) {
		parent->left = left;
		parent->right = right;
		if (left) tree->num++;
		if (right) tree->num++;
	}
}

static void visitTreeNode(TreeNode* node) {
	if (node) {
		printf("%c\t", node->data);
	}
}


static TreeNode* pre = NULL;
static void inOrderThreading(TreeNode* node) {
	if (node == NULL) return;
	inOrderThreading(node->left);
	if (node->left == NULL) {
		node->left = pre;
		node->Ltag = 1;
	}
	if (pre && pre->right == NULL) {
		pre->right = node;
		pre->Rtag = 1;
	}
	pre = node;
	inOrderThreading(node->right);
}


void inOrderThreadedTree(ThreadBTree* tree)
{
	if (tree && tree->root) {
		inOrderThreading(tree->root);
		tree->tag = 2;  // 0:default 1:pre 2:in 3:post
	}
}

void inOrederTree(ThreadBTree* tree)
{
	if (tree && tree->tag == 2) {
		TreeNode* node = tree->root;
		while (node) {
			while (node->Ltag == 0) {
				node = node->left;
			}
			visitTreeNode(node);
			while (node->Rtag == 1) {
				node = node->right;
				visitTreeNode(node);
			}
			node = node->right;
		}
		
	}
}












static void release(ThreadBTree* tree, TreeNode* node) {
	if (node == NULL) return;
	if (node->Ltag == 0) 
		release(tree,node->left);
	if (node->Rtag == 0)
		release(tree, node->right);
	free(node);
	tree->num--;
}

void releaseThreadBTree(ThreadBTree* tree)
{
	if (tree && tree->root) {
		release(tree, tree->root);
		printf("tree num is %d\n", tree->num);
		free(tree);
	}
}