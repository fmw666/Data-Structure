#pragma once
#include "struct.h"

void insert(BiTree &T,TElemType x)
{
    if (T == NULL) {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = x;
        T->lchild = T->rchild = NULL;
    }
    else {
        if (x <= T->data)
            insert(T->lchild, x);
        else
            insert(T->rchild, x);
    }
}

void CreateBiTree(BiTree &T)  //构建二叉树T
{
    TElemType x;
    T = NULL;
    cin >> x;
    while (x != 0) {
        insert(T, x);
        cin >> x;
    }
}

void PreOrderTraverse(BiTree T)          //二叉树先序遍历
{
    if (T) {
        cout << T->data << " ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T)         //二叉树中序遍历
{
    if (T) {
        PreOrderTraverse(T->lchild);
        cout << T->data << " ";
        PreOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T)         //二叉树后序遍历
{
    if (T) {
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
        cout << T->data << " ";
    }
}

void LevelOrderTraverse(BiTree T)        //二叉树层次遍历
{
}

int tree_depth(BiTree T)               //求二叉树T的深度
{
    int lh,rh,h;
    if (!T)
        h = 0;
    else {
        lh = tree_depth(T->lchild);
        rh = tree_depth(T->rchild);
        if (lh >= rh)
            h = lh + 1;
        else
            h = rh + 1;
    }
    return h;
}

int count_n(BiTree T)                   //求二叉树的结点总数
{
    int num, num1, num2;
    if (!T)
        num = 0;
    else {
        num1 = count_n(T->lchild);
        num2 = count_n(T->rchild);
        num = num1 + num2 + 1;
    }
    return num;
}

int CountSingle(BiTree T)            //求二叉树单分支节点的数目
{
    int num, num1, num2;
    if ((!T) || (!T->lchild) && (!T->rchild))
        num = 0;
    else {
        num1 = CountSingle(T->lchild);
        num2 = CountSingle(T->rchild);
        if (!T->lchild)
            num = num2 + 1;
        else if (!T->rchild)
            num = num1 + 1;
        else
            num = num1 + num2;
    }
    return num;
}
