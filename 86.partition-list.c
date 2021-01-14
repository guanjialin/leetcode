//
// Created by addzero on 2021/1/3.
//


#ifdef __LOCAL__
#include "header.h"
#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode ge = {0}, *pge = &ge;
    struct ListNode lt = {0}, *plt = &lt;
    plt->next = head;

    while (plt->next != NULL) {
        if (plt->next->val >= x) {
            pge->next = plt->next;
            pge->next = pge->next;
            plt->next = plt->next->next;
            pge = pge->next;
        } else {
            plt = plt->next;
        }
    }
    pge->next = NULL;
    plt->next = ge.next;

    return lt.next;
}

#ifdef __LOCAL__
int main()
{
    int data[] = {1,4,3,2,5,2};
    struct ListNode *list = list_create_from_int_array(data);
    list_print(partition(list, 3));
    
    return 0;
}
#endif