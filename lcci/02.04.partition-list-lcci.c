//
// Created by dell on 2020/10/22.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "header.h"

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode dummyslow, dummyfast;
    dummyfast.next = head;
    dummyslow.next = NULL;
    struct ListNode *slow = &dummyslow, *fast = &dummyfast;

    while (fast->next) {
        if (fast->next->val < x) {
            struct ListNode *temp = fast->next;
            fast->next = fast->next->next;  //
            temp->next = slow->next;
            slow->next = temp;
            slow = slow->next;
        } else {
            fast = fast->next;
        }
    }
    slow->next = dummyfast.next;

    return dummyslow.next;
}

int main()
{
    int data[] = {3, 5, 8, 5, 10, 2, 1};
    struct ListNode *head = ListCreate(data, array_int_len(data));
    ListPrint(partition(head, 5));

    return 0;
}