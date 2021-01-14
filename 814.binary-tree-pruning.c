//
// Created by addzero on 2020/12/2.
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


struct TreeNode* pruneTree(struct TreeNode* root){
    if (!root) {
        return root;
    }

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    if (root->val || root->left || root->right) {
        return root;
    }

    return NULL;
}

int main() {


    return 0;
}