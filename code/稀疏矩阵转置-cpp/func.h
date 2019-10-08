#ifndef FUNC_H
#define FUNC_H

#include "struct.h"

Status CreateSMatrix(TSMatrix &M);   //创建
Status DestroySMatrix(TSMatrix &M);   //销毁
void PrintSMatrix(TSMatrix M);   //输出

Status TransposeSMatrix(TSMatrix M,TSMatrix &T);   //转置
Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T);  //快转


Status CreateSMatrix(TSMatrix &M){
    int i,j;
    int count=0; //非零元
    cout<<"请问你要创建多大的稀疏矩阵？"<<endl;
    cout<<"行：";
    cin>>i;
    cout<<"列：";
    cin>>j;
    cout<<endl;
    cout<<"请输入非零元的个数：";
    cin>>count;
    M.mu = i;
    M.nu = j;
    M.tu = count;
    cout<<"请按照(行、列、值)的格式依次输入"<<M.tu<<"个非零元的信息：\n";
    int m,n,t;
    for(int i=1;i<=M.tu;i++)
    {
        cin>>m>>n>>t;
        M.data[i].i=m;
        M.data[i].j=n;
        M.data[i].e=t;
    }
    cout<<"您已创建完成一个稀疏矩阵！"<<endl;
    return OK;
}

Status DestroySMatrix(TSMatrix &M){
    if (M.tu != 0){
    for (int ii = 1; ii <= M.tu; ++ii){
        M.data[ii].i = 0;
        M.data[ii].j = 0;
        M.data[ii].e = 0;
        }
        M.mu = 0;
        M.tu = 0;
        M.nu = 0;
        return OK;
    }
    else
        return ERROR;
}

void PrintSMatrix(TSMatrix M){
    cout<<endl;
    int k =1;
    for(int i=1;i<=M.mu;i++)
    {
        for(int j=1;j<=M.nu;j++)
        {
            if(M.data[k].i==i && M.data[k].j==j && k<=M.tu)
            {
                cout<<M.data[k++].e<<" ";
            }else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}


Status TransposeSMatrix(TSMatrix M,TSMatrix &T){
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    int q=1;
    if(T.tu){
        for(int col=1;col<=M.nu;++col)
            for(int p=1;p<=M.tu;++p){
                if(M.data[p].j==col){
                    T.data[q].i=M.data[p].j;
                    T.data[q].j=M.data[p].i;
                    T.data[q].e=M.data[p].e;
                    ++q;
                }
            }
        return OK;
    }
}

Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T){
    int col, t, p, q;
    int num[20], cpot[20];
    T.mu = M.nu;  T.nu = M.mu;  T.tu = M.tu;
    if (T.tu) {
        for (col = 1; col <= M.nu; ++col)	//对列数进行初始化
            num[col] = 0;
        for (t = 1; t <= M.tu; ++t) // 求 M 中每一列所含非零元的个数
            ++num[M.data[t].j];
        cpot[1] = 1;
        // 求 M 中每一列的第一个非零元在 b.data 中的序号
        for (col = 2; col <= M.nu; ++col)
            cpot[col] = cpot[col - 1] + num[col - 1];
        for (p = 1; p <= M.tu; ++p)
        {
            col = M.data[p].j;
            q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        } // for
    } // if
    return OK;
}



#endif // FUNC_H
