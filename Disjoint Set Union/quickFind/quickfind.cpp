#include <stdio.h>
#include <stdlib.h>
#include "quickfind.h"

QuickFindSet* createQuickFindSet(int n)
{
	QuickFindSet* set = (QuickFindSet*)malloc(sizeof(QuickFindSet));
	set->data = (Element*)malloc(sizeof(Element) * n);
	set->group = (int*)malloc(sizeof(int) * n);
	set->n = 0;
	set->capacity = n;
	return set;
}

void initQuickFindSet(QuickFindSet* set,Element *data,int n)
{
	if (data && set) {
		for (int i = 0;i < n;++i) {
			set->data[i] = data[i];
			set->group[i] = i;
		}
		set->n = n;
	}
}

static int find_Index(QuickFindSet* set, Element e) {
	for (int i = 0;i < set->n;++i) {
		if (set->data[i] == e) return i;
	}
	return -1;
}

int isSameGroup(QuickFindSet* set, Element a, Element b)
{
	int a_ = find_Index(set, a);
	int b_ = find_Index(set, b);
	if (a_ == -1 || b_ == -1) {
		return -1;
	}
	return set->group[a_]==set->group[b_];
}

int UnionGroup(QuickFindSet* set, Element a, Element b)
{
	int a_ = find_Index(set, a);
	int b_ = find_Index(set, b);
	if (a_ == -1 || b_ == -1) {
		return -1;
	}
	int p_a = set->group[a_];
	int p_b = set->group[b_];
	int ID = p_a;
	for (int i = 0;i < set->n;++i) {
		if (set->group[i] == ID) {
			set->group[i] = p_b;
		}
	}
	return 0;
}

void releaseQuickFindSet(QuickFindSet* set)
{
	if (set) {
		if (set->data) free(set->data);
		if (set->group) free(set->group);
		free(set);
	}
}
