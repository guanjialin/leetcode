//
// Created by addzero on 2020/12/5.
//


#ifdef __LOCAL__
#include "header.h"
#endif


typedef struct {
    int size;
    struct double_list_node *head, *ptr_mid;
} FrontMiddleBackQueue;


FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue *obj = (FrontMiddleBackQueue *) calloc(1, sizeof(FrontMiddleBackQueue));
    obj->head = double_list_create();
    obj->ptr_mid = obj->head;

    return obj;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    double_list_push_front(obj->head, val);
    ++obj->size;
    if (1 == obj->size || !((obj->size) % 2)) {
        obj->ptr_mid = obj->ptr_mid->prev;
    }
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    struct double_list_node *node =
            obj->size % 2 ? double_list_insert_before(obj->ptr_mid, val) : double_list_insert_after(obj->ptr_mid, val);

    obj->ptr_mid = node;
    ++obj->size;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    double_list_push_back(obj->head, val);
    if ((++obj->size) % 2) {
        obj->ptr_mid = obj->ptr_mid->next;
    }
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if (!double_list_empty(obj->head)) {
        return -1;
    }

    --obj->size;
    if (!obj->size || (obj->size) % 2) {
        obj->ptr_mid = obj->ptr_mid->next;
    }

    return double_list_pop_front(obj->head);
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if (!double_list_empty(obj->head)) {
        return -1;
    }

    struct double_list_node *node = obj->ptr_mid;
    obj->ptr_mid = --obj->size % 2 ? obj->ptr_mid->next : obj->ptr_mid->prev;

    return double_list_remove(node);
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if (!double_list_empty(obj->head)) {
        return -1;
    }

    if (!((--obj->size) % 2)) {
        obj->ptr_mid = obj->ptr_mid->prev;
    }

    return double_list_pop_back(obj->head);
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    double_list_free(obj->head);
    free(obj);
}

/**
 * Your FrontMiddleBackQueue struct will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = frontMiddleBackQueueCreate();
 * frontMiddleBackQueuePushFront(obj, val);

 * frontMiddleBackQueuePushMiddle(obj, val);

 * frontMiddleBackQueuePushBack(obj, val);

 * int param_4 = frontMiddleBackQueuePopFront(obj);

 * int param_5 = frontMiddleBackQueuePopMiddle(obj);

 * int param_6 = frontMiddleBackQueuePopBack(obj);

 * frontMiddleBackQueueFree(obj);
*/

#ifdef __LOCAL__
int main()
{
    FrontMiddleBackQueue *obj = frontMiddleBackQueueCreate();
    printf("%d\n", frontMiddleBackQueuePopFront(obj));
    printf("%d\n", frontMiddleBackQueuePopMiddle(obj));
    printf("%d\n", frontMiddleBackQueuePopBack(obj));
    frontMiddleBackQueuePushFront(obj, 1);  // 1
    frontMiddleBackQueuePushBack(obj, 2);   // 1->2
    frontMiddleBackQueuePushMiddle(obj, 3); // 1->3->2
    frontMiddleBackQueuePushMiddle(obj, 4); // 1->4->3->2
    printf("%d\n", frontMiddleBackQueuePopFront(obj));  // 1
    printf("%d\n", frontMiddleBackQueuePopMiddle(obj)); // 3
    printf("%d\n", frontMiddleBackQueuePopMiddle(obj)); // 4
    printf("%d\n", frontMiddleBackQueuePopBack(obj));   // 2
    printf("%d\n", frontMiddleBackQueuePopFront(obj));  // -1
    frontMiddleBackQueueFree(obj);

    return 0;
}
#endif