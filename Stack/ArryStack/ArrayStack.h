#ifndef __ArrayStack__
#define __ArrayStack__

typedef int Element;
#define MaxStackSize 20

typedef struct {
	Element data[MaxStackSize];
	int length;
	int capacity;
}ArrayStaack;

ArrayStaack* createArrayStack();
void pushArrayStack(ArrayStaack* stack, Element e);
Element getArrayStack(ArrayStaack* stack);
//int popArrayStack(ArrayStaack* stack);
void popArrayStack(ArrayStaack* stack, Element* e);
void showArrrayStack(ArrayStaack* stack);
void releaseArrayStack(ArrayStaack* stack);




#endif