//
// Created by addzero on 2020/11/28.
//

#include <iostream>
#include <queue>
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#ifdef __BFS__
// 空间复杂度为 O(N)
class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *prev = NULL;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node *cur = q.front();
                q.pop();
                if (cur) {
                    cur->next = prev;
                    prev = cur;
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }

        return root;
    }
};
#else
class Solution {
public:
    Node *connect(Node *root) {
        if (!root) {
            return root;
        }
        Node *start = root;

        while (start) {
            Node *head = start;
            Node *next = nullptr;
            Node *prev = nullptr;

            for (Node *cur = start; cur != nullptr; cur = cur->next) {
                if (cur->left) {
                    helper(prev, cur->left, next);
                }
                if (cur->right) {
                    helper(prev, cur->right, next);
                }
            }
            start = next;
        }

        return root;
    }

private:
    void helper(Node *&prev, Node *cur, Node *&next) {
        if (prev) {
            prev->next = cur;
        }
        if (!next) {
            next = cur;
        }
        prev = cur;
    }
};
#endif

int main() {
    Node n1, n2, n3;
    n1.val = 1; n2.val = 2, n3.val = 3;
    n1.left = &n2; n1.right = &n3;
    n2.left = n2.right = n3.left = n3.right = nullptr;
    Solution().connect(&n1);

    return 0;
}