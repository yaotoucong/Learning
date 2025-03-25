#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

void initGraph(Graph* graph, char* datas, int n, int init) {
	initMatrixGraph(graph, datas, n, init, 0);
	addGraphEdge(graph, 0, 1, 4);
	addGraphEdge(graph, 0, 2, 6);
	addGraphEdge(graph, 0, 3, 6);
	addGraphEdge(graph, 1, 4, 7);
	addGraphEdge(graph, 1, 2, 1);
	addGraphEdge(graph, 2, 4, 6);
	addGraphEdge(graph, 2, 5, 4);
	addGraphEdge(graph, 3, 2, 2);
	addGraphEdge(graph, 3, 5, 5);
	addGraphEdge(graph, 4, 6,6);
	addGraphEdge(graph, 5, 4, 1);
	addGraphEdge(graph, 5, 6, 8);


}

void test() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	char datas[] = { '0','1','2','3','4','5','6' };
	initGraph(graph, datas, sizeof(datas) / sizeof(datas[0]), INF);

	int* path = (int*)malloc(sizeof(int) * graph->nodeNum);
	long* dist = (long*)malloc(sizeof(long) * graph->nodeNum);
	int start;
	//scanf_s("%d", &start);
	DijkstraShortPath(graph, 0, dist, path);
	for (int i = 0;i < graph->nodeNum;++i) {
		printf("<%c--->%c> cost:%d\n", graph->vex[0].show, graph->vex[i].show, dist[i]);
	}
	printf("===================\n");
	showShortPath(path, graph->nodeNum, 5);
	showShortPath(path, graph->nodeNum, 3);
	showShortPath(path, graph->nodeNum, 6);

	free(path);
	free(dist);
	releaseMatrixGraph(graph);
}

int main() {
	test();
	return 0;
}