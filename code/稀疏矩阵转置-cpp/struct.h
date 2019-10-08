#ifndef STRUCT_H
#define STRUCT_H

#include "head.h"

typedef struct{
    int i,j;     //该非零元的行下标和列下标
    ElemType e;
}Triple;

typedef struct{
    Triple data[MAXSIZE + 1];  //非零元三元组表，data[0]未用
    int mu,nu,tu;  //矩阵的行数、列数和非零元个数
}TSMatrix;


#endif // STRUCT_H
