//
// Created by addzero on 2021/5/5.
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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }

private:
    string dfs(TreeNode *root, string cur) {
        if (!root) return "";

        cur += ('a' + root->val);
        if (!root->left && !root->right) {
            std::reverse(cur.begin(), cur.end());
            return cur;
        }

        auto left = dfs(root->left, cur);
        auto right = dfs(root->right, cur);
        if (left.empty()) return right;
        else if (right.empty()) return left;

        return std::min(left, right);
    }
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif