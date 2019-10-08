#ifndef FUNCTION_H
#define FUNCTION_H

#include "queue.h"
#include <Windows.h>

Status InitQueue(SqQueue &q);//构造一个空队列q
int QueueLength(SqQueue q);//返回q的元素个数
Status EnQueue(SqQueue &q,QElemType e);//插入元素e为q的新队尾元素
Status DeQueue(SqQueue &q,QElemType &e);//若队列不空，则删除q的队头元素，用e返回其值，并返回OK
Status judgeNum(string exp);//判断是否回文
void print();

Status InitQueue(SqQueue &q){
    q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!q.base){
        exit(OVERFLOW);
    }
    q.front=0;
    q.rear=0;
    return OK;
}

int QueueLength(SqQueue q){
    return (q.rear-q.front+MAXQSIZE)%MAXQSIZE;
}

Status EnQueue(SqQueue &q,QElemType e){
    if((q.rear+1)%MAXQSIZE==q.front){
        return ERROR;
    }
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &q,QElemType &e){
    if(q.front==q.rear){
        return ERROR;
    }
    e=q.base[q.front];
    q.front=(q.front+1)%MAXQSIZE;
    return OK;
}

Status judgeNum(string exp){
    SqQueue q;
    InitQueue(q);
    QElemType e;
    for(int i=0;i<exp.length();i++){
        EnQueue(q,exp[i]);
    }
    q.rear--;
    while(q.front<q.rear){
        if(q.base[q.rear--]!=q.base[q.front++]){
            return FALSE;
        }
    }
    return TRUE;
}

void print()
{
    system("cls");
    cout<<endl<<"\t\t\t\t\t这是一个高端大气上档次的范茂伟的菜单图"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------|"<<endl;
    cout<<"\t\t\t\t\t|              1.压入队列             |"<<endl;
    cout<<"\t\t\t\t\t|              2.弹出队列             |"<<endl;
    cout<<"\t\t\t\t\t|              3.显示队长             |"<<endl;
    cout<<"\t\t\t\t\t|              4.回文判定             |"<<endl;
    cout<<"\t\t\t\t\t|              0.退出                 |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t请输入相关指令:";
}

#endif // FUNCTION_H
