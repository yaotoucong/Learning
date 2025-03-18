#ifndef __AVLTree__
#define __AVLTree__

typedef int Element;

typedef struct AVL_Node_ {
	Element data;
	struct AVL_Node_* left;
	struct AVL_Node_* right;
	int high;
}AVL_Node;

typedef struct {
	int cnt;
	AVL_Node* root;
}AVLTree;

AVLTree* createAVLTree();
int AVLTreeHigh(AVL_Node *node);
void InOrderAVLTree(AVLTree* tree);
void insertAVLNode(AVLTree* tree, Element e);
void deleteAVLNode(AVLTree* tree, Element e);
void releaseAVLTree(AVLTree* tree);


#endif