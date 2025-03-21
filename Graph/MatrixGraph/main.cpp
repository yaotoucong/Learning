#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MatrixGraph.h"

void test() {
	Graph graph;
	char names[] = { '1','2','3','4','5','6','7','8'};
	initMatrixGraph(&graph, names, sizeof(names) / sizeof(names[0]), INF,0);
	addGraphEdge(&graph, 0, 1, 1);
	addGraphEdge(&graph, 0, 2, 1);
	addGraphEdge(&graph, 1, 3, 1);
	addGraphEdge(&graph, 1, 4, 1);
	addGraphEdge(&graph, 2, 5, 1);
	addGraphEdge(&graph, 2, 6, 1);
	addGraphEdge(&graph, 3, 7, 1);
	addGraphEdge(&graph, 4, 7, 1);
	addGraphEdge(&graph, 5, 6, 1);
	printf("DFS:\n");
	DFSMatrixGraph(&graph, 0);
	printf("\nDFS_NoSecur:\n");
	DFSMatrixGraph_NoSecur(&graph, 0);
	printf("\nBFS:\n");
	BFSMatrixGraph(&graph, 0);
}

int main() {
	
	test();
	return 0;
}