#ifndef __LinkStack__
#define __LinkStack__

typedef int Element;
typedef struct link_node_{
	struct link_node_* next;
	Element data;
}link_node;

typedef struct {
	link_node* top;
	int num;
}LinkStack;

LinkStack* createLinkStack();
void pushLinkStack(LinkStack* stack, Element e);
void popLinkStack(LinkStack* stack, Element* e);
void showStack(LinkStack* stack);
void releaseLinkStack(LinkStack* stack);

#endif