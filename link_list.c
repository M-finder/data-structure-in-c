//
// Created by wu on 19-1-13.
//
#include <stdbool.h>
#include <stdio.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList; // 结构体 结构体指针， LNode * 也是结构体指针

/**
 * 单链表头插法
 * @param L
 * @return
 */
LinkList head_insert(LinkList LL) {
    int x;
    LinkList s;
    LL = (LinkList) malloc(sizeof(LNode)); // 创建头结点，分配头结点大小的内存
    LL->next = NULL;
    scanf("%d", &x);
    while (x != 999) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        s->next = LL->next;
        LL->next = s;
        scanf("%d", &x);
    }
    return LL;
}


/**
 * 尾插
 * @param LL
 */
void last_insert(LinkList LL) {
    int x;
    LNode *s, *r = LL;
    LL = (LinkList) malloc(sizeof(LNode));
    scanf("%d", &x);
    while (x != 999) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL; // 为了保证安全正确，尾结点指针置空

}

/**
 * 按值插入
 * @param LL
 * @param e
 * @return
 */
LinkList search_elem_by_value(LinkList LL, ElemType e) {
    LinkList p = LL->next;

    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}


LinkList search_elem_by_num(LinkList LL, int i){
    int j = 1;
    LinkList p = LL->next;
    if(i == 0 ) return LL; // 头结点
    if(i< 1) return NULL; // i 无效

    while(p && j < i){
        p = p->next;
        j++;
    }

    if(j == i) return p;
    else return NULL;


}

/**
 * 按位插入
 * @param L
 * @param i
 * @param x
 * @return
 */
void insert_elem(LinkList LL, int i, ElemType x) {

    LNode *p = search_elem_by_num(LL, i - 1);
    LinkList s = (LinkList) malloc(sizeof(LNode));
    s->next = p->next;
    s->data = x;
    p->next = s;
}

bool delete_elem(LinkList LL, int i) {
    LinkList p = search_elem_by_num(LL, i - 1);
    LinkList q;
    q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

void print_link_list(LinkList LL) {
    LinkList s = LL->next;
    while (s) {
        printf("%3d", s->data);
        s = s->next;
    }
    printf("\r\n\r\n");
}