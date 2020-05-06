#include "bintree.h"
#ifndef __STACK_H__
#define __STACK_H__

//定义一个栈
typedef BTNode* StackData;
typedef struct stack {
	StackData* str;
	int size;
	int capatity;
}Stack;

void StackInit(Stack* st, int size);

int IsEmpty(Stack* st);

void StackPop(Stack* st);

StackData StackTop(Stack* st);

void StackPush(Stack* st, StackData x);

#endif
