//
// Created by addzero on 2020/12/4.
//


#ifdef __LOCAL__
#include "cppheader.h"
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }

    int next() {
        TreeNode *cur = stk.top();
        stk.pop();
        helper(cur->right);

        return cur->val;
    }

    bool hasNext() {
        return !stk.empty();
    }

private:
    void helper(TreeNode *root)
    {
        while (root != NULL) {
            stk.push(root);
            root = root->left;
        }
    }

private:
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

#ifdef __LOCAL__
int main()
{

    
    return 0;
}
#endif