//
// Created by wu on 19-1-12.
//

#include <stdbool.h>
#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
    int listsize;
} SqList;

void list_init(SqList *L) {
    L->data[0] = 1;
    L->data[1] = 2;
    L->data[2] = 3;
    L->length = 3;
}

void printList(SqList *L) {
    for (int i = 0; i < L->length; ++i) {
        printf("%3d", L->data[i]);
    }
    printf("\r\n\r\n");
}

/**
 * 顺序表插入
 * @param L
 * @param i
 * @param e
 * @return
 */
bool list_insert(SqList *L, int i, ElemType e) {

    if (i < 1 || i > L->length + 1) return false; //位置输入错误
    if (L->length >= MaxSize) return false; // 存储空间已满

    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }

    L->data[i - 1] = e;
    L->length++;
    return true;
}

/**
 * 顺序表删除操作
 * @param L
 * @param i
 * @return
 */
bool delete_elem(SqList *L, int i) {
    if (i < 1 || i > L->length) return false; // 删除位置错误
    for (int j = i; j < L->length; j++) { //移动 i 结点的后继结点
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

/**
 * 顺序表查操作
 * @param L
 * @param i
 * @return
 */
int search_elem(SqList *L, int i) {
    for (int j = 0; j < L->length; ++j) {
        if (i == L->data[j]) {
            return j + 1;
        }
    }
    return 0;
}