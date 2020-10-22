//
// Created by dell on 2020/10/20.
//

#ifndef LEETCODE_CPPHEADER_H
#define LEETCODE_CPPHEADER_H


#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
    void print();
    int length();

    static ListNode *create(const int *data, int len);
};

ListNode * ListNode::create(const int *data, int len) {
    if (!data || !len) {
        return nullptr;
    }

    struct ListNode *p = nullptr;
    for (int i = len - 1; i >=0; --i) {
        auto *node = new ListNode(data[i]);
        node->next = p;
        p = node;
    }

    return p;
}

int ListNode::length() {
    int ans = 0;
    struct ListNode *root = this;

    while (root) {
        ++ans;
        root = root->next;
    }

    return ans;
}

// 方便 leetcode 使用
int ListNodeLength(ListNode *root)
{
    int ans = 0;

    while (root) {
        ++ans;
        root = root->next;
    }

    return ans;
}

void ListNode::print()
{
    ListNode *list = this;
    std::cout << "[";
    while (list) {
        std::cout << list->val << '\t';
        list = list->next;
    }
    std::cout << "]" << std::endl;
}

#endif //LEETCODE_CPPHEADER_H