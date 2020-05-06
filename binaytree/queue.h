#include "bintree.h"

#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef BTNode* QData;

typedef struct QNode {
	struct QNode* next;
	QData val;
}QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
	int size;
}Queue;

QNode* CreatNode(QData x);
void QueueInit(Queue* q);

int IsEmptyQueue(Queue* q);

QData QueueFront(Queue* q);

void QueuePush(Queue* q, QData x);

void QueuePop(Queue* q);

#endif
