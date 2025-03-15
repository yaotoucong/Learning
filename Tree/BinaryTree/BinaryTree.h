#ifndef __BinaryTree__
#define __BinaryTree__

//typedef char Element;

typedef struct Tree_Node {
	char data;
	struct Tree_Node* left;
	struct Tree_Node* right;
}TreeNode;

typedef struct {
	TreeNode* root;
	int num;
}BinaryTree;

BinaryTree* createBinaryTree();
TreeNode* createTreeNode(char e);
void initTreeRoot(BinaryTree* tree, TreeNode* node);
void insertTreeNode(BinaryTree* tree, TreeNode* parent, TreeNode* left, TreeNode* right);

void levelOrderBinaryTree(BinaryTree* tree);

void PreOrderBinaryTree(BinaryTree* tree);
void inOrderBinaryTree(BinaryTree* tree);
void postOrderBinaryTree(BinaryTree* tree);

void PreOrderBinaryTree_Norecur(BinaryTree* tree);
void inOrderBinaryTree_Norecur(BinaryTree* tree);
void postOrderBinaryTree_Norecur(BinaryTree* tree);

void releaseBinaryTree(BinaryTree* tree);





#endif