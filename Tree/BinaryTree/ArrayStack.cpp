#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

ArrayStaack* createArrayStack()
{
	ArrayStaack* stack = (ArrayStaack*)malloc(sizeof(ArrayStaack));
	stack->length = MaxStackSize;   //ÂúµÝ¼õÕ»
	stack->capacity = MaxStackSize;
	return stack;
}

void pushArrayStack(ArrayStaack* stack, Element e)
{
	if (--stack->length < 0) {
		printf("add fail!\n");
		return;
	}
	stack->data[stack->length] = e;
}

Element getArrayStack(ArrayStaack* stack)
{
	if (stack->length >= stack->capacity) {
		printf("get null\n");
	}
	return stack->data[stack->length];

}

//int popArrayStack(ArrayStaack* stack)
//{
//	if (stack->length >= stack->capacity) {
//		printf("null");
//		return -1;
//	}
//	++stack->length;
//	return 0;
//}




int popArrayStack(ArrayStaack* stack, Element* e)
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
	if (stack) free(stack);
}
