//
// Created by wu on 19-1-26.
//
// 层序遍历二叉树
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
    int front, rear;
} SqQueue;

void queue_init(SqQueue *SQ) {
    SQ->front = SQ->rear = 0;
}

bool en_queue(SqQueue *SQ, ElemType x) {
    if ((SQ->rear + 1) % MaxSize == SQ->front) return false; // 队满
    SQ->data[SQ->rear] = x;
    SQ->rear = (SQ->rear + 1) % MaxSize;
    return true;
}

ElemType de_queue(SqQueue *SQ, ElemType x) {
    if (SQ->rear == SQ->front) return false; // 队空
    x = SQ->data[SQ->front];
    SQ->front = (SQ->front + 1) % MaxSize;
    return x;
}

bool is_empty(SqQueue *SQ) {
    if (SQ->front == SQ->rear) return true;
    else return false;

}

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
void level_foreach_tree(SqQueue *SQ, BiTree T) {
    queue_init(SQ);
    BiTree p;
    en_queue(SQ, T);
    while (!is_empty(SQ)) {
        p = de_queue(SQ, p);
        printf("%c ", p->data);
        if(p->lchild != NULL)
            en_queue(SQ, p->lchild);
        if(p->rchild != NULL)
            en_queue(SQ, p->rchild);

    }
}