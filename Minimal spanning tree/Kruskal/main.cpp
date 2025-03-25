#include <stdio.h>
#include <stdlib.h>
#include "Kruskal.h"

void initGraph(Graph* graph, char* datas,int n,int init) {
	initMatrixGraph(graph, datas, n, init, 0);
	addGraphEdge(graph, 0, 1, 12);
	addGraphEdge(graph, 0, 5, 16);
	addGraphEdge(graph, 0, 6, 14);
	addGraphEdge(graph, 1, 2, 10);
	addGraphEdge(graph, 1, 5, 7);
	addGraphEdge(graph, 2, 3, 3);
	addGraphEdge(graph, 2, 4, 5);
	addGraphEdge(graph, 2, 5, 6);
	addGraphEdge(graph, 3, 4, 4);
	addGraphEdge(graph, 4, 5, 2);
	addGraphEdge(graph, 4, 6, 8);
	addGraphEdge(graph, 5, 6, 9);

	
}

void test() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	char datas[] = {'A','B','C','D','E','F','G'};
	initGraph(graph, datas,sizeof(datas)/sizeof(datas[0]),INF);

	EdgeSet* set = initEdgeSet(graph);
	int length = graph->edgeNum;
	sortEdgeSet(set, length);

	EdgeSet* result = (EdgeSet*)malloc(sizeof(EdgeSet) * (graph->nodeNum - 1));
	int sum = Kruskal_MGraph(graph, set, length, result);
	for (int i = 0;i < graph->nodeNum - 1;++i) {
		printf("[%c]----<%d>----[%c]\n", graph->vex[result[i].begin].show, result[i].weight, graph->vex[result[i].end].show);
	}

	printf("\ntotal is %d\n", sum);

	free(set);
	free(result);
	releaseMatrixGraph(graph);
}

int main() {
	test();
	return 0;
}