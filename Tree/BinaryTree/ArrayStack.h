#ifndef __ArrayStack__
#define __ArrayStack__
#include "BinaryTree.h"

typedef TreeNode* Element;
#define MaxStackSize 20

typedef struct {
	Element data[MaxStackSize];
	int length;
	int capacity;
}ArrayStaack;

ArrayStaack* createArrayStack();
void pushArrayStack(ArrayStaack* stack, Element e);
Element getArrayStack(ArrayStaack* stack);
//int popArrayStack(ArrayStaack* stack);
int popArrayStack(ArrayStaack* stack, Element* e);
void showArrrayStack(ArrayStaack* stack);
void releaseArrayStack(ArrayStaack* stack);




#endif