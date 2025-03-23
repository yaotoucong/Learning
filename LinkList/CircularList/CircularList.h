#ifndef __CircularList__
#define __CircularList__

typedef int Element;

typedef struct Link_Node {
	Element e;
	struct Link_Node* next;
}LinkNode;

typedef struct {
	LinkNode head;
	LinkNode* rear;
	int cnt;
}CircularList;


CircularList* createCircularList();
void insertHead(CircularList* list, Element e);
void insertRear(CircularList* list, Element e);
void deleteHead(CircularList* list);
void deleteRear(CircularList* list);
void deleteIndex(CircularList* list, int index);
void deleteNode(CircularList* list, Element e);
void visitCircularList(CircularList* list);
void releaseCircularList(CircularList* list);






#endif