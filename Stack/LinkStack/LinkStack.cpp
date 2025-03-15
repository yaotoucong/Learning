#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

LinkStack* createLinkStack()
{
	LinkStack* stack = (LinkStack*)malloc(sizeof(LinkStack));
	stack->num = 0;
	stack->top = NULL;
	return stack;
}

void pushLinkStack(LinkStack* stack, Element e)
{
	link_node* new_node = (link_node*)malloc(sizeof(link_node));
	new_node->next = NULL;
	new_node->data = e;

	new_node->next = stack->top;
	stack->top = new_node;
	stack->num++;
}

void popLinkStack(LinkStack* stack, Element* e)
{
	if (stack->top == NULL) {
		printf("stack is empty\n");
		return;
	}
	*e = stack->top->data;
	link_node* tmp = stack->top;
	stack->top = tmp->next;
	free(tmp);
	stack->num--;

}

void showStack(LinkStack* stack) {
	link_node* p = stack->top;
	while (p) {
		printf("%d\t", p->data);
		p = p->next;
	}
}

void releaseLinkStack(LinkStack* stack)
{
	if (stack) {
		link_node* tmp;
		while (stack->top) {
			tmp = stack->top;
			stack->top = tmp->next;
			free(tmp);
			stack->num--;
		}
		printf("\nstack num is %d\n", stack->num);
	}
}



