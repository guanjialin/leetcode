//
// Created by dell on 2020/10/20.
//

#ifndef LEETCODE_CPPHEADER_H
#define LEETCODE_CPPHEADER_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <climits>
#include <cstring>
#include <numeric>

using std::map;
using std::set;
using std::multiset;
using std::unordered_map;
using std::unordered_set;
using std::unordered_multimap;
using std::unordered_multiset;
using std::vector;
using std::stack;
using std::queue;
using std::deque;
using std::list;
using std::bitset;
using std::priority_queue;
using std::string;
using std::pair;
using std::cout;
using std::cin;
using std::endl;
using std::min;
using std::max;

// Definition for a Node.
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = nullptr;
//        random = nullptr;
//    }
//};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
    void print();
    int length();

    static ListNode *create(vector<int> data);
};

// 双向队列
template <typename T>
struct DoubleListNode {
    T val;
    DoubleListNode *next = nullptr, *prev = nullptr;
    DoubleListNode() {};
    DoubleListNode(T _val) : val(_val) {};

    DoubleListNode<T> *InsertAfter(const T &_val);
    DoubleListNode<T> *InsertBefore(const T &_val);
//    DoubleListNode<T> PushFront(const T &_val);
//    DoubleListNode<T> PushBack(const T &_val);
//    T Remove(const DoubleListNode<T> *pos);
    T Remove();
//    DoubleListNode<T> PopFront();
//    DoubleListNode<T> PopBack();
    bool Empty();
};

// 带头结点的双向循环队列
template<typename T>
DoubleListNode<T> *DoubleListNode<T>::InsertAfter(const T &_val) {
    auto node = new DoubleListNode<T>(_val);
    node->next = this->next;
    node->prev = this;
    this->next = node;
    node->next->prev = node;

    return node;
}

template<typename T>
DoubleListNode<T> *DoubleListNode<T>::InsertBefore(const T &_val) {
    auto node = new DoubleListNode<T>(_val);
    node->prev = this->prev;
    node->next = this;
    node->prev->next = node;
    this->prev = node;

    return node;
}

//template<typename T>
//DoubleListNode<T> DoubleListNode<T>::PushFront(const T &_val) {
//    return DoubleListNode<T>();
//}

//template<typename T>
//DoubleListNode<T> DoubleListNode<T>::PushBack(const T &_val) {
//    return DoubleListNode<T>();
//}

//template<typename T>
//T DoubleListNode<T>::Remove(const DoubleListNode<T> *pos) {
//    pos->prev->next = pos->next;
//    pos->next->prev = pos->prev;
//    T ans = pos->val;
//    delete(pos);
//
//    return val;
//}
template<typename T>
T DoubleListNode<T>::Remove() {
    this->prev->next = this->next;
    this->next->prev = this->prev;

    T ans = this->val;
    delete this;

    return ans;
}

template<typename T>
bool DoubleListNode<T>::Empty() {
    return this->next == this;
}

//template<typename T>
//DoubleListNode<T> DoubleListNode<T>::PopFront() {
//    return DoubleListNode<T>();
//}
//
//template<typename T>
//DoubleListNode<T> DoubleListNode<T>::PopBack() {
//    return DoubleListNode<T>();
//}

// end of 带头结点双向循环队列


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

template <typename T>
void vector_print(vector<T> vec) {
    for (auto val : vec) {
        cout << val << '\t';
    }
    cout << endl;
}

#define __DEBUG__
template <typename T>
void DEBUG(T val) {
#ifdef __DEBUG__
    cout << "DEBUG: " << val << endl;
#endif
}

#endif //LEETCODE_CPPHEADER_H