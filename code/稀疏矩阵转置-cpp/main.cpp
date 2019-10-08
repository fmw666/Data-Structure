#include <iostream>
#include "func.h"

using namespace std;

int main()
{
    TSMatrix M;
    CreateSMatrix(M);
    PrintSMatrix(M);

    TSMatrix T;

    int i;
    cout<<"请选择：1.普通转置，2.快速转置"<<endl;
    cin>>i;
    if(i==1){
        TransposeSMatrix(M,T);
        PrintSMatrix(T);
    }
    else if(i==2){
        FastTransposeSMatrix(M,T);
        PrintSMatrix(T);
    }
    else
        cout<<"输入有误!"<<endl;
    DestroySMatrix(M);
    DestroySMatrix(T);

    return 0;
}
