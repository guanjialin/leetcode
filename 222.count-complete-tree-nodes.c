//
// Created by addzero on 2020/11/24.
//


#include "header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// 官方解法确实精辟，根据官方解法改写
static bool exist(struct TreeNode *root, int bit, int k)
{
    while (bit != 0 && root != NULL) {
        if (bit & k) {
            root = root->right;
        } else {
            root = root->left;
        }
        bit >>= 1;
    }

    return root != NULL;
}

int countNodes(struct TreeNode* root) {
    if (NULL == root) {
        return 0;
    }

    // 获取树的最大高度
    int level = 0;
    struct TreeNode *p = root;
    while (p->left) {
        p = p->left;
        ++level;
    }

    int bit = level > 0 ? 1 << (level - 1) : 0;
    int low = 1 << level, high = (1 << (level + 1)) - 1;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (exist(root, bit, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    return low;
}


int main() {
    struct TreeNode node1 = {0}, node2 = {0}, node3 = {0}, node4 = {0}, node5 = {0};
    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    printf("%d\n", countNodes(&node1));

    return 0;
}