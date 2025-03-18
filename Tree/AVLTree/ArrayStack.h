#ifndef __ArrayStack__
#define __ArrayStack__
#include "AVLTree.h"

typedef AVL_Node* Ele;
#define MaxStackSize 202444412312

typedef struct {
	Ele *data;
	int length;
	int capacity;
}ArrayStaack;

ArrayStaack* createArrayStack(int n);
void pushArrayStack(ArrayStaack* stack, Ele e);
Ele getArrayStack(ArrayStaack* stack);
//int popArrayStack(ArrayStaack* stack);
int popArrayStack(ArrayStaack* stack, Ele* e);
void showArrrayStack(ArrayStaack* stack);
void releaseArrayStack(ArrayStaack* stack);




#endif