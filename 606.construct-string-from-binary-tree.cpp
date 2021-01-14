//
// Created by addzero on 2021/1/3.
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
#if 0
class Solution {
public:
    string tree2str(TreeNode* t) {
        string s;
        dfs(t, s);

        return s.size() <= 2 ? s : s.substr(1, s.size() - 2);
    }

private:
    void dfs(TreeNode *root, string &ans) {
        if (!root) {
            return;
        }
        ans += '(' + std::to_string(root->val);
        if (!root->left && root->right) {
            ans += "()";
        } else {
            dfs(root->left, ans);
        }
        dfs(root->right, ans);
        ans += ')';
    }
};
#else
// 答案的解法更简练
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) {
            return "";
        } else if (!t->left && !t->right) {
            return std::to_string(t->val);
        } else if (!t->right) {
            return std::to_string(t->val) + "(" + tree2str(t->left) + ")";
        }
        return std::to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
};
#endif

#ifdef __LOCAL__
int main()
{
    
    return 0;
}
#endif