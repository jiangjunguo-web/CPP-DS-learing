#include <stdio.h>
#include <stdlib.h>

void Swap1(int*str, int op1, int op2) {
	str[op1] ^= str[op2];
	str[op2] ^= str[op1];
	str[op1] ^= str[op2];

}
void sort1(int* str, int n) {
	if(str == NULL || n <= 1)
		return;
	int* te;
	int key;
	while(n-- > 1) {
		int* temp = str;
		te = ++str;
		key = *te;
		while(key < *temp) {
			*te = *temp;
			temp--;
			te--;
		}
		*te = key;
	}
}

void sort2(int* str, int n) {
	if(str == NULL || n <= 1)
		return;
	int skip = n;
	int* begin;
	int* end;
	int key;
	while(skip > 1) {
		skip = (skip + 1) / 2;
		begin = str;
		int i = 0;
		while(i++ < n-skip) {
			end = begin + skip;
			key = *end;
			if(key < *begin) {
				*end = *begin;
				*begin = key;
			}
			begin++;
		}
	}
}

void Swap(int* change1, int* change2) {
	*change1 ^= *change2;
	*change2 ^= *change1;
	*change1 ^= *change2;
}

void sort3(int* str, int n) {
	if(str == NULL || n <= 1)
		return;
	int *begin, *end, *temp;
	end = str + n -1;
	while(n--) {
		for(begin = str, temp = str; begin < end; begin++) 
			if(*begin > *temp) 
				temp = begin;
		if(*temp > *end)
			Swap(temp,end);
		temp = str;
		end--;
	}
}

void sort4(int* str, int n) {
	if(str == NULL || n <= 1)
		return;
	int *begin, *end, *max, *min, *temp;
	min = str;
	max = str + n - 1;
	while(min < max) {
		for(end = temp = begin = min; begin <= max; begin++) {
			if(*begin >= *temp) 
				temp = begin;
			if(*begin < *end) 
				end = begin;
		}
		if(*min > *end)
			Swap(min, end);
		if(*max < *temp)
			Swap(max, temp);
		end = ++min;
		temp = --max;
	}

}

void sort5(int* str, int len) {
	if(str == NULL || len <= 0)
		return;
	int i = 0;
	int j;
	int* begin, *end;
	begin = str;
	while(i < len) {
		begin = str, j = 0, end = begin + 1;
		while(j++ < len - i - 1) {
			if(*begin > *end) 
				Swap(begin,end);
			end++,begin++;
		}
		i++;
	}
}

void sort6(int* str, int len) {
	if(str == NULL || len <= 0)
		return;
	int i, j;
	int temp;
	int flag = 1;
	for(i = 0; i < len; i++) {
		flag = 1;
		for(j = 0; j < len - i - 1; j++) {
			if(str[j] > str[j + 1]) {
				flag = 0;
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			
		}
		if(flag == 1)
			break;
	}
}

//递归实现快速排序
void sort7(int* str, int begin, int end) {
	if(str == NULL || begin < 0 || end < 0)
		return;
	if(begin >= end)
		return;
	int left = begin;
	int right = end;
	int temp = str[begin];
	while(left < right) {
		while(left < right && temp <= str[right])	
			right--;
		str[left] = str[right];
		while(left < right && temp >= str[left])
			left++;
		str[right] = str[left];
	}
	str[left] = temp;
	sort7(str, begin, left - 1);
	sort7(str, left + 1, end);
}

int parton(int*str, int begin, int end) {
	if(str == NULL)
		return;
	int start = begin;
	int key = str[begin];
	while(begin < end) {
		while(begin < end && key <= str[end]) 
			end--;
		while(begin < end && key >= str[begin])
			begin++;
	//交换begin end 位置的值
	}
	//交换start begin位置的值
	return begin;
}

//use point to come ture the fast sort;
void sort8(int*str, int begin, int end) {
	if(str == NULL)
		return;
	if(begin >= end)
		return;
	int start = begin + 1;
	int prev = begin;
	int temp = str[begin];
	while(start <= end) {
		while(str[start] >= temp)
			start++;
		if(++prev != start)
			Swap1(str, prev, start);
		start++;
	}
	Swap1(str, begin, prev);
	sort8(str, begin, prev-1);
	sort8(str, prev+1, end);
}

void print(int* str, int m) {
	int i;
	for(i = 0; i < m; i++) 
		printf("%d ", *str++);
}

int main() {
	int str[] = {9, 1, 7, 6, 5, 4, 9, 7, 1};
	int len = sizeof(str) / sizeof(str[0]);
	sort8(str, 0, len - 1);
	print(str, len);

}
