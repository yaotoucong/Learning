#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

CircularList* createCircularList()
{
	CircularList* list = (CircularList*)malloc(sizeof(CircularList));
	list->cnt = 0;
	list->rear = NULL;
	list->head.e = 0;
	list->head.next = &list->head;

	return list;
}

static LinkNode* createLinkNode(Element e) {
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->e = e;
	node->next = NULL;
	return node;
}

void insertHead(CircularList* list, Element e)
{	
	LinkNode* node = createLinkNode(e);
	if (node == NULL) {
		printf("new node malloc fail!\n");
		return;
	}
	if (list->head.next == &list->head) list->rear = node;
	node->next = list->head.next;
	list->head.next = node;
	list->cnt++;
}

void insertRear(CircularList* list, Element e)
{
	LinkNode* node = createLinkNode(e);
	if (node == NULL) {
		printf("new node malloc fail!\n");
		return;
	}
	list->cnt++;
	if (list->head.next == &list->head) {
		node->next = list->head.next;
		list->head.next = node;
		list->rear = node;
		return;
	}
	list->rear->next = node;
	node->next = &list->head;
	list->rear = node;
}

void deleteNode(CircularList* list, Element e) {
	if (list) {
		if (list->head.next != &list->head) {
			LinkNode* p = &list->head;
			int index = 0;

			while (p->next != &list->head) {
				if (p->next->e == e) {
					deleteIndex(list, ++index);
					return;
				}
				index++;
				p = p->next;
			}
		}
	}
}

void deleteHead(CircularList* list)
{
	if (list) {
		if (list->head.next != &list->head) {
			LinkNode* tmp = list->head.next;
			if (tmp->next == &list->head) {
				list->head.next = &list->head;
				list->rear = NULL;
				free(tmp);
			}
			else {
				list->head.next = tmp->next;
				free(tmp);
			}
			list->cnt--;

		}
	}
}

void deleteRear(CircularList* list)
{
	if (list) {
		if (list->head.next != &list->head) {
			LinkNode* tmp;
			if (list->head.next->next == &list->head) {
				tmp = list->head.next;
				list->head.next = &list->head;
				list->rear = NULL;
				free(tmp);
			}
			else {

			}
		}
	}
}

void deleteIndex(CircularList* list, int index) {
	if (index<1 || index>list->cnt) {
		return;
	}
	LinkNode* p = &list->head;
	for (int i = 0;i < index - 1;++i) {
		p = p->next;
	}
	LinkNode* tmp = p->next;
	if (tmp->next == &list->head) {
		if (p == &list->head) {
			free(tmp);
			list->head.next = &list->head;
			list->rear = NULL;
			list->cnt--;
		}
		else {
			p->next = tmp->next;
			list->rear = p;
			free(tmp);
			list->cnt--;
		}
	}
	else {
		p->next = tmp->next;
		free(tmp);
		list->cnt--;
	}
}

void visitCircularList(CircularList* list) {
	if (list) {
		LinkNode* p = list->head.next;
		LinkNode* tmp;
		while (p != &list->head) {
			tmp = p;
			p = p->next;
			printf("%d\t", tmp->e);
		}
		printf("\n");
	}
}



void releaseCircularList(CircularList* list)
{
	if (list) {
		LinkNode* p = list->head.next;
		LinkNode* tmp;
		while (p != &list->head) {
			tmp = p;
			p = p->next;
			free(tmp);
			list->cnt--;
		}
		printf("list count is %d\n", list->cnt);
		free(list);
	}
}


