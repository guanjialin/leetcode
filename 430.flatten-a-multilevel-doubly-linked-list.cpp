//
// Created by dell on 2020/10/20.
//

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val) : val(_val){};
};


class Solution {
public:
    Node* flatten(Node* head) {
        Node *p = head;

        while (p) {
            if (!p->child) {
                p = p->next;
            } else {
                Node *temp = flatten(p->child);
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = p->next;
                if (p->next) {
                    p->next->prev = temp;
                }
                p->next = p->child;
                p->child->prev = p;
                p->child = nullptr;
                p = temp->next;
            }
        }

        return head;
    }
};


#include <iostream>
#include "header/cppheader.h"

int main()
{
    Node *node1 = new Node(1),
         *node2 = new Node(2),
         *node3 = new Node(3);

    node1->next = node2;
    node2->next = nullptr;
    node2->prev = node1;
    node3->next = nullptr;
    node1->prev = node3->prev = nullptr;

    node1->child = node3;
    node2->child = node3->child = nullptr;

    Node *node = Solution().flatten(node1);
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;

    return 0;
}
