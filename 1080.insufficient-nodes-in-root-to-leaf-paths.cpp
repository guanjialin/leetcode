//
// Created by addzero on 2021/5/4.
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) return nullptr;

        limit -= root->val;
        if (!root->left && !root->right) {
            // 叶节点，且不足节点
            if (limit > 0) return nullptr;
            return root;
        }

        root->left = sufficientSubset(root->left, limit);
        root->right = sufficientSubset(root->right, limit);

        if (!root->left && !root->right) return nullptr;
        return root;
    }
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif