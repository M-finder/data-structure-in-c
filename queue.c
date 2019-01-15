//
// Created by wu on 19-1-14.
//

#include <stdbool.h>

#define MaxSize 5
typedef int ElemType;
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

bool de_queue(SqQueue *SQ, ElemType x) {
    if (SQ->rear == SQ->front) return false; // 队空
    x = SQ->data[SQ->front];
    SQ->front = (SQ->front + 1) % MaxSize;
    return true;
}

void print_queue(SqQueue *SQ) {

    for (int i = SQ->front; i < SQ->rear; i++) {
        printf("%3d",SQ->data[i]);
    }
    printf("\r\n\r\n");

}