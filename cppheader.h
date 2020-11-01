//
// Created by dell on 2020/10/20.
//

#ifndef LEETCODE_CPPHEADER_H
#define LEETCODE_CPPHEADER_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::stack;
using std::string;
using std::pair;
using std::cout;
using std::cin;
using std::endl;

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

    static ListNode *create(vector<int> data);
};

ListNode * ListNode::create(vector<int> data) {
    struct ListNode *p = nullptr;

    for (auto iter = data.rbegin(); iter != data.rend(); ++iter) {
        auto *node = new ListNode(*iter);
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

#define __DEBUG__
template <typename T>
void DEBUG(T val) {
#ifdef __DEBUG__
    cout << "DEBUG: " << val << endl;
#endif
}

#endif //LEETCODE_CPPHEADER_H