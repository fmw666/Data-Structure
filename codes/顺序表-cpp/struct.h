#ifndef STRUCT_H
#define STRUCT_H

typedef int ElemType;

typedef struct
{
    ElemType *elem;//存储空间基址
    int     length;//当前长度
    int   listsize;//当前分配的存储容量
}SqList;

#endif // STRUCT_H
