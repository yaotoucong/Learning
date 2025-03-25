#ifndef __Kruskal__
#define __Kruskal__
#include "MatrixGraph.h"

typedef struct {
	int begin;
	int weight;
	int end;
}EdgeSet;

EdgeSet* initEdgeSet(Graph* graph);
void sortEdgeSet(EdgeSet* set,int n);
int Kruskal_MGraph(Graph* graph, EdgeSet* set,int n, EdgeSet* result);







#endif