#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"
#include "AVLTree.h"

AVLTree* createAVLTree()
{
	AVLTree* tree = (AVLTree*)malloc(sizeof(AVLTree));
	if (tree==NULL) {
		printf("AVLTree malloc fail!\n");
		free(tree);
		return NULL;
	}
	tree->cnt = 0;
	tree->root = NULL;;
	return tree;
}



int AVLTreeHigh(AVL_Node* node)
{
	if (node == NULL) return 0;
	int left=AVLTreeHigh(node->left);
	int right=AVLTreeHigh(node->right);
	if (left > right) return ++left;
	else return ++right;
}

static void InOrder(AVL_Node* node) {
	if (node) {
		if (node->left)	InOrder(node->left);
		printf("<%d,%d>\t", node->data, node->high);
		if (node->right) InOrder(node->right);
	}
}

void InOrderAVLTree(AVLTree* tree)
{
	if (tree) {
		InOrder(tree->root);
	}
}

static AVL_Node* createAVLNode(Element e) {
	AVL_Node* node = (AVL_Node*)malloc(sizeof(AVL_Node));
	node->data = e;
	node->left = node->right = NULL;
	node->high = 1;
	return node;
}

static int high(AVL_Node* node) {
	if (node == NULL) return 0;
	return node->high;
}

static int Max_(int a,int b) {
	return a > b ? a : b;
}

static int balance(AVL_Node* node) {
	if (node == NULL) {
		return 0;
	}
	return high(node->left) - high(node->right);
}

static AVL_Node* Left(AVL_Node* node) {
	AVL_Node* tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	node->high = Max_(high(node->left), high(node->right)) + 1;
	tmp->high= Max_(high(tmp->left), high(tmp->right)) + 1;
	return tmp;
}

static AVL_Node* Right(AVL_Node* node) {
	AVL_Node* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	node->high = Max_(high(node->left), high(node->right)) + 1;
	tmp->high = Max_(high(tmp->left), high(tmp->right)) + 1;
	return tmp;
}

static AVL_Node* insert(AVLTree* tree, AVL_Node* node, Element e) {
	if (node == NULL) {
		tree->cnt++;
		return createAVLNode(e);
	}
	if (e > node->data) {
		node->right = insert(tree, node->right, e);
	}
	else if(e<node->data){
		node->left = insert(tree, node->left, e);
	}
	else {
		return node;
	}
	node->high = Max_(high(node->left), high(node->right)) + 1;
	int b = balance(node);
	if (b > 1) {  //L? LL LR
		if (e > node->left->data) {  //LR
			node->left = Left(node->left);
		}
		return Right(node);
	}
	else if (b < -1) {  //R? RR RL
		if (e < node->right->data) {  //RL
			node->right = Right(node->right);
		}
		return Left(node);
	}


	return node;
}



void insertAVLNode(AVLTree* tree, Element e)
{
	if (tree) {
		tree->root = insert(tree, tree->root, e);
	}
}

static AVL_Node* deleteNode(AVLTree* tree, AVL_Node* node, Element e) {
	if (node == NULL) return NULL;
	if (e > node->data) {
		node->right = deleteNode(tree, node->right, e);
	}
	else if (e < node->data) {
		node->left = deleteNode(tree, node->left, e);
	}
	else {
		AVL_Node* tmp;
		if (node->left == NULL || node->right == NULL) {
			tmp = (node->left == NULL) ? node->right : node->left;
			free(node);
			tree->cnt--;
			return tmp;
		}
		tmp = node->left;
		while (tmp->right) {
			tmp = tmp->right;
		}
		node->data = tmp->data;
		node->left = deleteNode(tree, node->left, tmp->data);
	}
	node->high = Max_(high(node->left), high(node->right)) + 1;
	int b = balance(node);
	if (b > 1) {  //L? LL LR
		if (balance(node->left)<0) {
			node->left = Left(node->left);
		}
		return Right(node);
	}
	else if (b < -1) {    //R? RR RL
		if (balance(node->right)>0) {
			node->right = Right(node->right);
		}
		return Left(node);
	}
	return node;
}

void deleteAVLNode(AVLTree* tree, Element e)
{
	if (tree && tree->root) {
		tree->root=deleteNode(tree, tree->root, e);
	}
}

void release_NoSecur(AVLTree* tree, AVL_Node* node) {
	ArrayStaack* stack1 = createArrayStack(100);
	ArrayStaack* stack2 = createArrayStack(100);
	AVL_Node* tmp;
	pushArrayStack(stack1, node);
	while (popArrayStack(stack1, &tmp) != -1) {
		pushArrayStack(stack2, tmp);
		if (tmp->left) pushArrayStack(stack1, tmp->left);
		if (tmp->right)pushArrayStack(stack1, tmp->right);
	}
	while (popArrayStack(stack2, &tmp) != -1) {
		free(tmp);
		tree->cnt--;
	}



	releaseArrayStack(stack1);
	releaseArrayStack(stack2);
}



void releaseAVLTree(AVLTree* tree)
{
	if (tree && tree->root) {
		release_NoSecur(tree, tree->root);
		printf("\ntree num is %d\n", tree->cnt);
		free(tree);
	}
}
