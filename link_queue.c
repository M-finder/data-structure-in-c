//
// Created by wu on 19-1-14.
//
#include <stdbool.h>

typedef int ElemType;
typedef struct LinkNode{ // 链式队列结点 强制类型转换
    ElemType data;
    struct LinkNode * next;
}LinkNode;

typedef struct { // 链式队列
    LinkNode * front, * rear; //队首队尾指针
}LinkQueue;

void link_queue_init(LinkQueue * LQ){
    LQ->rear = LQ->front = (LinkNode *)malloc(sizeof(LinkNode));
    LQ->front->next = NULL;
}
void en_link_queue(LinkQueue * LQ, ElemType x){
    LinkNode * s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    LQ->rear->next = s;
    LQ->rear = s;
}

int de_link_queue(LinkQueue * LQ, ElemType x){
    if(LQ->front == LQ->rear) return  0; // 空队
    LinkNode *p = LQ->front->next;
    x = p->data;
    LQ->front->next = p->next;
    if(LQ->rear == p) LQ->rear = LQ->front;
    free(p);
    return x;
}

void print_link_queue(LinkQueue *LQ){
    if(LQ->front == LQ->rear){
        printf("空");
        return;
    }
    LinkNode * s = LQ->front;
    while(s != LQ->rear){
        s = s->next;
        printf("%3d",s->data);
    }
    printf("\r\n\r\n");
}