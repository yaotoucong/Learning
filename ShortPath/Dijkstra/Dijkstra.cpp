#include <stdio.h>
#include <stdlib.h>
#include "Dijkstra.h"

void DijkstraShortPath(Graph* graph, int start, long* dist, int* path)
{
	int length = graph->nodeNum;
	int* mark = (int*)malloc(sizeof(int) * length);
	for (int i = 0;i < length;++i) {
		dist[i] = graph->edge[start][i];
		mark[i] = 0;
		if (dist[i] < INF) {
			path[i] = start;
		}
		else {
			path[i] = -1;
		}
	}
	mark[start] = 1;
	dist[start] = 0;
	path[start] = -1;
	int min, min_index;
	for (int i = 0;i < length-1;++i) {
		min = INF;
		for (int j = 0;j < length;++j) {
			if (mark[j] == 0 && dist[j] < min) {
				min = dist[j];
				min_index = j;
			}
		}
		mark[min_index] = 1;
		for (int j = 0;j < length;++j) {
			if (mark[j] == 0 && ((dist[min_index] + graph->edge[min_index][j]) < dist[j])) {
				dist[j] = dist[min_index] + graph->edge[min_index][j];
				path[j] = min_index;
			}
		}
	}
	free(mark);
}

void showShortPath(int* path,int n,int des)
{
	int* stack = (int*)malloc(sizeof(int) * n);
	int pos = -1;
	while (des != -1) {
		stack[++pos] = des;
		des = path[des];
	}
	while (pos >= 0) {
		if (pos == 0) 
			printf("%d", stack[pos--]);
		else
			printf("%d -> ", stack[pos--]);
	}
	printf("\n");
}



