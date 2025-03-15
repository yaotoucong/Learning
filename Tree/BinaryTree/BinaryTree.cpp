#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "ArrayQueue.h"
#include "ArrayStack.h"

BinaryTree* createBinaryTree()
{
	BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	tree->num = 0;
	tree->root = NULL;
	return tree;
}

TreeNode* createTreeNode(char e)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = e;
	node->left = node->right = NULL;
	return node;
}

void initTreeRoot(BinaryTree* tree, TreeNode* node)
{
	if (tree && node) {
		tree->root = node;
		tree->num++;
	}
}

void insertTreeNode(BinaryTree* tree, TreeNode* parent, TreeNode* left, TreeNode* right)
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

void levelOrderBinaryTree(BinaryTree* tree)
{
	if (tree && tree->root) {
		ArrayQueue* queue = createArrayQueue();
		pushArrayQueue(queue, tree->root);
		TreeNode *tmp;
		while (popArrayQueue(queue, &tmp) != -1) {
			visitTreeNode(tmp);
			if (tmp->left) pushArrayQueue(queue, tmp->left);
			if(tmp->right) pushArrayQueue(queue, tmp->right);
		}

		releaseArrayQueue(queue);
	}
}

static void PreOrder(TreeNode* node) {
	if (node == NULL) return;
	visitTreeNode(node);
	PreOrder(node->left);
	PreOrder(node->right);
}

void PreOrderBinaryTree(BinaryTree* tree)
{
	if (tree && tree->root) {
		PreOrder(tree->root);
	}
}

static void inOrder(TreeNode* node) {
	if (node == NULL) return;
	inOrder(node->left);
	visitTreeNode(node);
	inOrder(node->right);
}

void inOrderBinaryTree(BinaryTree* tree)
{
	if (tree && tree->root) {
		inOrder(tree->root);
	}
}

static void postOrder(TreeNode* node) {
	if (node == NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	visitTreeNode(node);
}

void postOrderBinaryTree(BinaryTree* tree)
{
	if (tree && tree->root) {
		postOrder(tree->root);
	}
}

// No Recure ===========================================================

static void PreOrder_Norecur(TreeNode* node) {
	ArrayStaack* stack = createArrayStack();
	TreeNode* e;
	pushArrayStack(stack, node);
	while (popArrayStack(stack, &e) != -1) {
		visitTreeNode(e);
		if(e->right) pushArrayStack(stack, e->right);
		if (e->left) pushArrayStack(stack, e->left);
	}


	releaseArrayStack(stack);
}

void PreOrderBinaryTree_Norecur(BinaryTree* tree)
{
	if (tree && tree->root) {
		PreOrder_Norecur(tree->root);
	}
}

static void inOrder_Norecur(TreeNode* node) {
	ArrayStaack* stack = createArrayStack();
	TreeNode* e = node;
	while (e||stack->length<MaxStackSize) {
		if (e) {
			pushArrayStack(stack, e);
			e = e->left;
		}
		else {
			popArrayStack(stack, &e);
			visitTreeNode(e);
			e = e->right;
		}
	}
	


	releaseArrayStack(stack);
}

void inOrderBinaryTree_Norecur(BinaryTree* tree)
{
	if (tree && tree->root) {
		inOrder_Norecur(tree->root);
	}
}

static void postOrder_Norecur(TreeNode* node) {
	ArrayStaack *stack1 = createArrayStack();
	ArrayStaack *stack2 = createArrayStack();
	TreeNode* e;
	pushArrayStack(stack1, node);
	while (popArrayStack(stack1, &e) != -1) {
		pushArrayStack(stack2, e);
		if (e->left) pushArrayStack(stack1, e->left);
		if (e->right) pushArrayStack(stack1, e->right);
	}

	while (popArrayStack(stack2, &e) != -1) {
		visitTreeNode(e);
	}



	releaseArrayStack(stack1);
	releaseArrayStack(stack2);
}

void postOrderBinaryTree_Norecur(BinaryTree* tree)
{
	if (tree && tree->root) {
		postOrder_Norecur(tree->root);
	}
}

static void release(BinaryTree* tree,TreeNode* node) {
	if (node == NULL) return;
	release(tree,node->left);
	release(tree,node->right);
	free(node);
	tree->num--;
}

void releaseBinaryTree(BinaryTree* tree)
{
	if (tree && tree->root) {
		release(tree,tree->root);
		printf("tree num is %d\n", tree->num);
		free(tree);
	}
}
