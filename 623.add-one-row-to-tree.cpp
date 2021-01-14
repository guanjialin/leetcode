//
// Created by addzero on 2021/1/8.
//


#ifdef __LOCAL__

#include "header.h"

#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (1 == d) {
            auto node = new TreeNode(v);
            node->left = root;
            return node;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (--d > 1 && !q.empty()) {
            auto size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        while (!q.empty()) {
            auto node = q.front(); q.pop();
            auto left = new TreeNode(v);
            auto right = new TreeNode(v);
            left->left = node->left;
            right->right = node->right;
            node->left = left;
            node->right = right;
        }

        return root;
    }
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif