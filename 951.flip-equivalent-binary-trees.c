//
// Created by addzero on 2020/12/9.
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


bool flipEquiv(struct TreeNode* root1, struct TreeNode* root2){
    if (!root1 && !root2) {
        return true;
    } else if (!root1 || !root2 || (root1->val != root2->val)) {
        return false;
    }

    return (flipEquiv(root1->left, root2->right)
            && flipEquiv(root1->right, root2->left))
            || (flipEquiv(root1->left, root2->left)
                && flipEquiv(root1->right, root2->right));
}

#ifdef __LOCAL__

int main() {
    struct TreeNode node11 = {0}, node12 = {0}, node13 = {0}, node14 = {0}, node15 = {0}, node16 = {0};
    struct TreeNode node21 = {0}, node22 = {0}, node23 = {0}, node24 = {0}, node25 = {0}, node26 = {0};
    node11.val = 1; node12.val = 2, node13.val = 3, node14.val = 4, node15.val = 5, node16.val = 6;
    node21.val = 1; node22.val = 2, node23.val = 3, node24.val = 4, node25.val = 5, node26.val = 6;
    node11.left = &node12; node11.right = &node13, node12.left = &node14, node12.right = &node15, node13.left = &node16;
    node21.left = &node23; node21.right = &node22, node22.left = &node24, node22.right = &node25, node23.right = &node26;
    printf("%d\n", flipEquiv(&node11, &node21));

    return 0;
}

#endif