//
// Created by addzero on 2020/11/25.
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
class FindElements {
public:
    FindElements(TreeNode* root) {
        build(root, 0);
    }

    // 用位运算可将空间复杂度降低到 O(1)
    // 因为最后构建出来的树应该是一棵类似完全二叉树
    // 故每一层节点值范围应为为 2^h ~ 2^(h+1) - 1
    // 对应的二进制位应该为 h+1 位，其中最高位为 1 不要，0表示左子树，1表示右子树，
    // 则只需要logN。
    bool find(int target) {
        return set_node.find(target) != set_node.end();
    }

private:
    void build(TreeNode *root, int val)
    {
        if (nullptr == root) {
            return;
        }

        root->val = val;
        set_node.insert(val);
        build(root->left, 2 * val + 1);
        build(root->right, 2 * val + 2);
    }

private:
    unordered_set<int> set_node;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {


    return 0;
}