#ifndef __Prim__
#define __Prim__
#include "MatrixGraph.h"

typedef struct {
	int begin;
	int weight;
	int end;
}EdgeSet;

void PrimMGraph(Graph* graph, EdgeSet* set,int start);







#endif