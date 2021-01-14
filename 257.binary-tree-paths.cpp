//
// Created by addzero on 2020/12/16.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");

        return ans;
    }

private:
    void dfs(TreeNode *root, string prev) {
        if (!root) {
            return;
        }

        prev += (prev.empty() ? "" : "->") + std::to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(prev);
        } else {
            dfs(root->left, prev);
            dfs(root->right, prev);
        }
    }

private:
    vector<string> ans;
};

#ifdef __LOCAL__
int main()
{

    
    return 0;
}
#endif