#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AdjacencyList.h"

Graph* createAdjacencyList(char* datas, int n, int directed)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->nodes = (arcNode*)malloc(sizeof(arcNode) * n);
	graph->visits = (int*)malloc(sizeof(int) * n);
	graph->directed = directed;
	graph->EdgeNum = 0;
	graph->NodeNum = n;
	for (int i = 0;i < n;++i) {
		graph->nodes[i].data = datas[i];
		graph->nodes[i].index = i;
		graph->nodes[i].firstEdge = NULL;
		graph->visits[i] = 0;
	}
	return graph;
}

static int isEdge(Graph* graph, int a, int b) {
	arcEdge* p = graph->nodes[a].firstEdge;
	while (p) {
		if (p->index == b) {
			return 1;
		}
		p = p->next;	
	}
	return 0;
}

static arcEdge* createArcEdge(int index, Element weight) {
	arcEdge* node = (arcEdge*)malloc(sizeof(arcEdge));
	node->index = index;
	node->weight = weight;
	node->next = NULL;
	return node;
}

int addArcNode(Graph* graph, int a, int b, Element weight)
{
	if (a == b) return 0;
	if (a < 0 || a >= graph->NodeNum) {
		return 0;
	}
	if (b < 0 || b >= graph->NodeNum) {
		return 0;
	}
	if (isEdge(graph, a, b)) {
		return 0;
	}
	arcEdge* Edge = createArcEdge(b, weight);
	Edge->next = graph->nodes[a].firstEdge;
	graph->nodes[a].firstEdge = Edge;
	graph->EdgeNum++;
	if (graph->directed == 0) {
		arcEdge* Edge1 = createArcEdge(a, weight);
		Edge1->next = graph->nodes[b].firstEdge;
		graph->nodes[b].firstEdge = Edge1;
		//graph->EdgeNum++;
	}
	return 1;
}

static void visitNode(Graph* graph, int pos) {
	printf("%c\t", graph->nodes[pos].data);
}

void DFS_AdjacencyList(Graph* graph, int pos)
{
	arcEdge* tmp = graph->nodes[pos].firstEdge;
	visitNode(graph, pos);
	graph->visits[pos] = 1;
	int index;
	while (tmp) {
		index = tmp->index;
		if (graph->visits[index] == 0) {
			DFS_AdjacencyList(graph, index);
		}
		tmp = tmp->next;
	}
}



void DFS_AdjacencyList_NoSecur(Graph* graph, int pos)
{
	memset(graph->visits, 0, sizeof(int) * graph->NodeNum);
	int* stack = (int*)malloc(sizeof(int) * graph->NodeNum);
	memset(stack, 0, sizeof(int) * graph->NodeNum);


	int top = -1;
	stack[++top] = pos;
	graph->visits[pos] = 1;
	arcEdge* tmp;
	while (top >= 0) {
		pos = stack[top--];
		tmp = graph->nodes[pos].firstEdge;
		visitNode(graph, pos);
		while (tmp) {
			if (graph->visits[tmp->index] == 0) {
				stack[++top] = tmp->index;
				graph->visits[tmp->index] = 1;
			}
			tmp = tmp->next;
		}
	}

}



void BFS_AdjacencyList_NoSecur(Graph* graph, int pos)
{
	memset(graph->visits, 0, sizeof(int) * graph->NodeNum);
	int length = graph->NodeNum + 1;
	int* queue = (int*)malloc(sizeof(int) * length * 2);
	int front = 0, rear = 0;
	memset(queue, 0, sizeof(int) * length * 2);
	arcEdge* tmp;
	queue[rear] = pos;
	rear = (rear + 1) % length;
	graph->visits[pos] = 1;
	int index;
	while (rear != front) {
		index = queue[front];
		front = (front + 1) % length;
		visitNode(graph, index);

		tmp = graph->nodes[index].firstEdge;
		while (tmp) {
			if (graph->visits[tmp->index] == 0) {
				queue[rear] = tmp->index;
				rear = (rear + 1) % length;
				graph->visits[tmp->index] = 1;
			}
			tmp = tmp->next;
		}
	}

}






void releaseAdjacencyList(Graph* graph)
{
	if (graph) {
		if (graph->nodes) {
			free(graph->nodes);
		}
		free(graph);
	}
}
