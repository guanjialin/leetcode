//
// Created by addzero on 2020/12/10.
//


#ifdef __LOCAL__

#include "header.h"

#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode* root) {
    if (!root) return 0;

    int ans = 0;
    if (root->left && !root->left->left && !root->left->right) {
        ans += root->left->val;
    }

    ans += sumOfLeftLeaves(root->left);
    ans += sumOfLeftLeaves(root->right);

    return ans;
}

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif