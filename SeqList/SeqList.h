#ifndef __SeqList__
#define __SeqList__

typedef int Element;

typedef struct {
	Element* data;
	int length;
	int capacity;
}Seqlist;

Seqlist* createSeqlist(int n);
int PushBackSeq(Seqlist* seqlist, Element e);
int insertSeq(Seqlist* seqlist, int pos, Element e);
void deleteSeq_index(Seqlist* seqlist, int index);
void deleteSeq_num(Seqlist* seqlist, int num);
void showSeq(Seqlist* seqlist);

void realeaseSeqlist(Seqlist* seqlist);





#endif 
