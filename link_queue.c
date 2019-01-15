//
// Created by wu on 19-1-14.
//
#include <stdbool.h>

typedef int ElemType;
typedef struct{ // 链式队列结点
    ElemType data;
    struct LinkNode * next;
}LinkNode;

typedef struct { // 链式队列
    LinkNode * front, * rear; //队首队尾指针
}LinkQueue;

void en_link_queue(LinkQueue * LQ, ElemType x){
    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next - NULL;
    LQ->rear-next = s;
    LQ->rear = s;
}

bool de_link_queue(LinkQueue * LQ, ElemType x){
    if(LQ->front == LQ->rear) return  false; // 空队
    p = LQ->front->next;
    x = p->data;
    LQ->front->next = p->next;
    if(LQ->rear == p) LQ->rear = LQ->front;
    free(p);
    return true;
}