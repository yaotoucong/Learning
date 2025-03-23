#ifndef __Doubly Linked List__
#define __Doubly Linked List__

typedef int Element;
typedef struct Link_Node {
	Link_Node* left;
	Element e;
	Link_Node* right;
}LinkNode;


typedef struct {
	LinkNode head;
	int cnt;
}Double_List;

Double_List* createDouble_List();
void insertHead(Double_List* list, Element e);
void insertRear(Double_List* list, Element e);
void deleteHead(Double_List* list);
void deleteRear(Double_List* list);
void deleteIndex(Double_List* list, int index);
void visitList(Double_List* list);
void releaseDouble_List(Double_List* list);












#endif