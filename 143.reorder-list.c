//
// Created by zero on 2020/10/20.
//

/*
 * 思路：
 *  1. 找到中间节点；
 *  1. 翻转后半部分；
 *  2. 合并前后部分；
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "header.h"

void reorderList(struct ListNode* head){
    if (!head) {
        return;
    }

    struct ListNode *slow = head, *fast = head;

    // 找到中间节点
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 防止翻转的时候最后节点的next不空
    fast = slow->next;
    slow->next = NULL;

    // 翻转后半部分
    while (fast) {
        struct ListNode *temp = fast->next;
        fast->next = slow->next;
        slow->next = fast;
        fast = temp;
    }

    fast = slow->next;
    slow->next = NULL;
    slow = head;

    while (fast) {
        struct ListNode *temp = fast->next;
        fast->next = slow->next;
        slow->next = fast;
        fast = temp;
        slow = slow->next->next;
    }
}

int main()
{
    int data[] = {1, 2, 3, 4, 5};
    struct ListNode *node = ListCreate(data, 5);
    reorderList(node);
    ListPrint(node);

    return 0;
}