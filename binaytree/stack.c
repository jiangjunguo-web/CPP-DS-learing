#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void StackInit(Stack* st, int size) {
	st->str = (StackData*)malloc(sizeof(StackData)*size);
	st->size = 0;
	st->capatity = size;
}

int IsEmpty(Stack* st) {
	if(st == NULL)
		return;
	if(st->size == 0)
		return 1;
	return 0;
}

void StackPop(Stack* st) {
	if(st == NULL)
		return;
	if(IsEmpty(st))
		return;
	st->size--;
}

void StackPush(Stack* st, StackData x) {
	if(st == NULL) 
		return;
	if(st->size == st->capatity) {
		st->capatity *= 2;
		st->str = (StackData*)realloc(st->str, sizeof(StackData)*st->capatity);
	}
	st->str[st->size++] = x;
}

StackData StackTop(Stack* st) {
 	return st->str[st->size - 1];
}
