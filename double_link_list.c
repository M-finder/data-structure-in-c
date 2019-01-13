//
// Created by wu on 19-1-13.
//

#include <stdbool.h>
#include <stdio.h>

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *prev, *next;  // 前驱和后继指针
} DNode, *DLinkList; // 结构体 结构体指针


/**
 * 双链表头插法
 * @param DL
 * @return
 */
DLinkList header_insert(DLinkList DL) {
    DLinkList s ;
    int x;
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->next = NULL;
    DL->prev = NULL;

    scanf("%d", &x);

    while (x != 999) {
        s = (DLinkList) malloc(sizeof(DNode));
        s->data = x;
        s->next = DL->next;
        if (DL->next) {
            DL->next->prev = s;
        }
        s->prev = DL;
        DL->next = s;
        scanf("%d", &x);
    }
    return DL;

}

/**
 * 双链表尾插法
 * @param DL
 * @return
 */
DLinkList last_insert(DLinkList DL) {
    DL = (DLinkList)malloc(sizeof(DNode));

    DLinkList s, r = DL;
    int x;
    DL->prev = NULL;

    scanf("%d", &x);

    while (x != 999) {
        s = (DLinkList) malloc(sizeof(DNode));
        s->data = x;
        r->next = s;
        s->prev = r;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return DL;
}

/**
 * 按序号查找
 * @param DL
 * @param x
 * @return
 */
DLinkList search_elem_by_num(DLinkList DL, int i){
    DLinkList p = DL->next;
    int j = 1;
    if(i ==0 ) return DL;
    if(i < 1) return NULL;

    while (p && j < i){
        p = p->next;
        j++;
    }
    return p;
}
/**
 * 按位插入
 * @param DL
 * @param i
 * @param e
 * @return
 */
bool insert_elem(DLinkList DL, int i, ElemType e) {
    DLinkList p = search_elem_by_num(DL, i - 1);
    if (p == NULL) return false;
    DLinkList s = (DLinkList) malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    s->prev = p;
    p->next = s;
    p->next->prev = s;
    return true;
}

/**
 * 按位删除
 * @param DL
 * @param x
 * @return
 */
bool delete_elem(DLinkList DL, int i){
    DLinkList p = search_elem_by_num(DL,i -1);
    if(!p) return false;

    DLinkList  q = p->next;
    if(!p->next) return false;

    p->next = q->next;
    if(q->next){
        q->next->prev = p;
    }
    free(q);
    return true;
}

void print_double_link_list(DLinkList DL) {
    DLinkList s = DL->next;
    while (s) {
        printf("%3d", s->data);
        s = s->next;
    }
    printf("\r\n\r\n");
}