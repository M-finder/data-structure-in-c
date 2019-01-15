#include <stdio.h>
#include <malloc.h>
#include "queue.c"

int main() {

    SqQueue SQ;
    queue_init(&SQ);
    en_queue(&SQ, 2);
    en_queue(&SQ, 3);
    en_queue(&SQ, 4);
    en_queue(&SQ, 5);

    print_queue(&SQ);

    printf("Hello, World!\n");
    return 0;
}

// 链栈
/*int main(){

    LinkStack  LS;
    link_stack_init(&LS);
    link_stack_push(&LS,2);
    link_stack_push(&LS,3);
    link_stack_push(&LS,4);
    link_stack_push(&LS,5);
    print_link_stack(&LS);
    ElemType x;
    x = link_stack_pop(&LS,x);
    print_link_stack(&LS);
    printf("x = %d\r\n",x);

    printf("Hello, World!\n");
    return 0;
}
*/

// 共享栈
/*int main() {

    SqDoubleStack DS;
    share_stack_init(&DS);
    share_push(&DS, 1, 1);
    share_push(&DS, 2, 1);
    share_push(&DS, 3, 1);
    share_push(&DS, 4, 1);
    share_push(&DS, 5, 1);

    share_push(&DS, 9, 2);
    share_push(&DS, 8, 2);
    share_push(&DS, 7, 2);
    share_push(&DS, 6, 2);
    share_push(&DS, 5, 2);

    print_share_stack(&DS);

    ElemType ta, tb;
    ta = share_pop(&DS, ta, 1);
    printf("a=%3d", ta);
    printf("\r\n");

    tb = share_pop(&DS, tb, 2);
    printf("b=%3d", tb);
    printf("\r\n");

    print_share_stack(&DS);
    printf("Hello, World!\n");
    return 0;
}
*/

// 顺序栈
/*int main() {

    SqStack S;
    init(&S);
    if(stack_empty(&S)){
        printf("yes\r\n");
    }
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    printStack(&S);
    ElemType  s;
    s=  pop(&S,s);
    printf("%3d",s);
    printf("\r\n");
    printStack(&S);
    printf("Hello, World!\n");
    return 0;
}*/

// 双链表
/*int main() {
    DLinkList DL;
//    DL = header_insert(DL);
    DL = last_insert(DL);

    print_double_link_list(DL);

    insert_elem(DL,2,90);
    print_double_link_list(DL);

    delete_elem(DL,2);
    print_double_link_list(DL);

    printf("Hello, World!\n");
    return 0;
}
*/

// 链表调用
/*int main() {

    LinkList LL;
    LL = head_insert(LL);

//    LNode LL;
//    head_insert(&LL);

    print_link_list(LL);

    insert_elem(LL, 2, 90);

    print_link_list(LL);

    delete_elem(LL,2);

    print_link_list(LL);

    printf("Hello, World!\n");
    return 0;
}*/

// 顺序表调用
/*int main() {

    SqList L; // 结构体
    list_init(&L);
    list_insert(&L,1,20);

    printList(&L);

    delete_elem(&L,2);
    printList(&L);

    ElemType  x = search_elem(&L,2);
    printf("%3d\r\n",x);
    printf("Hello, World!\n");
    return 0;
}*/


