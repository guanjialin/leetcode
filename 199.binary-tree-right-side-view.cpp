//
// Created by addzero on 2020/11/28.
//


#include "cppheader.h"

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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (root && !q.empty()) {
            int size = q.size();
            ans.push_back(q.front()->val);
            for (int i = 0; i < size; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->right) {
                    q.push(cur->right);
                }
                if (cur->left) {
                    q.push(cur->left);
                }
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}