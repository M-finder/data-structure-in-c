//
// Created by wu on 19-1-13.
//
#include <stdbool.h>
#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

/**
 * 初始化
 * @param S
 */
void init(SqStack *S){
    S->top = -1;
}
/**
 * 判空
 * @param S
 * @return
 */
bool stack_empty(SqStack *S) { // 结构体操作，所以下边用 . 操作
    return (S->top == -1) ? true : false;
}

/**
 * 进栈
 * @param S
 * @param x
 * @return
 */
bool push(SqStack *S, ElemType x){
    if (S->top == MaxSize-1) return false;
    S->top ++;
    S->data[S->top] = x;
    return true;
}

/**
 * 出栈
 * @param S
 * @param x
 * @return
 */
ElemType pop(SqStack *S, ElemType x){
    if (S->top == -1) return false;
    x = S->data[S->top--]; // x = S->top S.top = S->top -1
    return x;
}

void printStack(SqStack * S) {
    for (int i = 0; i <= S->top; i++) {
        printf("%3d", S->data[i]);
    }
    printf("\r\n\r\n");
}
