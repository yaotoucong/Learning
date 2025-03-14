#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

LinkList* createLinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	if (list == NULL) {
		printf("LinkList malloc failt!\n");
	}
	list->header.data = 0;
	list->header.next = NULL;
	list->num = 0;
	return list;
}

static link_node* creatlink_node(Element e) {
	link_node* node = (link_node*)malloc(sizeof(link_node));
	node->data = e;
	node->next = NULL;
	return node;
}

void header_insert(LinkList* list, Element e)
{
	if (list) {
		link_node* p = &list->header;
		link_node* new_node = creatlink_node(e);
		if (p->next == NULL) {
			p->next = new_node;
		}
		else {
			link_node* tmp = p->next;
			new_node->next = tmp;
			p->next = new_node;
		}
		++list->num;
	}
}

void back_insert(LinkList* list, Element e) {
	if (list) {
		link_node* p = &list->header;
		link_node* new_node = creatlink_node(e);
		while (p->next) {
			p = p->next;
		}
		p->next = new_node;
		++list->num;
	}
}

void index_insert(LinkList* list, int pos, Element e)
{
	link_node* new_node = creatlink_node(e);
	link_node* p = &list->header;
	
	// pos : list->header-> 1 -> 2-> 3 -> ....

	if (pos == 0 ) {
		printf("pos violations");
		return;
	}

	if (pos >= list->num) {
		back_insert(list, e);
		return;
	}

	for (int i = 0;i < pos - 1;++i) {
		p = p->next;
	}
	link_node* tmp = p->next;
	p->next = tmp->next;
	new_node->next = tmp;
	p->next = new_node;
	++list->num;
}

void header_delete(LinkList* list)
{
	link_node* p = &list->header;
	if (p->next) {
		link_node* tmp = p->next;
		p->next = tmp->next;
		free(tmp);
		--list->num;
	}
}

void index_delete(LinkList* list, int index) {
	// index : list->header-> 1 -> 2-> 3 -> ....
	if (index == 0) {
		printf("index violations");
		return;
	}
	link_node* p = &list->header;
	if (index >= list->num) {
		while (p->next->next) {
			p = p->next;
		}
		link_node* tmp = p->next;
		p->next = NULL;
		free(tmp);
		--list->num;
	}
	else {
		for (int i = 0;i < index - 1;++i) {
			p = p->next;
		}
		link_node* tmp = p->next;
		p->next = tmp->next;
		free(tmp);
		--list->num;
	}
}

void showLinkList(LinkList* list) {
	if (list) {
		link_node* p = list->header.next;
		while (p) {
			printf("%d\t", p->data);
			p = p->next;
		}
		printf("\nList_num:%d\n", list->num);
	}
}

void releaseLinkList(LinkList* list)
{
	if (list) {
		link_node* p = &list->header;
		link_node* tmp;
		while (p->next) {
			tmp = p->next;
			p->next = tmp->next;
			free(tmp);
			--list->num;
		}
		printf("%d\n", list->num);
		free(list);
	}
}
