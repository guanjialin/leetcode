//
// Created by dell on 2020/10/23.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "header.h"

#ifdef __QUICK_SORT__
// quick sort, 可能会超时
void list_quick_sort(struct ListNode *left, struct ListNode *right) {
    if (left == right || left->next == right) {
        return;
    }

    struct ListNode *pivot = left->next;
    struct ListNode *pleft = left->next->next;
    pivot->next = right;

    while (pleft != right) {
        struct ListNode *temp = pleft->next;
        if (pleft->val < pivot->val) {
            pleft->next = left->next;
            left->next = pleft;
        } else {
            pleft->next = pivot->next;
            pivot->next = pleft;
        }
        pleft = temp;
    }

    list_quick_sort(left, pivot);
    list_quick_sort(pivot, right);
}

struct ListNode* sortList(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    list_quick_sort(&dummy, NULL);

    return dummy.next;
}
#else
struct ListNode *merge(struct ListNode *left, struct ListNode *right) {
    struct ListNode dummy, *p = &dummy;
    dummy.next = NULL;

    while (left && right) {
        if (left->val < right->val) {
            p->next = left;
            left = left->next;
        } else {
            p->next = right;
            right = right->next;
        }

        p = p->next;
    }

    p->next = left ? left : right;

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode *slow = head, *fast = head;

    // get mid head
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;

    return merge(sortList(head), sortList(fast));
}
#endif

int main()
{
    int data[] = {4, 2, 1, 3};
    struct ListNode *head = list_create_from_int_array(data);
    list_print(sortList(head));

    return 0;
}