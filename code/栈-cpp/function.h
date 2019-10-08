#ifndef FUNCTION_H
#define FUNCTION_H

#include "stack.h"
#include <Windows.h>

Status InitStack(SqStack &s);//构造一个空栈s
Status DestroyStack(SqStack &s);//销毁栈s
Status ClearStack(SqStack &s);//把s置为空
Status StackEmpty(SqStack s);//判断s是否为空
int StackLength(SqStack s);//s的长度
Status GetTop(SqStack s,SElemType &e);//若栈不空，e返回s栈顶元素
Status Push(SqStack &s,SElemType e);//插入元素e为新的栈顶元素
Status Pop(SqStack &s,SElemType &e);//若栈不空，删除s的栈顶元素，用e返回
void Show(SqStack s);//输出栈s里面的值
void print();//显示菜单
void conversion(int n,int d);//进制转换
Status matching(string exp);//括号匹配
Status judgeNum(string exp);//回文判断

Status InitStack(SqStack &s){
    //构造一个空栈s
    s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!s.base) exit(OVERFLOW);
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &s){
    s.top=NULL;
    s.stacksize=0;
    free(s.base);
    return OK;
}

Status ClearStack(SqStack &s){
    SElemType e;
    while( !StackEmpty(s) )
        Pop(s,e);
    return OK;
}

Status StackEmpty(SqStack s){
    if(s.top==s.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack s){
    return s.top-s.base;
}

Status GetTop(SqStack s,SElemType &e){
    if(s.top==s.base) return ERROR;
    e=*(s.top-1);
    return OK;
}

Status Push(SqStack &s,SElemType e){
    if(s.top-s.base>=s.stacksize){
        s.base=(SElemType *)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!s.base)
            exit(OVERFLOW);
        s.top=s.base+s.stacksize;
        s.stacksize+=STACKINCREMENT;
    }
    *s.top++ = e;
    return OK;
}

Status Pop(SqStack &s,SElemType &e){
    if(s.top==s.base)
        return ERROR;
    e=*--s.top;
    return OK;
}

void Show(SqStack s){
    SqStack tmp;
    InitStack(tmp);
    SElemType e;
    int i=0;
    cout<<endl;
    while(!StackEmpty(s)){
        Pop(s,e);
        i++;
        cout<<"\t\t\t\t\t第"<<i<<"个数为："<<e<<endl;
    }
    cout<<endl<<"\t\t\t\t\t一共"<<i<<"个数";
    system("pause");
}

void print()
{
    system("cls");
    cout<<endl<<"\t\t\t\t\t这是一个高端大气上档次的范茂伟的菜单图"<<endl;
    cout<<"\t\t\t\t\t_______________________________________"<<endl;
    cout<<"\t\t\t\t\t|              1.显示栈顶             |"<<endl;
    cout<<"\t\t\t\t\t|              2.压栈                 |"<<endl;
    cout<<"\t\t\t\t\t|              3.弹栈                 |"<<endl;
    cout<<"\t\t\t\t\t|              4.遍历显示             |"<<endl;
    cout<<"\t\t\t\t\t|              5.判断空栈             |"<<endl;
    cout<<"\t\t\t\t\t|              6.栈长                 |"<<endl;
    cout<<"\t\t\t\t\t|              7.清空                 |"<<endl;
    cout<<"\t\t\t\t\t|              8.销毁                 |"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------|"<<endl;
    cout<<"\t\t\t\t\t|              9.进制转换             |"<<endl;
    cout<<"\t\t\t\t\t|              10.括号匹配            |"<<endl;
    cout<<"\t\t\t\t\t|              11.表达式求值          |"<<endl;
    cout<<"\t\t\t\t\t|              12.回文判定            |"<<endl;
    cout<<"\t\t\t\t\t|              0.退出                 |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t请输入相关指令:";
}

void print_in()
{
    system("cls");
    cout<<endl<<"\t\t\t\t\t这是一个高端大气上档次的范茂伟的菜单图"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------|"<<endl;
    cout<<"\t\t\t\t\t|              1.进制转换             |"<<endl;
    cout<<"\t\t\t\t\t|              2.括号匹配             |"<<endl;
    cout<<"\t\t\t\t\t|              3.表达式求值           |"<<endl;
    cout<<"\t\t\t\t\t|              4.回文判定             |"<<endl;
    cout<<"\t\t\t\t\t|              0.退出                 |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t请输入相关指令:";
}

Status matching(string exp){
    SqStack s;
    InitStack(s);
    SElemType e;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='('||exp[i]=='['){
            Push(s,exp[i]);
        }
        else if(exp[i]==')'){
            GetTop(s,e);
            if(e=='('){
                Pop(s,e);
            }
            else
                return ERROR;
        }
        else if(exp[i]==']'){
            GetTop(s,e);
            if(e=='['){
                Pop(s,e);
            }
            else
                return ERROR;
        }
        else{
            return ERROR;
        }
    }
    if(StackEmpty(s)==TRUE)
        return OK;
    else
        return ERROR;
}

void conversion(int n,int d){
    SqStack s;
    InitStack(s);
    SElemType e;
    int temp=n;
    while(n>0){
        Push(s,n%d);
        n=n/d;
    }
    cout<<endl<<"\t\t\t\t\t转换后的值为：";
    while(!StackEmpty(s)){
        Pop(s,e);
        cout<<e;
    }
    cout<<endl;
    cout<<"\t\t\t\t\t";
    system("pause");
}

Status judgeNum(string exp){
    SqStack s;
    InitStack(s);
    SElemType e;
    for(int i=0;i<exp.length();i++){
        Push(s,exp[i]);
    }
    for(int i=0;i<exp.length();i++){
        GetTop(s,e);
        if(exp[i]!=e)
            return FALSE;
        else
            Pop(s,e);
    }
    return TRUE;
}

#endif // FUNCTION_H
