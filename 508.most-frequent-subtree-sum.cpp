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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

private:
    int dfs(TreeNode *root) {
        if (!root) return 0;

        int sum = root->val + dfs(root->left) + dfs(root->right);
        if (++cnt[sum] >= cur_max) {
            if (cnt[sum] > cur_max) {
                ans.clear();
                cur_max = cnt[sum];
            }
            ans.push_back(sum);
        }

        return sum;
    }

private:
    unordered_map<int, int> cnt;
    vector<int> ans;
    int cur_max = 0;
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif