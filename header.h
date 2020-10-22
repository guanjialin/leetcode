//
// Created by dell on 2020/10/20.
//

#ifndef LEETCODE_HEADER_H
#define LEETCODE_HEADER_H

#include <stdio.h>
#include <stdlib.h>

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

#endif //LEETCODE_HEADER_H
