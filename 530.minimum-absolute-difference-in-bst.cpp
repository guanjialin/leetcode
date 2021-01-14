//
// Created by addzero on 2021/1/6.
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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, pre, ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int &pre, int &ans) {
        if (!root) {
            return;
        }

        dfs(root->left, pre, ans);
        if (pre != -1) {
            ans = min(ans, root->val - pre);
        }
        pre = root->val;
        dfs(root->right, pre, ans);
    }
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif