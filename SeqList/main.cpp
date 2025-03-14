#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

void test() {
	Seqlist* seqlist = createSeqlist(20);
	for (int i = 0;i < 6;++i) {
		PushBackSeq(seqlist, i + 100);
	}
	showSeq(seqlist);

	insertSeq(seqlist, 4, 7);
	showSeq(seqlist);

	deleteSeq_index(seqlist, 3);
	showSeq(seqlist);

	deleteSeq_num(seqlist, 105);
	showSeq(seqlist);

	realeaseSeqlist(seqlist);
}


int main() {
	test();


	return 0;
}

