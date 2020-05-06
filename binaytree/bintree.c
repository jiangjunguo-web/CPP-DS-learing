#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "stack.h"
#include "queue.h"

 //通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
 BTNode* BinaryTreeCreate(BData* a, int* p) {
	if(a[*p] != '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->val = a[*p];
		(*p)++;
		root->left = BinaryTreeCreate(a, p);
		(*p)++;
		root->right = BinaryTreeCreate(a, p);
		return root;
	}
	else 
		return NULL;
}

 void TreePrevOrderR(BTNode* root) {
	if(root == NULL)
		return;
	printf("%c ", root->val);
	TreePrevOrderR(root->left);
	TreePrevOrderR(root->right);
}
 // 二叉树销毁
 void BinaryTreeDestory(BTNode** root) {
	BTNode* cur = *root;
	if(cur) {
		BinaryTreeDestory(&cur->left);
		BinaryTreeDestory(&cur->right);
		free(cur);
		*root = NULL; 
	}
}

 // 二叉树节点个数
 int BinaryTreeSize(BTNode* root) {
	if(root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
 // 二叉树叶子节点个数
 int BinaryTreeLeafSize(BTNode* root) {
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 1;
	return	BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
 // 二叉树第k层节点个数
 int BinaryTreeLevelKSize(BTNode* root, int k) {
	if(root == NULL)
		return 0;
	if(k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
 // 二叉树查找值为x的节点
 BTNode* BinaryTreeFind(BTNode* root, BData x) {
	if(root == NULL)
		return NULL;
	if(root->val == x)
		return root;
	BTNode* temp;
	temp = BinaryTreeFind(root->left, x);
	if(temp == NULL)
		temp = BinaryTreeFind(root->right, x);
	return temp;
}
 // 二叉树前序遍历 
 void BinaryTreePrevOrder(BTNode* root) {	
	if(root == NULL)	
		return;
	Stack st;
	StackInit(&st, 10);
	BTNode* cur = root;
	while(cur || (IsEmpty(&st) != 1)) {
		while(cur) {
			printf("%c ", cur->val);
			StackPush(&st, cur);
			cur = cur->left;
		}
		cur = StackTop(&st);
		StackPop(&st);
		cur = cur->right;
	}
	printf("\n");
}

 // 二叉树中序遍历
 void BinaryTreeInOrder(BTNode* root) {
	BTNode* cur = root;
	Stack st;
	StackInit(&st, 10);
	BTNode* top;
	while(cur || (IsEmpty(&st) != 1)) {
		while(cur) {
			StackPush(&st, cur);
			cur = cur->left;
		}
		top = StackTop(&st);
		StackPop(&st);
		printf("%c ", top->val);
		cur = top->right;
	}
	printf("\n");
}
 // 二叉树后序遍历
 void BinaryTreePostOrder(BTNode* root) {
	if(root == NULL)
		return;
	
	BTNode* cur = root;
	Stack st;
	StackInit(&st, 100);
	BTNode* prev = NULL;
	BTNode* top;
	while(cur || (IsEmpty(&st) != 1)) {
		while(cur) {
			StackPush(&st, cur);
			cur = cur->left;
		}
		top = StackTop(&st);
		if(top->right == NULL || top->right == prev) {
			printf("%c ", top->val);
			StackPop(&st);
			prev = top;
		} 
		else {
			cur = top->right;
		}
	}
	printf("\n");
}
 // 层序遍历
 void BinaryTreeLevelOrder(BTNode* root) {
	if(root == NULL)
		return;
	Queue q;
	QueueInit(&q);
	if(root)
		QueuePush(&q, root);
	BTNode* front;
	while(IsEmptyQueue(&q) != 1) {
		front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->val);
		if(front->left)
			QueuePush(&q, front->left);
		if(front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");
}
 // 判断二叉树是否是完全二叉树
 int BinaryTreeComplete(BTNode* root) {
	if(root == NULL)
		return 1;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	BTNode* top;
	while(IsEmptyQueue(&q) != 1) {
		top = QueueFront(&q);
		QueuePop(&q);
		if(top) {
			QueuePush(&q, top->left);
			QueuePush(&q, top->right);
		}
		else 
			break;
	}
	QueuePop(&q);
	while(IsEmptyQueue(&q) != 1) {
		top = QueueFront(&q);
		if(top != NULL)
			return 0;
		QueuePop(&q);
	}
	return 1;
}

int main() {
	BData a[] = {"ABD##E##CF##G##"};
	int p = 0;
	BTNode* root = BinaryTreeCreate(a, &p);
	printf("%d \n", BinaryTreeComplete(root));

	BinaryTreeDestory(&root);
	BinaryTreeInOrder(root);
	BinaryTreePostOrder(root);
}
