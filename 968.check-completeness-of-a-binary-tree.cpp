//
// Created by addzero on 2021/5/2.
//

/*
 * 官方有更简洁的解法
 */

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        int level = 0;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            bool ok = true;
            bool leaf = size != pow(2, level);
            for (int i = 0; i < size; ++i) {
                auto node = q.front(); q.pop();
                // 叶子节点居然要有孩子
                if (leaf && (node->left || node->right)) return false;
                // 有右孩子，但是居然没有左孩子
                if (node->right && !node->left) return false;
                // 前面出现没有孩子的，后面居然又出现有孩子的
                if (!ok && (node->left || node->right)) return false;
                ok = (node->left && node->right);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ++level;
        }

        return true;
    }
};

#ifdef __LOCAL__

int main() {
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);
    n1.setChild(&n2, &n3);
    n2.setChild(&n4, &n5);
    n3.setChild(&n6);
    cout << Solution().isCompleteTree(&n1) << endl;

    return 0;
}

#endif