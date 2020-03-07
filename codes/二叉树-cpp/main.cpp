#include "func.h"

int main()
{
    BiTree T;
    cout << "请输入一个二叉树（0为结束标志）：";
    CreateBiTree(T);
    cout << "先序遍历：";
    PreOrderTraverse(T);
    cout << endl << "中序遍历：";
    InOrderTraverse(T);
    cout << endl << "后序遍历：";
    PostOrderTraverse(T);
    cout << endl << "二叉树深度：" << tree_depth(T) << endl;
    cout << "二叉树结点数：" << count_n(T) << endl;
    cout << "二叉树单分支结点数：" << CountSingle(T) << endl;
    system("pause");
    return 0;
}