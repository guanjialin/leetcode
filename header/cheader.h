//
// Created by addzero on 2020/12/7.
//

#ifndef LEETCODE_CHEADER_H
#define LEETCODE_CHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include "uthash/uthash.h"


typedef enum {
    false = 0,
    true = 1,
} bool;

struct ListNode {
    int val;
    struct ListNode *next;
};
#define list_node ListNode

struct DoubleListNode {
    int val;
    struct DoubleListNode *next, *prev;
};
#define double_list_node DoubleListNode

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#define list_create_from_int_array(data) ListCreate(data, array_int_len(data))
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

#define list_print(head) ListPrint(head)
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
#define array_str_print(array, size) array_print(array, size, "%s\t")

#define array_len(array, type) (sizeof(array) / sizeof(type))
#define array_int_len(array) array_len(array, int)

void array_int_swap(int data[], int index1, int index2) {
    int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}

#endif //LEETCODE_CHEADER_H