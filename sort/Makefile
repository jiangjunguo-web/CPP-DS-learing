# $@ : 表示着目标
# $^ : 表示所有的依赖
# $< : means the first depended file

#无论是否是最新文件,都执行一遍
.PHONY : clean main

CC = gcc

# 产生当前路径,保存到BASEDIR变量中
BASEDIR =$(shell pwd)

# 筛选出pwd/src/ 目录下所有的.c文件, 保存到变量SRCS中
SRCS = $(wildcard $(BASEDIR)/src/*.c)

# 将保存到变量中的.c文件前面的目录信息删去
SRCS := $(notdir $(SRCS))

# 创建pwd/obj 目录
OBJDIR = $(BASEDIR)/obj
$(shell mkdir -p $(OBJDIR))

# 将SRCS变量中的.c 全部变成.o文件. 存在变量OBJS
OBJS = $(SRCS:.c=.o)
# 将OBJS变量中的.o 文件加上目录信息
OBJS:= $(addprefix $(OBJDIR)/, $(OBJS)) 

# 目标main 
main : $(OBJS)
	$(CC) -o $@ $^
$(OBJDIR)/%.o : $(BASEDIR)/src/%.c
	$(CC) -c -g  $< -o  $@ -I ./include
clean : 
	rm -rf $(OBJS)
