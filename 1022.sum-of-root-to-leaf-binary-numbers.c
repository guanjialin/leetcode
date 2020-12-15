//
// Created by addzero on 2020/12/15.
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

void dfs(struct TreeNode *root, int prev, int *ans) {
    if (!root) {
        return;
    }

    prev = prev * 2 + root->val;

    if (!root->left && !root->right) {
        *ans += prev;
        return;
    }

    dfs(root->left, prev, ans);
    dfs(root->right, prev, ans);
}

int sumRootToLeaf(struct TreeNode* root){
    int ans = 0;
    dfs(root, 0, &ans);
    return ans;
}

#ifdef __LOCAL__
int main()
{

    
    return 0;
}
#endif