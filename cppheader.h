//
// Created by dell on 2020/10/20.
//

#ifndef LEETCODE_CPPHEADER_H
#define LEETCODE_CPPHEADER_H


#include <iostream>
#include <unordered_map>


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

#endif //LEETCODE_CPPHEADER_H
