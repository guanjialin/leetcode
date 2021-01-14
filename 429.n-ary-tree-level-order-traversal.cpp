//
// Created by addzero on 2021/1/11.
//


#ifdef __LOCAL__

#include "header.h"

#endif

#ifdef __LOCAL__
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
#endif

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        if (!root) {
            return ans;
        }

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                auto node = q.front(); q.pop();
                level.emplace_back(node->val);

                for (auto child : node->children) {
                    if (child) {
                        q.push(child);
                    }
                }
            }
            ans.emplace_back(level);
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif