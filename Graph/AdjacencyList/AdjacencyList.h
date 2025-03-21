#ifndef __AdjacencyList__
#define __AdjacencyList__

typedef int Element;
#define Max_adjacencyList_Size 20
typedef struct adjacencyEdge{
	int index;
	Element weight;
	struct adjacencyEdge* next;
}arcEdge;

typedef struct {
	int index;
	char data;
	arcEdge* firstEdge;
}arcNode;

typedef struct {
	arcNode* nodes;
	int* visits;
	int EdgeNum;
	int NodeNum;
	int directed;
}Graph;

Graph* createAdjacencyList(char* datas, int n, int directed);
int addArcNode(Graph* graph, int a, int b, Element weight);
void DFS_AdjacencyList(Graph* graph,int pos);
void DFS_AdjacencyList_NoSecur(Graph* graph, int pos);
void BFS_AdjacencyList_NoSecur(Graph* graph, int pos);
void releaseAdjacencyList(Graph* graph);




#endif