#pragma once
#include "head.h"
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;  //左右孩子指针
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T);   //构建二叉树T
void PreOrderTraverse(BiTree T);          //二叉树先序遍历
void InOrderTraverse(BiTree T);         //二叉树中序遍历
void PostOrderTraverse(BiTree T);         //二叉树后序遍历
void LevelOrderTraverse(BiTree T);         //二叉树层次遍历
int tree_depth(BiTree T);               //求二叉树T的深度
int count_n(BiTree T);                   //求二叉树的结点总数
int CountSingle(BiTree T);            //求二叉树单分支节点的数目