#include <stdio.h>
#include <stdlib.h>
#include "Kruskal.h"

EdgeSet* initEdgeSet(Graph* graph)
{
	int length = graph->edgeNum;
	EdgeSet* set = (EdgeSet*)malloc(sizeof(EdgeSet) * length);
	int pos = 0;
	for (int i = 0;i < graph->nodeNum;++i) {
		for (int j = i+1;j < graph->nodeNum;++j) {
			if (graph->edge[i][j] < INF) {
				set[pos].begin = i;
				set[pos].weight = graph->edge[i][j];
				set[pos].end = j;
				pos++;
			}	
		}
	}
	return set;
}

void sortEdgeSet(EdgeSet* set,int n)
{
	if (set) {
		EdgeSet tmp;
		for (int i = 0;i < n - 1;++i) {
			for (int j = 0;j < n - 1 - i;++j) {
				if (set[j].weight > set[j + 1].weight) {
					tmp = set[j];
					set[j] = set[j + 1];
					set[j + 1] = tmp;
				}
			}
		}
	}
	/*for (int i = 0;i < n;++i) {
		printf("%d\t", set[i].weight);
	}*/
}

static int findparent(int* parent,int x) {
	while (x != parent[x]) {
		x = parent[x];
	}
	return x;
}

int Kruskal_MGraph(Graph* graph, EdgeSet* set,int n, EdgeSet* result)
{	
	int sum = 0;
	int pos = 0;
	int* parent = (int*)malloc(sizeof(int)* graph->nodeNum);
	for (int i = 0;i < graph->nodeNum;++i) {
		parent[i] = i;
	}
	int a, b;
	int p_a,p_b;
	for (int i = 0;i < n;++i) {
		a = set[i].begin;
		b = set[i].end;
		p_a = findparent(parent, a);
		p_b = findparent(parent, b);
		if (p_a == p_b) continue;
		result[pos].begin = a;
		result[pos].end = b;
		result[pos].weight = set[i].weight;
		sum += set[i].weight;
		pos++;
		parent[p_a] = p_b;
	}
	free(parent);
	return sum;
}
