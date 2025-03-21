#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdjacencyList.h"

void test() {
	char datas[] = { 'a','b','c','d','e' };
	Graph* graph = createAdjacencyList(datas, sizeof(datas) / sizeof(datas[0]), 1);
	addArcNode(graph, 0, 4, 1);
	addArcNode(graph, 0, 3, 1);	
	addArcNode(graph, 0, 1, 1);
	addArcNode(graph, 1, 4, 1);
	addArcNode(graph, 1, 2, 1);
	addArcNode(graph, 2, 0, 1);
	addArcNode(graph, 3, 2, 1);
	printf("%d\n", graph->EdgeNum);
	printf("DFS:\n");
	DFS_AdjacencyList(graph, 0);
	
	printf("\nDFS_NoSecur:\n");
	DFS_AdjacencyList_NoSecur(graph, 0);
	printf("\nBFS_NoSecur:\n");
	BFS_AdjacencyList_NoSecur(graph, 0);
	releaseAdjacencyList(graph);
}

int main() {

	test();
	return 0;
}