#ifndef STRUCT_H
#define STRUCT_H

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

#endif // STRUCT_H
