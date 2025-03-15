#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkQueue.h"

LinkQueue* createLinkQueue()
{
	LinkQueue* queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	queue->num = 0;
	queue->front = queue->rear = NULL;
	return queue;
}

void pushLinkQueue(LinkQueue* queue, Element e)
{
	link_node* new_node = (link_node*)malloc(sizeof(link_node));
	new_node->data = e;
	new_node->next = NULL;

	if (queue->front == NULL) {
		queue->front = new_node;
	}
	else {
		queue->rear->next = new_node;
	}
	queue->rear = new_node;
	queue->num++;
}

int popLinkQueue(LinkQueue* queue, Element* e)
{
	if (queue->front == NULL) {
		printf("queue is empty\n");
		return -1;
	}
	*e = queue->front->data;
	link_node* tmp = queue->front;
	queue->front = tmp->next;
	queue->num--;
	return 0;
}

void releaseLinkQueue(LinkQueue* queue)
{
	if (queue) {
		link_node* tmp;
		while (queue->front) {
			tmp = queue->front;
			queue->front = tmp;
			free(tmp);
			queue->num--;
		}
		printf("\nqueue num is %d\n", queue->num);
		free(queue);
	}
}





