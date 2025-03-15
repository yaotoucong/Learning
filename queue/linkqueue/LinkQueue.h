#ifndef __LinkQueue__
#define __LinkQueue__

typedef int Element;

typedef struct link_node_ {
	Element data;
	struct link_node_* next;
}link_node;

typedef struct {
	link_node* front;
	link_node* rear;
	int num;
}LinkQueue;

LinkQueue* createLinkQueue();
void pushLinkQueue(LinkQueue* queue, Element e);
int popLinkQueue(LinkQueue* queue, Element* e);
void releaseLinkQueue(LinkQueue* queue);





#endif 