#include "queue.h"
#include <stdlib.h>

QNode* CreatNode(QData x) {
	QNode* cur = (QNode*)malloc(sizeof(QNode));
	cur->val = x;
	cur->next = NULL;
	return cur;
}
void QueueInit(Queue* q) {
	if(q == NULL)
		return;
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

int IsEmptyQueue(Queue* q) {
	if(q == NULL)
		return;
	return (q->size == 0) ? 1 : 0;
}

QData QueueFront(Queue* q) {
	if(q == NULL)
		return;
	return q->front->val;
}
//考虑空队
void QueuePush(Queue* q, QData x) {
	if(q == NULL)
		return;
	QNode* cur = CreatNode(x);
	if(q->front == NULL) {
		q->front=q->rear = cur;	
	}
	else {
		q->rear->next = cur;
		q->rear = q->rear->next;
	}
	q->size++;
}

void QueuePop(Queue* q) {
	if(q == NULL)
		return;
	if(q->front) {
		QNode* cur = q->front->next;
		free(q->front);
		q->front = cur;
		cur = NULL;
		if(q->front == NULL)
			q->rear = NULL;
		--q->size;
	}
}

