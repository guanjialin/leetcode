//
// Created by addzero on 2021/1/5.
//


#ifdef __LOCAL__
#include "header.h"
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#if 0
int dfs(struct TreeNode *root, int parent)
{
    if (!root) {
        return parent == INT_MIN ? 0 : parent;
    }

    if (!root->left && !root->right) {
        if (parent != INT_MIN) {
            root->val += parent;
        }
        return root->val;
    }

    root->val += dfs(root->right, parent);
    if (root->left) {
        return dfs(root->left, root->val);
    }

    return root->left ? root->left->val : root->val;
}

struct TreeNode* convertBST(struct TreeNode* root){
    dfs(root, INT_MIN);

    return root;
}
#else
// 官方解法，反序中序遍历
void dfs(struct TreeNode *root, int *sum)
{
    if (root) {
        dfs(root->right, sum);
        *sum = root->val + *sum;
        root->val = *sum;
        dfs(root->left, sum);
    }
}
struct TreeNode* convertBST(struct TreeNode* root) {
    int sum = 0;
    dfs(root, &sum);

    return root;
}
#endif

#ifdef __LOCAL__
int main()
{
    struct TreeNode node1 = {0}, node2 = {0}, node3 = {0};
    node1.val = 3, node2.val = 2, node3.val = 4;
    node1.left = &node2; node1.right = &node3;
    convertBST(&node1);
    
    return 0;
}
#endif