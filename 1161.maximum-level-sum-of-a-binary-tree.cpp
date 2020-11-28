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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        int cur_level = 1;
        int max_sum = INT_MIN;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int sum = 0;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            if (sum > max_sum) {
                max_sum= sum;
                ans = cur_level;
            }
            ++cur_level;
        }

        return ans;
    }
};

int main() {


    return 0;
}