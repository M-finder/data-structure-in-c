//
// Created by wu on 19-1-21.
//

#include <stdlib.h>
#include <stdbool.h>

typedef struct BiNode {
    char data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;


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

void foreach_tree(BiTree T) {
    if (T != NULL) {
        printf("%c ", T->data);
        foreach_tree(T->lchild);
        foreach_tree(T->rchild);
    }

}

void foreach_in_tree(BiTree T){
    if(T != NULL){
        foreach_in_tree(T->lchild);
        printf("%c ",T->data);
        foreach_in_tree(T->rchild);
    }
}

void foreach_rear_tree(BiTree T){
    if(T != NULL){
        foreach_post_tree(T->lchild);
        foreach_post_tree(T->rchild);
        printf("%c ",T->data);
    }
}
