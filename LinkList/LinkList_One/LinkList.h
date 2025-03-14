#ifndef __LinkList_One__
#define __LinkList_One__

typedef int Element;

typedef struct _link_node {
	Element data;
	struct _link_node *next;
}link_node;

typedef struct {
	link_node header;
	int num;
}LinkList;

LinkList* createLinkList();
void header_insert(LinkList* list, Element e);
void back_insert(LinkList* list, Element e);
void index_insert(LinkList* list, int pos,Element e);
void header_delete(LinkList* list);
void index_delete(LinkList* list, int index);
void showLinkList(LinkList* list);
void releaseLinkList(LinkList* list);


#endif 
