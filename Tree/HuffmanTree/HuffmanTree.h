#ifndef __HuffmanTree__
#define __HuffmanTree__

typedef struct {
	int weight;
	int parent;
	int lChild;
	int rChild;
}HuffmanNode,* HuffmanTree;

HuffmanTree createHuffmanTree(int* weight, int n);
char** createHuffmanNode(HuffmanTree tree, int n);
void releaseHuffmanTree(HuffmanTree tree);
#endif