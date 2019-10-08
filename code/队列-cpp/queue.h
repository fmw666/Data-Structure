#ifndef QUEUE_H
#define QUEUE_H

#include "head.h"

typedef struct{
    QElemType *base; //初始化的动态分配存储空间
    int front;       //头指针，若队列不空，指向队列头元素
    int rear;        //尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;

#endif // QUEUE_H
