#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

void test() {
	CircularList* list = createCircularList();
	int x, n;
	scanf_s("%d", &n);
	scanf_s("%d", &x);
	for (int i = 1;i <= n;++i) {
		insertRear(list, i);
	}
	LinkNode* p = &list->head;
	for(int i=0;i<x;++i){
		p = p->next;
	}
	int num;
	scanf_s("%d", &num);
	int cnt;
	LinkNode* tmp;
	while (list->cnt>1) {
		cnt = 1;
		while (cnt != num) {
			if(p->next==&list->head) p = p->next;
			p = p->next;
			cnt++;
		}
		tmp = p->next;
		deleteNode(list, p->e);
		if (tmp == &list->head) 
			p = tmp->next;
		else
			p = tmp;
	}
	printf("\nexists man is %d\n", list->head.next->e);
	//for (int i = 0;i < 10;++i) {
	//	insertRear(list, 100 + i);
	//}
	//visitCircularList(list);

	//deleteIndex(list, 10);
	//visitCircularList(list);*/

	//deleteNode(list, 104);
	//visitCircularList(list);

	releaseCircularList(list);
}

int main() {
	test();






	return 0;
}