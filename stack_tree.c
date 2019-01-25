//
// Created by wu on 19-1-24.
//
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100


typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

typedef BiTree ElemType;
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

/**
 * 栈的初始化
 * @param S
 */
void init(SqStack *S) {
    S->top = -1;
}

/**
 * 创建二叉树
 * @param T
 * @return
 */
bool created_tree(BiTree *T) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *T = NULL;
    } else {
        BiTree p = (BiTree) malloc(sizeof(BiNode));
        if (T == NULL) {
            printf("创建节点失败，无法分配可用内存...");
            exit(-1);
        } else {
            p->data = ch;
            *T = p;
            created_tree(&p->lchild);
            created_tree(&p->rchild);
        }
    }
    return true;
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
ElemType pop(SqStack *S, ElemType x) {
    if (S->top == -1) return false;
    x = S->data[S->top--]; // x = S->top S.top = S->top -1
    return x;
}

/**
 * 先序遍历
 * @param S
 * @param T
 */
void first_foreach_stack_tree(SqStack *S, BiTree T) {
    init(S);
    BiTree p = T;

    while (p || !stack_empty(S)) {
        while (p) {
            printf("%c ", p->data);
            push(S, p);
            p = p->lchild;
        }
        if (!stack_empty(S)) {
            p = pop(S, p);
            p = p->rchild;
        }
    }
}

void in_foreach_stack_tree(SqStack * S,BiTree T){
    init(S);
    BiTree p = T;

    while (p || !stack_empty(S)) {
        while (p) {
            push(S, p);
            p = p->lchild;
        }
        if (!stack_empty(S)) {
            p = pop(S, p);
            printf("%c ",p->data);
            p = p->rchild;
        }
    }
}


void rear_foreach_stack_tree(SqStack * S,BiTree T){
    init(S);
    BiTree p = T, r = NULL;

    while (p || !stack_empty(S)) {
        if(p){
            push(S, p);
            p=p->lchild;
        }else{
            p = S->data[S->top];
            if(p->rchild && p->rchild != r){
                p = p->rchild;
            }else{
                pop(S,p);
                printf("%c ",p->data);
                r = p;
                p = NULL;
            }
        }

    }
}