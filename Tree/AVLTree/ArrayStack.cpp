#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayStack.h"

ArrayStaack* createArrayStack(int n)
{
	ArrayStaack* stack = (ArrayStaack*)malloc(sizeof(ArrayStaack));
	if (stack == NULL) {
		free(stack);
		printf("stack malloc fail\n");
	}
	stack->data = (Ele*)malloc(sizeof(Ele) * n);
	memset(stack->data, NULL, sizeof(Ele) * n);
	if (stack->data == NULL)
		printf("stack->data is NULL\n");
	stack->length = n;   //ÂúµÝ¼õÕ»
	stack->capacity = n;
	return stack;
}


void pushArrayStack(ArrayStaack* stack, Ele e)
{
	if (--stack->length < 0) {
		int new_capacity = stack->capacity * 2;
		int Old_capacity = stack->capacity;
		Ele* new_Data = (Ele*)realloc(stack->data, sizeof(Ele) * new_capacity);
		if (new_Data == NULL) {
			printf("new_Data realloc fail\n");
			return;
		}
		for (int i = 0;i < Old_capacity;++i) {
			new_Data[new_capacity - Old_capacity + i] = new_Data[i];
		}
		stack->data = new_Data;
		stack->capacity = new_capacity;
		stack->length = new_capacity - Old_capacity - 1;
	}
	stack->data[stack->length] = e;
}

Ele getArrayStack(ArrayStaack* stack)
{
	if (stack->length >= stack->capacity) {
		printf("get null\n");
	}
	return stack->data[stack->length];

}





int popArrayStack(ArrayStaack* stack, Ele* e)
{
	if (stack->length >= stack->capacity) {
		printf("pop null");
		return -1;
	}
	*e = stack->data[stack->length++];
	return 0;
}

void showArrrayStack(ArrayStaack* stack)
{
	if (stack->length >= stack->capacity) {
		printf("show null");
		return;
	}
	while (stack->length < stack->capacity) {
		printf("%d\t", stack->data[stack->length++]);
	}
	printf("\nstack_length: %d", stack->length);
}

void releaseArrayStack(ArrayStaack* stack)
{
	if (stack) {
		if (stack->data) {
			free(stack->data);
		}
		free(stack);
	}
}
