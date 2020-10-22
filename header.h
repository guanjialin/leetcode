//
// Created by dell on 2020/10/20.
//

#ifndef LEETCODE_HEADER_H
#define LEETCODE_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef enum {
    false,
    true
} bool;

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *ListCreate(int *data, int len)
{
    if (!data || !len) {
        return NULL;
    }

    struct ListNode *p = NULL;
    for (int i = len - 1; i >=0; --i) {
        struct ListNode *node = (struct ListNode *) calloc(1, sizeof(struct ListNode));
        node->val = data[i];
        node->next = p;
        p = node;
    }

    return p;
}

void ListPrint(const struct ListNode *list)
{
    printf("[");
    while (list) {
        printf("%d\t", list->val);
        list = list->next;
    }
    printf("]\n");
}

#define array_print(array, size, fmt) \
{ printf("["); for (int i = 0; i < size; ++i) printf(fmt, array[i]); printf("]\n"); }
#define array_int_print(array, size) array_print(array, size, "%d\t")

#endif //LEETCODE_HEADER_H
