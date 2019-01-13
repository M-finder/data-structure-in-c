//
// Created by wu on 19-1-13.
//

#include <stdbool.h>

#define MaxSize 10

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int topA;
    int topB;
} SqDoubleStack;

/**
 * 共享栈
 * @param DS
 */
void share_stack_init(SqDoubleStack *DS) {
    DS->topA = -1;
    DS->topB = MaxSize;
}

/**
 * 共享栈进栈
 * @param DS
 * @param x
 * @param stackNum
 * @return
 */
bool share_push(SqDoubleStack *DS, ElemType x, int stackNum) {
    if (DS->topA + 1 == DS->topB) return false;

    if (stackNum == 1) DS->data[++DS->topA] = x;
    else if (stackNum == 2) DS->data[--DS->topB] = x;
    return true;
}

/**
 * 共享栈出栈
 * @param DS
 * @param x
 * @param stackNum
 * @return
 */
ElemType share_pop(SqDoubleStack *DS, ElemType x, int stackNum) {
    if (stackNum == 1 && DS->topA != -1) {
        x = DS->data[DS->topA--];
        return x;
    } else if (stackNum == 2 && DS->topB != MaxSize) {
        x = DS->data[DS->topB++];
        return x;
    }
    return false;

}

/**
 * 共享栈打印
 * @param DS
 */
void print_share_stack(SqDoubleStack *DS) {
    printf("topA:");
    for (int i = 0; i <= DS->topA; i++) {
        printf("%3d", DS->data[i]);
    }
    printf("\r\n\r\n");
    printf("topB:");
    for (int j = MaxSize-1; j >= DS->topB; j--) {
        printf("%3d", DS->data[j]);
    }
    printf("\r\n\r\n");
}