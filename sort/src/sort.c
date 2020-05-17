#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "queue.h"

#define STACK_LEN 100

void Swap(int* str, int begin, int end) {
	int temp = str[begin];
	str[begin] = str[end];
	str[end] = temp;
}

//插入排序实现
void InsertSort(int* str, int len) {
	if(str == NULL)	
		return;
	int i = 1;
	int found = 0;
	int temp;	
	while(i <= len) {
		if(str[i] < str[i-1]){
			temp = str[i];
			found = i - 1;
			while(str[found] >= temp) {
				str[found + 1] = str[found];
				found--;
			}
			str[found + 1] = temp;
		}
		i++;
	}
}

//选择排序
void SelectSort(int* str, int len) {
	if(str == NULL || len == 0)
		return; 
	int locate, temp, find; 
	for(locate = 0; locate < len; locate++) {
		temp = locate;
		for(find = locate + 1; find <= len; find++) 
			if(str[find] < str[temp]) 
				temp = find; 
		Swap(str, temp, locate);
	}
}

//希尔排序
void ShellSort(int* str, int len) {
	if(str == NULL || len == 0)
		return; 
	int skip = len;
	int  i, j;
	while(skip > 1) { 
		skip = (skip + 1) / 2;
		i = 0;
		j = i + skip;
		for(; j <= len; i++, j++) 
			if(str[i] > str[j]) 
				Swap(str, i, j);
	}
}

//Bubble sort with flag
void BuddleSort(int* str, int len) {
	if(str == NULL || len == 0)
		return;
	int i, j, flag;
	for(i = 0; i <= len; i++) {
		flag = 0;
		for(j = 0; j <= len - i -1; j++) 
			if(str[j] > str[j + 1]) {
				Swap(str, j, j + 1);
				flag = 1;
			}
		if(flag == 0)
			break;
	}
} 

//make the arthritic more effictive 
int GetMidValue(int* str, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	if(str[begin] > str[end]) {
		if(str[mid] > str[begin])
			return begin;
		else {
			if(str[mid] < str[end])
				return end;
			else 
				return mid;
		}
		
	}
	else {
		if(str[mid] > str[end])
			return end;
		else {	
			if(str[mid] < str[begin])
				return begin;
			else 
				return mid;
		}
	}
}

//FastSort ways;
int partion(int* str, int begin, int end) {
	int left = begin;
	int right = end;
	int mid = GetMidValue(str, begin, end);
	Swap(str, begin, mid);
	int key = str[begin];
	while(left < right) {
		while(key <= str[right] && left < right)
			right--;
		while(key >= str[left] && left< right)
			left++; 
		Swap(str, left, right);
	}
	Swap(str, left, begin);
	return left;
}

//FastSort ways1;
int partion1(int* str, int begin, int end) {
	if(str == NULL )
		return -1;
	int mid = GetMidValue(str, begin, end);
	Swap(str, begin, mid);
	int key = str[begin];
	int left = begin;
	int right = end;
	while(left < right) {
		while(str[right] > key && left < right)
			right--;
		if(str[right] <= key)
			Swap(str, left, right);
		while(str[left] <= key && left < right)
			left++;
		if(str[right] > key)
			Swap(str, left, right);
	}
	return left;
}

int partion3(int* str, int begin, int end) {
	if(str == NULL || begin >= end)
		return -1;
	int mid = GetMidValue(str, begin, end);
	Swap(str, begin, mid);
	int key = str[begin];
	int start = begin;
	int fast = begin + 1;
	while(fast <= end) {
		if(str[fast] <= key && ++start != fast)
			Swap(str, start, fast);
		fast++;
	}
	Swap(str, begin, start);
	return start;
}

//FastSort by R
void FastSort(int* str, int begin, int end) {
	if(str == NULL || begin >= end)
		return;
	int keyPos = partion3(str, begin, end);
	FastSort(str, begin, keyPos - 1);
	FastSort(str, keyPos + 1, end);
}

//FastSort without R finished by stack;
void FastSortNr(int* str, int begin, int end) {
	if(str == NULL)
		return;
	Stack st;
	StackInit(&st, STACK_LEN);
	StackPush(&st, end);
	StackPush(&st, begin);
	int keyPos, left, right;
	while(IsEmpty(&st) != 1) {
	    left = StackTop(&st);
	    StackPop(&st);
	    right = StackTop(&st);
	    StackPop(&st);
	    keyPos = partion3(str, left, right);
	    if(keyPos != -1) {
	        StackPush(&st, right);
	        StackPush(&st, keyPos + 1);
	        StackPush(&st, keyPos - 1);
	        StackPush(&st, left);
	    }
	}
}

//FastSort without R finished by stack;
void FastSortNr_1(int* str, int begin, int end) {
	if(str == NULL)
		return;
	Queue q;
	QueueInit(&q);
	int left, right, keyPos;
	QueuePush(&q, begin);
	QueuePush(&q, end);
	while(IsEmptyQueue(&q) != 1) {
		left = QueueFront(&q);
		QueuePop(&q);
		right = QueueFront(&q);
		QueuePop(&q);
		keyPos = partion3(str, left, right);
		if(keyPos != -1) {
			QueuePush(&q, left);
			QueuePush(&q, keyPos - 1);
			QueuePush(&q, keyPos + 1);
			QueuePush(&q, right);
		}
	}
}

//HeapSort
//归并排序
void Megrge(int* str, int begin, int mid, int end, int* temp) {
	if(str == NULL)
		return;
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1; 
	int end2 = end;
	int idx = begin;
	while(begin1 <= end1 && begin2 <= end2) {
		if(str[begin1] <= str[begin2])
			temp[idx++] = str[begin1++];
		else 
			temp[idx++] = str[begin2++];
	}
	if(begin1 <= end1) 
		memcpy(temp + idx, str + begin1, (end1 - begin1 + 1) * sizeof(int));
	if(begin2 <= end2)
		memcpy(temp + idx, str + begin2, (end2 - begin2 + 1) * sizeof(int));
	memcpy(str + begin, temp + begin, sizeof(int) * (end - begin + 1));
}

void MegrgeSort(int* str, int begin, int end, int* temp) {
	if(str == NULL)
		return;
	if(begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	MegrgeSort(str, begin, mid, temp);
	MegrgeSort(str, mid + 1, end, temp);
	Megrge(str, begin, mid, end, temp);
}

void MegSortR(int* str, int begin, int end) {
	if(str == NULL)
		return;
	int* temp = (int*)malloc(sizeof(int) * (end - begin + 1));
	MegrgeSort(str, begin, end, temp);
	free(temp);
}

//采用非递归实现归并排序函数
void MegrgeSortNr(int*str, int begin, int end) {
	if(str == NULL)
		return;
	int* temp = (int*)malloc(sizeof(int) * (end - begin + 1));
	int k = 1;
	int n = end + 1;
	int i;
	while(k < n) {
		for(i = 0; i < n; i += 2 * k) {
			int start = i;
			int mid = i + k - 1;
			if(mid >= n - 1)
				continue;
			int last = i + 2 * k - 1;
			if(last >= n) 
				last = n - 1;
			Megrge(str, start, mid, last, temp);
		}
		k *= 2;
	}
}



void printStr(int* str, int len) {
	int i;
	for(i = 0; i <= len; i++) 
		printf("%d ", str[i]);
	printf("\n");
}

int main() {
	int str[] = {9,8,7,7,6,4,3,2,1,0};
	int len = sizeof(str) / sizeof(str[0]) - 1;
	MegrgeSortNr(str, 0, len);
	printStr(str, len);
	return 0;
}
