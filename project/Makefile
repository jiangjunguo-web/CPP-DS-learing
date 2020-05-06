#我的第一个makefile
#$@ ：目标
#$^ : 所有依赖文件
#$< : 第一个依赖文件
# .PHONY后面写的目标无论是否是最新的，都强制执行

.PHONY: clean main
CC = gcc

#wildcard 通配函数 使用后得到main.c add.c sub.c mul.c parse.c
BASEDIR = $(shell pwd)
OBJDIR = $(BASEDIR)/obj
SRCDIR = $(BASEDIR)/src
INCLUDEDIR = $(BASEDIR)/include
$(shell mkdir -p $(OBJDIR) $(SRCDIR) $(INCLUDEDOR))
$(shell mv *.c $(SRCDIR)/)
$(shell mv *.h $(INCLUDEDIR)/)
SRCS=$(wildcard *.c $(SRCDIR)/*.c)
SRCS:=$(notdir $(SRCS))
OBJS = $(SRCS:.c=.o)    #将SRCS得到的.c 换成.o
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))
main : $(OBJS)
	$(CC) -o $@ $^ 

# %通配符类似于系统中的*
$(OBJDIR)/%.o :%.c
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJS)

