//
// Created by wu on 19-1-13.
//
#include <stdbool.h>
#include <stdio.h>

typedef int ElemType;
typedef struct SNode{ // 定义结点
    ElemType data;
    struct SNode * next;
}SNode, * SLink;

typedef struct LinkStack{ // 定义链栈
    SLink top;
    int count;
}LinkStack;

bool link_stack_init(LinkStack * LS){
    LS->top = (SLink)malloc(sizeof(SNode));
    LS->top = NULL; // 栈顶指针清空
    return true;
}
bool link_stack_push(LinkStack * LS, ElemType x){
    SLink p = (SLink)malloc(sizeof(SNode)); // 给新元素分配空间
    p->data = x;
    p->next = LS->top; // 栈顶指针指向新元素
    LS->top = p;
    LS->count ++;
    return true;
}

ElemType link_stack_pop(LinkStack *LS, ElemType x){
    if (LS->top == NULL) return false;
    x = LS->top->data; // 栈顶元素值

    // 修改栈顶指针
    SLink p = LS->top;
    LS->top = LS->top->next;
    free(p);
    LS->count --;
    return x;
}

void print_link_stack(LinkStack * LS){
    SLink  p = LS->top;
    while (p != NULL){
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\r\n");
}