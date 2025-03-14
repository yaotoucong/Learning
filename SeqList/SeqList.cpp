#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

Seqlist* createSeqlist(int n)
{	
	Seqlist* seqlist = (Seqlist*)malloc(sizeof(Seqlist));
	if (seqlist == NULL) {
		printf("SeqList malloc fail!\n");
	}

	seqlist->data = (Element*)malloc(sizeof(Element) * n);
	if (seqlist->data == NULL) {
		printf("SeqList->data malloc fail!\n");
	}

	seqlist->capacity = n;
	seqlist->length = 0;     //待插入位置

	return seqlist;
}

static int enLargerSeq(Seqlist* seqlist) {
	Element* tmp = (Element*)malloc(sizeof(Element) * (seqlist->capacity * 2));
	if (tmp == NULL) {
		printf("enLargeSeq malloc fail!\n");
		return -1;
	}
	for (int i = 0;i < seqlist->length;++i) {
		tmp[i] = seqlist->data[i];
	}
	free(seqlist->data);
	seqlist->data = tmp;
	seqlist->capacity *= 2;
	return 0;
}

int PushBackSeq(Seqlist* seqlist, Element e)
{
	if (seqlist->length >= seqlist->capacity && enLargerSeq(seqlist)) {
		printf("PushBackSeq fail!\n");
		return -1;
	}
	seqlist->data[seqlist->length++] = e;


	return 0;
}

int insertSeq(Seqlist* seqlist, int pos, Element e)
{
	if (seqlist->length >= seqlist->capacity && enLargerSeq(seqlist)) {
		printf("InsertSeq fail!\n");
		return -1;
	}
	
	//pos : 0 ,1 ,2 ,3
	/*
	for (int i = seqlist->length - 1;i >= pos;--i) {
		seqlist->data[i + 1] = seqlist->data[i];
	}
	seqlist->data[pos] = e;
	seqlist->length++;
	*/


	//pos ; 1 ,2 ,3 ,4
	
	pos -= 1;
	for (int i = seqlist->length;i > pos - 1;--i) {
		seqlist->data[i] = seqlist->data[i - 1];
	}
	seqlist->data[pos] = e;
	seqlist->length++;
	


	return 0;
}

void deleteSeq_index(Seqlist* seqlist, int index)
{
	if (index < 0 || index >= seqlist->length) {
		printf("deleteSeq_index fail!\n");
		return;
	}

	/*
	// pos: 0 , 1 , 2

	for (int i = index;i < seqlist->length;--i) {
		seqlist->data[i] = seqlist->data[i + 1];       //版本1（错误版），这里犯错了，把seqlist->length的位置也往前面移动了
	}
	seqlist->length--;

	//pos: 1 , 2 , 3

	for (int i = index + 1;i < seqlist->length - 2;--i) {
		seqlist->data[i - 1] = seqlist->data[i];
	}
	seqlist->length--;

	*/

	// pos: 0 , 1 , 2
	/*for (int i = index;i < seqlist->length-1;++i) {
		seqlist->data[i] = seqlist->data[i + 1];       //版本2（已修改），究极无敌逆天，++i写出--i，眼瞎看半天
	}
	seqlist->length--;*/

	//pos: 1 , 2 , 3
	index -= 1;
	for (int i = index + 1;i < seqlist->length ;++i) {
		seqlist->data[i - 1] = seqlist->data[i];
	}
	seqlist->length--;

	
	
}

void deleteSeq_num(Seqlist* seqlist, int num)
{	
	int index = -1;
	for (int i = 0;i < seqlist->length;++i) {
		if (seqlist->data[i] == num) index = i;
	}
	if (index == -1) {
		printf("deleteSeq_num fail!----------not found num\n");
		return;
	}
	
	if (index < 0 || index >= seqlist->length) {
		printf("deleteSeq_index fail!\n");
		return;
	}

	for (int i = index;i < seqlist->length - 1;++i) {
		seqlist->data[i] = seqlist->data[i + 1];       
	}
	seqlist->length--;
}

void showSeq(Seqlist* seqlist)
{
	if (seqlist && seqlist->data) {
		printf("\ndata:\n");
		for (int i = 0;i < seqlist->length;++i) {
			printf("%d\t", seqlist->data[i]);
		}
	}
}





void realeaseSeqlist(Seqlist* seqlist)
{
	if (seqlist) {
		if (seqlist->data) 
			free(seqlist->data);
		free(seqlist);
	}
}
