#ifndef __ThreadBTree__
#define __ThreadBTree__

typedef char Element;

typedef struct Tree_Node {
	char data;
	struct Tree_Node* left;
	struct Tree_Node* right;
	int Ltag;
	int Rtag;
}TreeNode;

typedef struct {
	TreeNode* root;
	int num;
	int tag;   // 0:default 1:pre 2:in 3:post
}ThreadBTree;

ThreadBTree* createThreadBTree();
TreeNode* createTreeNode(Element e);
void initTreeRoot(ThreadBTree* tree, TreeNode* node);
void insertTreeNode(ThreadBTree* tree, TreeNode* parent, TreeNode* left, TreeNode* right);

void inOrderThreadedTree(ThreadBTree* tree);
void inOrederTree(ThreadBTree* tree);
void releaseThreadBTree(ThreadBTree* tree);


#endif