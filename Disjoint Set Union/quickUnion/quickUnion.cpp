#include <stdio.h>
#include <stdlib.h>
#include "quickUnion.h"

quickUnionSet* createquickUnionSet(int capacity)
{
	quickUnionSet* set = (quickUnionSet*)malloc(sizeof(quickUnionSet));
	if (set == NULL) {
		free(set);
		printf("set malloc fail!\n");
		return NULL;
	}
	set->data = (Element*)malloc(sizeof(Element) * capacity);
	set->parent = (int*)malloc(sizeof(int*) * capacity);
	set->size= (int*)malloc(sizeof(int*) * capacity);
	set->n = 0;
	set->capacity = capacity;
	return set;
}

void initquickUnionSet(quickUnionSet* set, Element* data,int n)
{
	if (data && set) {
		for (int i = 0;i < n;++i) {
			set->data[i] = data[i];
			set->parent[i] = i;
			set->size[i] = 1;
		}
		set->n = n;
	}
}

static int findIndex(quickUnionSet* set, Element e) {
	if (set) {
		for (int i = 0;i < set->n;++i) {
			if (set->data[i] == e)
				return i;
		}
		return -1;
	}
}

#define __PATH_COMPRESS__
#ifndef __PATH_COMPRESS__
static int findParent(quickUnionSet* set, Element e) {
	int index = findIndex(set, e);
	if (index == -1) return -1;
	while (index != set->parent[index]) {
		index = set->parent[index];
	}
	return index;
}
#else
static SetNode* pushNode(SetNode* top, int index) {
	SetNode* node = (SetNode*)malloc(sizeof(SetNode));
	if (node == NULL) printf("node malloc fail!\n");
	node->data = index;
	node->next = top;
	return node;
}

static SetNode* popNode(SetNode* top, int* e) {
	if (top && e) {
		*e = top->data;
		SetNode* tmp = top;
		top = top->next;
		free(tmp);
		return top;
	}
}

static int findParent(quickUnionSet* set, Element e) {
	int index = findIndex(set, e);
	if (index == -1) return -1;
	SetNode* top = NULL;
	while (index != set->parent[index]) {
		top = pushNode(top, index);
		index = set->parent[index];
	}
	int element;
	while (top) {
		top = popNode(top, &element);
		set->parent[element] = index;
	}
	return index;
}
#endif

int isSameParent(quickUnionSet* set, Element a, Element b)
{	
	int p_a = findParent(set, a);
	int p_b = findParent(set, b);
	if (p_a == -1 || p_b == -1) {
		printf("not find Element\n");
		return -1;
	}
	return p_a==p_b;
}

int UnionParent(quickUnionSet* set, Element a, Element b)
{
	if (a == b) {
		printf("a and b is Same Parent\n");
		return -1;
	}
	int p_a = findParent(set, a);
	int p_b = findParent(set, b);
	
	int size_a = set->size[p_a];
	int size_b = set->size[p_b];
	int ID;
	if (size_a >= size_b) {
		set->parent[p_b] = p_a;
		set->size[a] += size_b;

	}
	else {
		set->parent[p_a] = p_b;
		set->size[p_b] += size_a;
	}
	return 0;
}

void releasequickUnionSet(quickUnionSet* set)
{
	if (set) {
		if (set->data) free(set->data);
		if (set->size) free(set->size);
		if (set->parent) free(set->parent);
		free(set);
	}
}
