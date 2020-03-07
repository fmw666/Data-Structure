#ifndef FUNCTION_H
#define FUNCTION_H

#include "struct.h"
#include "head.h"

Status InitList(SqList& L);
void Creat(SqList &L);
Status Show(SqList L);
Status Search(SqList L);
Status Insert(SqList &L,int i,ElemType e);
Status Delete(SqList &L);
Status Ascend(SqList& L,int i);
void Destory(SqList& L);
void Print();

Status InitList(SqList& L){
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

void Creat(SqList &L){
    int n;
    cout<<endl<<"\t\t\t\t\t范茂伟：请问您想创建多少个数?"<<endl;
    cout<<"\t\t\t\t\t你：";
    cin>>n;
    if(L.length>=L.listsize){
        ElemType* newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize+=LISTINCREMENT;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"\t\t\t\t\t范茂伟：请输入第"<<i+1<<"个数:";
        cin>>L.elem[i];
        L.length++;
    }
    system("cls");
    cout<<endl<<"\t\t\t\t\t范茂伟：您已成功创建，准备好开始咯！  ";
    Sleep(3000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t3"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t2"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t1"<<endl;
    Sleep(1000);
}

Status Show(SqList L){
    if(L.length==0){
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
    for(int i=0;i<L.length;i++){
        cout<<"\t\t\t\t\t范茂伟：第"<<i+1<<"个数为:"<<L.elem[i]<<endl;
    }
    cout<<endl<<"\t\t\t\t\t范茂伟：一共"<<L.length<<"个数。"<<endl;
    cout<<endl<<endl<<"\t\t\t\t\t";
    system("pause");
}

Status Search(SqList L){
    cout<<endl<<"\t\t\t\t\t请输入你要查找的数：";
    ElemType e;
    cin>>e;
    for(int i=0; i<L.length; i++)
        if(L.elem[i] == e){
            cout<<"\t\t\t\t\t范茂伟：第"<<i+1<<"个数为"<<L.elem[i]<<endl;
            cout<<endl<<"\t\t\t\t\t";
            system("pause");
            return OK;
        }
    cout<<"\t\t\t\t\t范茂伟：未找到这个数"<<endl;
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    return ERROR;
}

Status Insert(SqList &L,int i,ElemType e){
    ElemType *p,*q;
    if(i<1||i>L.length+1){
        cout<<"\t\t\t\t\t序号越界，无效！"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }
    if(L.length>=L.listsize){
        ElemType* newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize+=LISTINCREMENT;
    }
    q=&(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;--p){
        *(p+1)=*p;
    }
    *q=e;
    ++L.length;
    return OK;
}

Status Delete(SqList &L){
    if(L.length<=0){
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
    if(L.length<i||i<1){
        cout<<endl<<"\t\t\t\t\t系统提示：序号越界，无效！"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }
    cout<<endl<<"\t\t\t\t\t系统提示：第"<<i<<"个数为"<<L.elem[i-1]<<"，请问是否确认删除？"<<endl;
    cout<<"\t\t\t\t\t(1代表YES，0代表NO)"<<endl;
    cout<<endl<<"\t\t\t\t\t你：";
    int a;
    cin>>a;
    if(a==1){
        ElemType *p,*q;
        p=&(L.elem[i-1]);
        ElemType e=*p;
        q=L.elem+L.length-1;
        for(++p;p<=q;++p){
            *(p-1)=*p;
        }
        L.length--;
        cout<<endl<<"\t\t\t\t\t请稍后";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
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

Status Ascend(SqList &L,int i){
    if(i==1){
        for (int j=0;j<L.length-1;j++)
            for (int k=0;k<L.length-1-j; k++)
                if (L.elem[k] > L.elem[k+1]){
                    int temp = L.elem[k];
                    L.elem[k] = L.elem[k+1];
                    L.elem[k+1] = temp;
                }
            cout<<endl<<"\t\t\t\t\t系统提示：正序排序成功！"<<endl;
            cout<<endl<<"\t\t\t\t\t";
            system("pause");
            return OK;
    }
    else if(i==2){
        for (int j=0;j<L.length-1;j++)
            for (int k=0;k<L.length-1-j; k++)
                if (L.elem[k] < L.elem[k+1]){
                    int temp = L.elem[k];
                    L.elem[k] = L.elem[k+1];
                    L.elem[k+1] = temp;
                }
            cout<<endl<<"\t\t\t\t\t系统提示：倒序排序成功！"<<endl;
            cout<<endl<<"\t\t\t\t\t";
            system("pause");
            return OK;
    }
    else{
        cout<<endl<<"\t\t\t\t\t系统提示：错误！";
    }
}

void Destory(SqList &L){
    L.length=0;
    cout<<endl<<"\t\t\t\t\t范茂伟：清空成功！即将退出。";
    Sleep(3000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t3"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t2"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t1"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t范茂伟：拜拜~(回车结束程序)"<<endl;
}

void Print(){
    system("cls");
    cout<<endl<<"\t\t\t\t\t    这是一个高端大气上档次的范茂伟的菜单图"<<endl;
    cout<<"\t\t\t\t\t_____________________________________________"<<endl;
    cout<<"\t\t\t\t\t|                 1.显示                    |"<<endl;
    cout<<"\t\t\t\t\t|                 2.查找                    |"<<endl;
    cout<<"\t\t\t\t\t|                 3.插入                    |"<<endl;
    cout<<"\t\t\t\t\t|                 4.删除                    |"<<endl;
    cout<<"\t\t\t\t\t|                 5.排序                    |"<<endl;
    cout<<"\t\t\t\t\t|                 0.清空                    |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t请输入相关指令:";
}

#endif // FUNCTION_H
