#include <stdio.h>
#include <stdlib.h>
#include "Prim.h"

void PrimMGraph(Graph* graph, EdgeSet* set,int start)
{
	int length = graph->nodeNum;
	int* mark = (int*)malloc(sizeof(int) * length);
	int* path = (int*)malloc(sizeof(int) * length);
	long* cost = (long*)malloc(sizeof(long) * length);
	for (int i = 0;i < length;++i) {
		cost[i] = graph->edge[start][i];
		mark[i] = 0;
		if (graph->edge[start][i] < INF) {
			path[i] = start;
		}
		else {
			path[i] = -1;
		}
	}
	mark[start] = 1;
	int min = INF;
	int min_index = -1;
	int pos = 0;
	for (int i = 0;i < length - 1;++i) {
		min = INF;
		for (int j = 0;j < length;++j) {
			if (mark[j] == 0 && cost[j] < min) {
				min = cost[j];
				min_index = j;
			}
		}
		set[pos].begin = path[min_index];
		set[pos].weight = min;
		set[pos].end = min_index;
		pos++;
		mark[min_index] = 1;
		for (int k = 0;k < length;++k) {
			if (mark[k] == 0 && graph->edge[min_index][k] < cost[k]) {
				cost[k] = graph->edge[min_index][k];
				path[k] = min_index;
			}
		}

	}



	free(mark);
	free(path);
	free(cost);
}
