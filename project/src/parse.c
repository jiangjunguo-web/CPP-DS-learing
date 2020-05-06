#include <stdio.h>
#include <stdlib.h>
#include "add.h"
#include "parse.h"
#include "sub.h"
#include "mul.h"

#define IN 1
#define OUT 0

typedef int FUNC (int, int);

FUNC* p_fun = NULL;
char op;

struct exptr_t {
	FUNC* p_fun;
	char* name;
	char op;
};


struct exptr_t eptr[] = {
	{sub, "sub", '-'},
	{add, "add", '+'},
	{mul, "mul", '*'},
	{NULL, NULL, 0}
};

void do_action(int argc, char* argv[]) {
	int left = atoi(argv[1]);
	int right = atoi(argv[2]);
	int ret = p_fun(left, right);
	printf("%s%c%s = %d\n", argv[1], op, argv[2], ret);
}

void main_math(int argc, char* argv[]) {
	int i;
	p_fun = NULL;
	for(i = 0; ; i++) {
		if(eptr[i].op == 0) {
			printf("命令不存在\n", argv[0]);
			return;
		}
		if(strcmp(eptr[i].name, argv[0]) == 0) {
			p_fun = eptr[i].p_fun;
			op = eptr[i].op;
			break;
		}
	}
	do_action(argc, argv);
}

void parse(char* buf) {
	int i;
	int argc = 0;
	char* argv[10] = {};
	int flag = OUT;
	for(i = 0; buf[i] != '\0'; i++) {
		if(flag == OUT && !isspace(buf[i])) {
			argv[argc++] = buf + i;
			flag = IN;
		}
		if(flag == IN && isspace(buf[i])) {
			buf[i] = '\0';
			flag = OUT;
		}
	}
	main_math(argc, argv);
}
