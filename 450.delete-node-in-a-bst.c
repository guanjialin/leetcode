//
// Created by addzero on 2020/11/18.
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


static int successor(struct TreeNode *root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root->val;
}

static int predecessor(struct TreeNode *root) {
    while (root->right != NULL) {
        root = root->right;
    }

    return root->val;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if (NULL == root) {
        return root;
    }

    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (NULL == root->left && NULL == root->right) {
            return NULL;
        } else if (root->right != NULL) {
            root->val = successor(root->right);
            root->right = deleteNode(root->right, root->val);
        } else {
            root->val = predecessor(root->left);
            root->left = deleteNode(root->left, root->val);
        }
    }

    return root;
}

int main() {
    struct TreeNode node0, node1, node2, node3, node4, node5;
    node0.val = 5; node1.val = 3; node2.val = 6;
    node3.val = 2; node4.val = 4; node5.val = 7;
    node0.left = &node1; node0.right = &node2;
    node1.left = &node3; node1.right = &node4;
    node2.left = NULL; node2.right = &node5;
    node3.left = node3.right = node4.left = node4.right = node5.left = node5.right = NULL;

    struct TreeNode *ans = deleteNode(&node0, 3);

    return 0;
}