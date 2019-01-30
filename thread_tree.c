//
// Created by m on 2019/1/28.
//

#include <stdlib.h>
#include <stdbool.h>

// 线索二叉树
typedef char ElemType;
typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 标志位 左标志位和右标志位 0 表示指向左右子树，1表示指向前驱后继
} ThreadNode, *ThreadTree;

ThreadTree pre = NULL;

bool created_tree(ThreadTree *T) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *T = NULL;
    } else {
        ThreadTree p = (ThreadTree) malloc(sizeof(ThreadNode));
        if (T == NULL) {
            printf("创建节点失败，无法分配可用内存...");
            exit(-1);
        } else {
            p->data = ch;
            p->ltag = 0;
            p->rtag = 0;
            *T = p;
            created_tree(&p->lchild);
            created_tree(&p->rchild);
        }
    }
    return true;
}

void foreach_tree(ThreadTree T) {
    if (T != NULL) {
        printf("%c ", T->data);
        foreach_tree(T->lchild);
        foreach_tree(T->rchild);
    } else {
        printf("# ");
    }

}

/**
 * 先序线索化
 * @param T
 */
void first_threading(ThreadTree T) {

    if (T == NULL) return;

    if (T->lchild == NULL) {
        T->ltag = 1;
        T->lchild = pre;
    }

    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = 1;
        pre->rchild = T;
    }
    pre = T;
    if (T->ltag == 0) first_threading(T->lchild);
    if (T->rtag == 0) first_threading(T->rchild);
}

/**
 * 中序线索化
 * @param T
 * @param pre
 */
void in_threading(ThreadTree T) {
    if (T == NULL) return;

    if (T->lchild && T->ltag == 0) in_threading(T->lchild);

    if (T->lchild == NULL) {
        T->ltag = 1;
        T->lchild = pre;
    }

    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = 1;
        pre->rchild = T;
    }
    pre = T;

    if (T->rchild && T->rtag == 0) in_threading(T->rchild);
}

void post_threading(ThreadTree T) {
    if (T == NULL) return;

    if (T->lchild && T->ltag == 0) in_threading(T->lchild);
    if (T->rchild && T->rtag == 0) in_threading(T->rchild);
    if (T->lchild == NULL) {
        T->ltag = 1;
        T->lchild = pre;
    }

    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = 1;
        pre->rchild = T;
    }
    pre = T;
}

/**
 * 先序遍历
 * @param T
 */
void first_foreach_thread_tree(ThreadTree T) {
    while (T) {
        while (T->ltag == 0) {
            printf("%c ", T->data);
            T = T->lchild;
        }
        printf("%c ", T->data);
        T = T->rchild;

        while (T) {
            if (T->lchild != NULL && T->rtag == 0) {
                break;
            }
            printf("%c ", T->data);
            T = T->rchild;
        }
    }
}

/**
 * 中序遍历
 * @param T
 */
void in_foreach_thread_tree(ThreadTree T) {
    while (T) {
        while (T->ltag == 0) {
            T = T->lchild;
        }
        printf("%c ", T->data);
        while (T && T->rtag == 1) {
            T = T->rchild;
            printf("%c ", T->data);
        }
        T = T->rchild;
    }
}