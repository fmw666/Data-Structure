#include <iostream>
#include <stdio.h>
#include "function.h"

using namespace std;

int main()
{
    SqStack s;
    InitStack(s);
    int Sel=1;
    SElemType e;
    string str;
    int data;
    int a;
    while(Sel!=0){
        print();
        cin>>Sel;
        switch (Sel) {
        case 1:
            if(GetTop(s,e)==OK){
                cout<<endl<<"\t\t\t\t\t栈顶元素为："<<e<<endl;
                cout<<"\t\t\t\t\t";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t此栈为空，请问是否压栈(1代表YES，0代表NO)：";
                int a;
                cin>>a;
                if(a==0){
                    cout<<"\t\t\t\t\t";
                    system("pause");
                }else if(a==1){
                    cout<<"\t\t\t\t\t请输入要压栈的数：";
                    cin>>e;
                    Push(s,e);
                    cout<<endl<<"\t\t\t\t\t压栈完成！";
                    system("pause");
                }else{
                    cout<<"\t\t\t\t\t输入有误！";
                    system("pause");
                }
            }
            break;
        case 2:
            cout<<endl<<"\t\t\t\t\t请输入要压栈的数：";
            cin>>e;
            if(Push(s,e)==OK){
                cout<<endl<<"\t\t\t\t\t压栈完成！";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t压栈失败！";
                system("pause");
            }
            break;
        case 3:
            if(Pop(s,e)==OK){
                cout<<endl<<"\t\t\t\t\t弹栈完成！弹出元素为："<<e<<endl;
                cout<<"\t\t\t\t\t";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t此栈为空，请问是否压栈(1代表YES，0代表NO)：";
                int a;
                cin>>a;
                if(a==0){
                    cout<<"\t\t\t\t\t";
                    system("pause");
                }else if(a==1){
                    cout<<"\t\t\t\t\t请输入要压栈的数：";
                    cin>>e;
                    Push(s,e);
                    cout<<endl<<"\t\t\t\t\t压栈完成！";
                    system("pause");
                }else{
                    cout<<"\t\t\t\t\t输入有误！";
                    system("pause");
                }
            }
            break;
        case 4:
            Show(s);
            break;
        case 5:
            if(StackEmpty(s)==TRUE){
                cout<<endl<<"\t\t\t\t\t确实是空栈！";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t不是空栈！";
                system("pause");
            }
            break;
        case 6:
            cout<<endl<<"\t\t\t\t\t此栈的长度为："<<StackLength(s)<<endl;
            cout<<"\t\t\t\t\t";
            system("pause");
            break;
        case 7:
            if(ClearStack(s)==TRUE){
                cout<<endl<<"\t\t\t\t\t已清空变为空栈！";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t清空失败！";
                system("pause");
            }
            break;
        case 8:
            if(DestroyStack(s)==OK)
                cout<<endl<<"\t\t\t\t\t销毁成功！";
            else{
                cout<<endl<<"\t\t\t\t\t销毁失败！";
                break;
            }
            system("pause");
            while(Sel!=0){
                print_in();
                cin>>Sel;
                switch (Sel) {
                case 1:
                    cout<<endl<<"\t\t\t\t\t请输入一个十进制数：";
                    cin>>data;
                    cout<<"\t\t\t\t\t转化为几进制：";
                    cin>>a;
                    conversion(data,a);
                break;
                case 2:
                    cout<<endl<<"\t\t\t\t\t请输入一串带‘(、)、[、]’的序列：";
                    cin>>str;
                    if(matching(str)==OK){
                        cout<<endl<<"\t\t\t\t\t括号匹配！";
                    }
                    else{
                        cout<<endl<<"\t\t\t\t\t括号不匹配！";
                    }
                    system("pause");
                break;
                case 3:
                    cout<<endl<<"\t\t\t\t\t该功能还未实现，";
                    system("pause");
                break;
                case 4:
                    cout<<endl<<"\t\t\t\t\t请输入一串序列：";
                    cin>>str;
                    if(judgeNum(str)==TRUE){
                        cout<<endl<<"\t\t\t\t\t是回文数，";
                        system("pause");
                    }
                    else{
                        cout<<endl<<"\t\t\t\t\t不是回文数，";
                        system("pause");
                    }
                break;
                case 0:
                    cout<<endl<<"\t\t\t\t\t退出成功！";
                    system("pause");
                    exit(0);
                    break;
                default:
                    cout<<endl<<"\t\t\t\t\t输入不合法！";
                    system("pause");
                break;
                }
            };

        case 9:
            cout<<endl<<"\t\t\t\t\t请输入一个十进制数：";
            cin>>data;
            cout<<"\t\t\t\t\t转化为几进制：";
            cin>>a;
            conversion(data,a);
            break;
        case 10:

            cout<<endl<<"\t\t\t\t\t请输入一串带‘(、)、[、]’的序列：";
            cin>>str;
            if(matching(str)==OK){
                cout<<endl<<"\t\t\t\t\t括号匹配！";
            }
            else{
                cout<<endl<<"\t\t\t\t\t括号不匹配！";
            }
            system("pause");
            break;
        case 11:
            cout<<endl<<"\t\t\t\t\t该功能还未实现，";
            system("pause");
        break;
        case 12:
            cout<<endl<<"\t\t\t\t\t请输入一串序列：";
            cin>>str;
            if(judgeNum(str)==TRUE){
                cout<<endl<<"\t\t\t\t\t是回文数，";
                system("pause");
            }
            else{
                cout<<endl<<"\t\t\t\t\t不是回文数，";
                system("pause");
            }
        break;
        case 0:
            cout<<endl<<"\t\t\t\t\t退出成功！";
            system("pause");
            exit(0);
            break;
        default:
            cout<<endl<<"\t\t\t\t\t输入不合法！";
            system("pause");
            break;
        }
    };

    return 0;
}
