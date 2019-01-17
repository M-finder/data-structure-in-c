//
// Created by wu on 19-1-13.
//
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
void init(SqStack *S) {
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
bool push(SqStack *S, ElemType x) {
    if (S->top == MaxSize - 1) return false;
    S->top++;
    S->data[S->top] = x;
    return true;
}

/**
 * 出栈
 * @param S
 * @param x
 * @return
 */
ElemType pop(SqStack *S, ElemType *x) {
    if (S->top == -1) return false;
    *x = S->data[S->top--]; // x = S->top S.top = S->top -1
    return *x;
}

void printStack(SqStack *S) {
    for (int i = 0; i <= S->top; i++) {
        printf("%3d", S->data[i]);
    }
    printf("\r\n\r\n");
}
/**
 * 括号匹配
 * @param S
 * @param str
 * @return
 */
bool stack_check(SqStack *S, char *str) {
    int len = strlen(str);
    ElemType x;
    for (int i = 0; i < len; i++) {
        char a = str[i];
        switch (a) {
            case '(':
                push(S, a);
                break;
            case '[':
                push(S, a);
                break;
            case ')':
                pop(S, &x);
                if(x != '('){
                    printf("不匹配 \r\n");
                    return false;
                }
                break;
            case ']':
                pop(S, &x);
                if(x != '['){
                    printf("不匹配 \r\n");
                    return false;
                }
                break;

        }

    }
    if (stack_empty(S)){
        printf("空\r\n");
        return true;
    }else{
        return false;
    }

}

/**
 * 后缀表达式求值
 * @param S
 * @param str
 * @return
 */
int stack_eva(SqStack *S, char *str){
    int len = strlen(str);
    printf("len = %d\r\n",len);
    ElemType x,y;
    for (int i = 0; i < len; i++) {
        char a = str[i];
        switch (a) {
            case '+':
                pop(S, &x);
                pop(S, &y);
                push(S,x+y);
                printStack(S);
                break;
            case '-':
                pop(S, &x);
                pop(S, &y);
                push(S,x-y);
                printStack(S);
                break;
            case '*':
                pop(S, &x);
                pop(S, &y);
                push(S,x*y);
                printStack(S);
                break;
            case '/':
                pop(S, &x);
                pop(S, &y);
                push(S,y/x);
                printStack(S);
                break;
            default:
                push(S, a);
                printStack(S);
                break;

        }

    }

    return 0;
}

