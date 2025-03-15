#ifndef __ArrayQueue__
#define __ArrayQueue__

typedef int Element;
#define MaxQueueSize 14

typedef struct {
	Element data[MaxQueueSize];
	int front;
	int rear;
}ArrayQueue;

ArrayQueue* createArrayQueue();
int pushArrayQueue(ArrayQueue* queue, Element e);
int popArrayQueue(ArrayQueue* queue, Element* e);
void showArrayQueue(ArrayQueue* queue);
void releaseArrayQueue(ArrayQueue* queue);



#endif
