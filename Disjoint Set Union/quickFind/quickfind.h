#ifndef __quickfind__
#define __quickfind__

typedef int Element;

typedef struct {
	Element* data;
	int* group;
	int n;
	int capacity;
}QuickFindSet;

QuickFindSet* createQuickFindSet(int n);
void initQuickFindSet(QuickFindSet* set, Element* data, int n);
int isSameGroup(QuickFindSet* set, Element a, Element b);
int UnionGroup(QuickFindSet* set, Element a, Element b);
void releaseQuickFindSet(QuickFindSet* set);


#endif