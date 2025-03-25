#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MatrixGraph.h"

void initMatrixGraph(Graph* graph, char* names, int num, marixEdge initEdge, int directed)
{
	graph->directed = directed;
	graph->edgeNum = 0;
	graph->nodeNum = num;
	for (int i = 0;i < num;++i) {
		graph->vex[i].index = i;
		graph->vex[i].show = names[i];
		for (int j = 0;j < num;++j) {
			graph->edge[i][j] = initEdge;
		}
	}


}
static int isEdge(marixEdge weight) {
	if (weight > 0 && weight < INF) {
		return 1;
	}
	return 0;
}

int addGraphEdge(Graph* graph, int a, int b, marixEdge weight)
{
	if (a == b) return 0;
	if (a < 0 || a >= graph->nodeNum) {
		return 0;
	}
	if (b < 0 || b >= graph->nodeNum) {
		return 0;
	}
	if (isEdge(graph->edge[a][b])) {
		return 0;
	}
	graph->edge[a][b] = weight;
	if (graph->directed == 0) {
		graph->edge[b][a] = weight;
	}
	graph->edgeNum++;

	return 1;
}

static void visitGraphNode(Graph* graph, int pos) {
	if (pos < 0 || pos >= graph->edgeNum) return;
	printf("%c\t", graph->vex[pos]);
}

static int MatrixVisited[MaxGraphSize] = { 0 };



void DFSMatrixGraph(Graph* graph,int pos)
{
	visitGraphNode(graph, pos);
	MatrixVisited[pos] = 1;
	for (int i = 0;i < graph->nodeNum;++i) {
		if (isEdge(graph->edge[pos][i]) && MatrixVisited[i] == 0) {
			DFSMatrixGraph(graph, i);
		}
	}
}

void DFSMatrixGraph_NoSecur(Graph* graph, int pos)
{
	memset(MatrixVisited, 0, sizeof(int) * MaxGraphSize);
	int* stack = (int*)malloc(sizeof(int) * graph->nodeNum);
	memset(stack, 0, sizeof(int) * graph->nodeNum);
	int top = -1;
	stack[++top] = pos;
	MatrixVisited[pos] = 1;
	while (top >= 0) {
		pos = stack[top--];
		visitGraphNode(graph, pos);
		for (int i = 0;i < graph->nodeNum;++i) {
			if (isEdge(graph->edge[pos][i]) && MatrixVisited[i] == 0) {
				stack[++top] = i;
				MatrixVisited[i] = 1;
			}
		}
	}
}

void BFSMatrixGraph(Graph* graph, int pos) {
	memset(MatrixVisited, 0, sizeof(int) * MaxGraphSize);
	int length = graph->edgeNum + 1;
	int* queue = (int*)malloc(sizeof(int) * length);
	memset(queue, 0, sizeof(int) * length);
	int front = 0, rear = 0;
	queue[rear] = pos;
	rear = (rear + 1) % length;
	MatrixVisited[pos] = 1;
	while (front != rear) {
		pos = queue[front];
		visitGraphNode(graph,pos);
		front = (front + 1) % length;
		for (int i = 0;i < graph->nodeNum;++i) {
			if (isEdge(graph->edge[pos][i]) && MatrixVisited[i] == 0) {
				queue[rear] = i;
				MatrixVisited[i] = 1;
				rear = (rear + 1) % length;
			}
		}
	}
}

void releaseMatrixGraph(Graph* graph)
{
	if (graph) free(graph);
}
