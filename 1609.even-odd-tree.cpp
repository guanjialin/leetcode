//
// Created by addzero on 2020/12/3.
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
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto size = q.size();
            int remain = level++ % 2;
            int base = remain ? 1 : -1;
            int prev = remain ? 1e6 + 1 : 0;

            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur) {
                    // 条件1：
                    //   如果奇数层，remain 为 1，cur->val % 2 为 1 则为奇数，则不符合，false
                    //   如果为偶数层，则刚好相反
                    // 条件2：
                    //   如果奇数层，base 为 1，如果 cur->val 非严格单调递减法，则 prev - cur->val 必 <=0
                    //   从而导致，(prev - cur->val) * base <= 0 成立
                    //   如果是偶数层，则刚好相反
                    if (cur->val % 2 == remain || (prev - cur->val) * base <= 0) {
                        return false;
                    }

                    prev = cur->val;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return true;
    }
};

#ifdef __LOCAL__
int main()
{

    
    return 0;
}
#endif