#ifndef __MatrixGraph__
#define __MatrixGraph__

#define MaxGraphSize 20
#define INF 100000
typedef struct {
	char show;
	int index;
}matrixNode;

typedef int marixEdge;

typedef struct {
	matrixNode vex[MaxGraphSize];
	marixEdge edge[MaxGraphSize][MaxGraphSize];
	int nodeNum;
	int edgeNum;
	int directed;
}Graph;

void initMatrixGraph(Graph* graph,char *names,int num,marixEdge initEdge,int directed);
int addGraphEdge(Graph* graph, int a, int b, marixEdge weight);
void DFSMatrixGraph(Graph* graph,int pos);
void DFSMatrixGraph_NoSecur(Graph* graph, int pos);
void BFSMatrixGraph(Graph* graph, int pos);

void releaseMatrixGraph(Graph* graph);
#endif