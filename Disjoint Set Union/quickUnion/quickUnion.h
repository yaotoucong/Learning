#ifndef __quickUnion__
#define __quickUnion__

typedef int Element;

typedef struct {
	Element* data;
	int* parent;
	int* size;
	int n;
	int capacity;
}quickUnionSet;

typedef struct Set_Node {
	int data;
	struct Set_Node* next;
}SetNode;

quickUnionSet* createquickUnionSet(int capacity);
void initquickUnionSet(quickUnionSet* set, Element* data,int n);
int isSameParent(quickUnionSet* set, Element a, Element b);
int UnionParent(quickUnionSet* set, Element a, Element b);
void releasequickUnionSet(quickUnionSet* set);





#endif