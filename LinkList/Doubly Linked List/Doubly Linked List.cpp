#include <stdio.h>
#include <stdlib.h>
#include "Doubly Linked List.h"

Double_List* createDouble_List()
{
	Double_List* list = (Double_List*)malloc(sizeof(Double_List));
	list->head.e = 0;
	list->head.left = NULL;
	list->head.right = &list->head;
	list->cnt = 0;
	return list;
}

static LinkNode* createLinkNode(Element e) {
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->e = e;
	node->left = node->right = NULL;
	return node;
}

void insertHead(Double_List* list, Element e)
{
	LinkNode* node = createLinkNode(e);
	list->cnt++;
	if (list->head.right == &list->head) {
		list->head.right = node;
		list->head.left = node;
		node->left = &list->head;
		node->right= &list->head;
		return;
	}
	node->right = list->head.right;
	node->left = &list->head;
	list->head.right->left = node;
	list->head.right = node;
}

void insertRear(Double_List* list, Element e)
{
	LinkNode* node = createLinkNode(e);
	list->cnt++;
	if (list->head.right == &list->head) {
		list->head.right = node;
		list->head.left = node;
		node->left = &list->head;
		node->right = &list->head;
		return;
	}
	node->left = list->head.left;
	list->head.left->right = node;
	node->right = &list->head;
	list->head.left = node;
}

void deleteHead(Double_List* list)
{
	if (list->head.right == &list->head) {
		return;
	}
	LinkNode* tmp = list->head.right;
	if (tmp->right == &list->head) {
		free(tmp);
		list->head.left = NULL;
		list->head.right = &list->head;
		list->cnt--;
		return;
	}
	tmp->right->left = &list->head;
	list->head.right = tmp->right;
	free(tmp);
	list->cnt--;

}

void deleteRear(Double_List* list)
{
	if (list->head.right == &list->head) {
		return;
	}
	LinkNode* tmp = list->head.left;
	if (tmp->left == &list->head) {
		free(tmp);
		list->head.left = NULL;
		list->head.right = &list->head;
		list->cnt--;
		return;
	}
	tmp->left->right = &list->head;
	list->head.left = tmp->left;
	free(tmp);
	list->cnt--;
}

void deleteIndex(Double_List* list, int index)
{
	if (index<1 || index>list->cnt) {
		return;
	}

	for (int i = 0;i < index;++i) {

	}
}

void visitList(Double_List* list) {
	if (list) {
		LinkNode* p = list->head.right;
		LinkNode* tmp;
		while (p != &list->head) {
			tmp = p;
			p = p->right;
			printf("%d\t", tmp->e);
		}
		printf("\n");
	}
}

void releaseDouble_List(Double_List* list)
{
	if (list) {
		LinkNode* p = list->head.right;
		LinkNode* tmp;
		while (p != &list->head) {
			tmp = p;
			p = p->right;
			free(tmp);
			list->cnt--;
		}
		printf("list num is%d\n", list->cnt);
		free(list);
	}
}
