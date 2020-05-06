#include <stdio.h>

#ifndef __B_TREE__
#define __B_TREE__

typedef char BData;

typedef struct BTreeNode {
	BData val;
	struct BTreeNode* left;
	struct BTreeNode* right;	
}BTNode;

 void TreePrevOrderR(BTNode* root);
 //通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
 BTNode* BinaryTreeCreate(BData* a, int* p);
 // 二叉树销毁
 void BinaryTreeDestory(BTNode** root);
 // 二叉树节点个数
 int BinaryTreeSize(BTNode* root);
 // 二叉树叶子节点个数
 int BinaryTreeLeafSize(BTNode* root);
 // 二叉树第k层节点个数
 int BinaryTreeLevelKSize(BTNode* root, int k);
 // 二叉树查找值为x的节点
 BTNode* BinaryTreeFind(BTNode* root, BData x);
 // 二叉树前序遍历 
 void BinaryTreePrevOrder(BTNode* root);
 // 二叉树中序遍历
 void BinaryTreeInOrder(BTNode* root);
 // 二叉树后序遍历
 void BinaryTreePostOrder(BTNode* root);
 // 层序遍历
 void BinaryTreeLevelOrder(BTNode* root);
 // 判断二叉树是否是完全二叉树
 int BinaryTreeComplete(BTNode* root);


#endif
