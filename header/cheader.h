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

// ### 以下 double_list_node 操作都假设带头结点
struct double_list_node *double_list_create()
{
    struct double_list_node *node = (struct double_list_node *) calloc(1, sizeof(struct double_list_node));
    if (node) {
        node->next = node->prev = node;
    }

    return node;
}

// 不能用 obj->next != obj->prev 判空，在只有一个元素的时候有问题
bool double_list_empty(struct double_list_node *obj)
{
    return obj->next != obj;
}

struct double_list_node *double_list_insert_before(struct double_list_node *pos, int val)
{
    struct double_list_node *node = (struct double_list_node *) calloc(1, sizeof(struct double_list_node));
    if (node) {
        node->val = val;
        node->prev = pos->prev;
        node->next = pos;
        node->prev->next = node;
        pos->prev = node;
    }

    return node;
}

struct double_list_node *double_list_insert_after(struct double_list_node *pos, int val)
{
    struct double_list_node *node = (struct double_list_node *) calloc(1, sizeof(struct double_list_node));
    if (node) {
        node->val = val;
        node->next = pos->next;
        node->next->prev = node;
        node->prev = pos;
        pos->next = node;
    }

    return node;
}

struct double_list_node *double_list_push_front(struct double_list_node *head, int val)
{
    return double_list_insert_after(head, val);
}

struct double_list_node *double_list_push_back(struct double_list_node *head, int val)
{
    return double_list_insert_before(head, val);
}

int double_list_remove(struct double_list_node *pos)
{
    int ans = pos->val;
    pos->next->prev = pos->prev;
    pos->prev->next = pos->next;
    free(pos); pos = NULL;

    return ans;
}

int double_list_pop_front(struct double_list_node *head)
{
    return double_list_remove(head->next);
}

int double_list_pop_back(struct double_list_node *head)
{
    return double_list_remove(head->prev);
}

void double_list_free(struct double_list_node *head)
{
    struct double_list_node *node;
    while (double_list_empty(head)) {
        node = head->next;
        head->next = node->next;
        free(node); node = NULL;
    }
    free(head); node = NULL;
}
// ### end double_list_node with head


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct trie_node {
    bool word;
    struct trie_node *next[26];
};


#define trie_node_create() ((struct trie_node *) calloc(1, sizeof(struct trie_node)))
struct trie_node *trie_build(char **words, int size)
{
    struct trie_node *trie = (struct trie_node *) calloc(1, sizeof(struct trie_node));
    struct trie_node *pt = trie;

    for (int i = 0; i < size; ++i) {
        char *p = words[i];

        while (*p != '\0') {
            if (!pt->next[*p - 'a']) {
                pt->next[*p - 'a'] = trie_node_create();
            }
            pt = pt->next[*p - 'a'];
            ++p;
        }
        pt->word = true;
    }

    return trie;
}

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
#define array_int_print_all(array) array_print(array, array_int_len(array), "%d\t")
#define array_str_print(array, size) array_print(array, size, "%s\t")

#define array_len(array, type) (sizeof(array) / sizeof(type))
#define array_int_len(array) array_len(array, int)

void array_int_swap(int data[], int index1, int index2) {
    int temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}

#endif //LEETCODE_CHEADER_H
