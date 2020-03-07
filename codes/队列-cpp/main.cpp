#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    string s;
    QElemType e;
    SqQueue q;
    InitQueue(q);
    int flag=1;
    while(flag!=0){
        print();
        cin>>flag;
        switch (flag) {
        case 1:
            cout<<endl<<"\t\t\t\t\t请输入要压入的数：";
            cin>>e;
            if(EnQueue(q,e)==OK){
                cout<<endl<<"\t\t\t\t\t压入队列完成！";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t压入队列失败！";
                system("pause");
            }
            break;
        case 2:
            if(DeQueue(q,e)==OK){
                cout<<endl<<"\t\t\t\t\t弹出队列完成！弹出元素为："<<e<<endl;
                cout<<"\t\t\t\t\t";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t此队列为空，请问是否压数进队列(1代表YES，0代表NO)：";
                int a;
                cin>>a;
                if(a==0){
                    cout<<"\t\t\t\t\t";
                    system("pause");
                }else if(a==1){
                    cout<<"\t\t\t\t\t请输入要压入的数：";
                    cin>>e;
                    EnQueue(q,e);
                    cout<<endl<<"\t\t\t\t\t压入队列完成！";
                    system("pause");
                }else{
                    cout<<"\t\t\t\t\t输入有误！";
                    system("pause");
                }
            }
            break;
        case 3:
            cout<<endl<<"\t\t\t\t\t此队列的长度为："<<QueueLength(q)<<endl;
            cout<<"\t\t\t\t\t";
            system("pause");
            break;
        case 4:
            cout<<endl<<"\t\t\t\t\t请输入一串序列：";
            cin>>s;
            if(judgeNum(s)==TRUE){
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
    }

    return 0;
}
