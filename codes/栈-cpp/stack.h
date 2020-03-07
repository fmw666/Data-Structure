#ifndef STACK_H
#define STACK_H

#include "head.h"

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


#endif // STACK_H
