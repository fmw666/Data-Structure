#ifndef FUNCTION_H
#define FUNCTION_H

#include "struct.h"
#include "head.h"
#include <iostream>

void Creat(LinkList &L,int n);
Status Show(LinkList L);
Status Search(LinkList L);
Status Insert(LinkList &L,int i,ElemType e);
Status Delete(LinkList &L);
void Destory(LinkList& L);
void Print();

void Creat(LinkList &L){
    int n;
    cout<<endl<<"\t\t\t\t\t范茂伟：请问您想创建多少个数?"<<endl;
    cout<<"\t\t\t\t\t你：";
    cin>>n;
    cout<<endl;
    L = (LinkList)malloc(sizeof(LNode));
    LinkList r=L;
    for(int i=0;i<n;i++){
        LinkList p=(LinkList)malloc(sizeof(LNode));
        cout<<"\t\t\t\t\t范茂伟：请输入第"<<i+1<<"个数:";
        cin>>(p->data);
        r->next=p;
        r=p;
    }
    r->next=NULL;
}

Status Show(LinkList L){
    if(L->next==NULL){
        cout<<endl<<"\t\t\t\t\t系统提示：空表！"<<endl<<endl;
        cout<<"\t\t\t\t\t范茂伟：请问是否现在重新构建一个表？"<<endl;
        cout<<"\t\t\t\t\t(1代表YES，0代表NO)"<<endl;
        cout<<"\t\t\t\t\t你：";
        int a;
        cin>>a;
        if(a==1){
            Creat(L);
            return OK;
        }
        else if(a==0){
            return ERROR;
        }
        else{
            cout<<endl<<"\t\t\t\t\t系统提示：错误！";
        }
        system("pause");
        return 0;
    }
    cout<<endl;
    int i=0;
    while(L->next){
        cout<<"\t\t\t\t\t范茂伟：第"<<i+1<<"个数为:"<<L->next->data<<endl;
        L=L->next;
        i++;
    }
    cout<<endl<<"\t\t\t\t\t范茂伟：一共"<<i<<"个数。"<<endl;
    cout<<endl<<endl<<"\t\t\t\t\t";
    system("pause");
}

Status Search(LinkList L){
    cout<<endl<<"\t\t\t\t\t请输入你要查找的数：";
    ElemType e;
    cin>>e;
    cout<<endl;
    LinkList p = L->next;
    int i=1;
    while (p){
        if(p->data==e){
            cout<<"\t\t\t\t\t范茂伟："<<e<<"这个数在第"<<i<<"这个位置"<<endl;
            cout<<endl<<"\t\t\t\t\t";
            system("pause");
            return OK;
        }
        p = p->next;
        i++;

    }
    cout<<"\t\t\t\t\t范茂伟：未找到这个数"<<endl;
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    return ERROR;
}

Status Insert(LinkList &L,int i,ElemType e){
    LinkList p=L;
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        ++j;
    }
    cout<<endl;
    if(!p||j>i-1){
        cout<<"\t\t\t\t\t序号越界，无效！"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    cout<<"\t\t\t\t\t系统提示：插入成功！"<<endl;
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    return ERROR;
    return OK;

}

Status Delete(LinkList &L){
    if(L->next==NULL){
        cout<<endl<<"\t\t\t\t\t系统提示：空表！"<<endl<<endl;
        cout<<"\t\t\t\t\t范茂伟：请问是否现在重新构建一个表？"<<endl;
        cout<<"\t\t\t\t\t(1代表YES，0代表NO)"<<endl;
        cout<<"\t\t\t\t\t你：";
        int a;
        cin>>a;
        if(a==1){
            Creat(L);
            return OK;
        }
        else if(a==0){
            return ERROR;
        }
        else{
            cout<<endl<<"\t\t\t\t\t系统提示：错误！";
        }
        system("pause");
        return 0;
    }
    cout<<endl<<"\t\t\t\t\t范茂伟：请问您想删除第几个？"<<endl;
    int i;
    cout<<"\t\t\t\t\t你：";
    cin>>i;

    LinkList p=L;
    int j=0;
    while(p->next&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1){
        cout<<endl<<"\t\t\t\t\t系统提示：序号越界，无效！"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }
    LinkList q=p->next;
    cout<<endl<<"\t\t\t\t\t系统提示：第"<<i<<"个数为"<<q->data<<"，请问是否确认删除？"<<endl;
    cout<<"\t\t\t\t\t(1代表YES，0代表NO)"<<endl;
    cout<<endl<<"\t\t\t\t\t你：";
    int a;
    cin>>a;
    if(a==1){
        cout<<endl<<"\t\t\t\t\t请稍后";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        p->next=q->next;
        free(q);
        cout<<endl<<"\t\t\t\t\t系统提示：删除成功！"<<endl;
        Sleep(2000);
        cout<<"\t\t\t\t\t";
        return OK;
    }
    else if(a==0){
        cout<<endl<<"\t\t\t\t\t系统提示：正在为你返回！"<<endl;
        cout<<"\t\t\t\t\t请稍后";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        return ERROR;
    }
    else{
        cout<<endl<<"\t\t\t\t\t系统提示：序号越界，无效！"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }

}

void Destory(LinkList &L){
    L->next=NULL;
    cout<<endl<<"\t\t\t\t\t范茂伟：清空成功！即将退出。"<<endl;
    cout<<endl<<"\t\t\t\t\t请稍后";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<endl<<"\t\t\t\t\t系统提示：已退出！(回车结束)"<<endl;
    cout<<"\t\t\t\t\t";
    Sleep(2000);
}

void Print(){
    system("cls");
    cout<<endl<<"\t\t\t\t\t    这是一个高端大气上档次的范茂伟的菜单图"<<endl;
    cout<<"\t\t\t\t\t_____________________________________________"<<endl;
    cout<<"\t\t\t\t\t|                 1.显示                    |"<<endl;
    cout<<"\t\t\t\t\t|                 2.查找                    |"<<endl;
    cout<<"\t\t\t\t\t|                 3.插入                    |"<<endl;
    cout<<"\t\t\t\t\t|                 4.删除                    |"<<endl;
    cout<<"\t\t\t\t\t|                 0.清空                    |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t请输入相关指令:";
}

#endif // FUNCTION_H
