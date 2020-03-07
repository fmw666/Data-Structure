#include "function.h"
#include "head.h"
#include "struct.h"

int main()
{
    SqList L;
    InitList(L);
    Creat(L);
    int Sel=1;
    while(Sel!=0){
        Print();
        cin>>Sel;
        switch (Sel) {
        case 1:
            Show(L);
            break;
        case 2:
            Search(L);
            break;
        case 3:
            cout<<endl<<"\t\t\t\t\t范茂伟：你想插入的位置在哪？"<<endl;
            cout<<endl<<"\t\t\t\t\t你：";
            int i1;
            cin>>i1;
            cout<<endl<<"\t\t\t\t\t范茂伟：你想插入哪个数？"<<endl;
            cout<<endl<<"\t\t\t\t\t你：";
            ElemType e;
            cin>>e;
            Insert(L,i1,e);
            break;
        case 4:
            Delete(L);
            break;
        case 5:
            cout<<endl<<"\t\t\t\t\t请选择： 1.正向排序   2.逆向排序"<<endl;
            int i;
            cout<<"\t\t\t\t\t你的选择是：";
            cin>>i;
            Ascend(L,i);
            break;
        case 0:
            Destory(L);
            break;
        default:
            break;
        }
    };
}
