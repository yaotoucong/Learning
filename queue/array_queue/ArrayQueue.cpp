#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayQueue.h"

ArrayQueue* createArrayQueue()
{
	ArrayQueue* queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	memset(queue->data, 0, sizeof(Element) * MaxQueueSize);
	queue->front = queue->rear = 0;
	return queue;
}

int pushArrayQueue(ArrayQueue* queue, Element e)
{
	if ((queue->rear + 1) % MaxQueueSize == queue->front) {
		printf("queue is filled\n");
		return -1;
	}
	queue->data[queue->rear] = e;
	queue->rear = (queue->rear + 1) % MaxQueueSize;
	return 0;
}

int popArrayQueue(ArrayQueue* queue, Element* e)
{
	if (queue->front == queue->rear) {
		printf("\nqueue is empty\n");
		return -1;
	}
	*e = queue->data[queue->front];
	queue->front = (queue->front + 1) % MaxQueueSize;
	return 0;
}

void showArrayQueue(ArrayQueue* queue)
{
	if (queue->front == queue->rear) {
		printf("\nqueue is empty\n");
		return;
	}
	while (queue->front != queue->rear) {
		printf("%d\t", queue->data[queue->front]);
		queue->front = (queue->front + 1) % MaxQueueSize;
	}
}

void releaseArrayQueue(ArrayQueue* queue)
{
	if (queue) free(queue);
}
