//
// Created by addzero on 2020/12/31.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> temp;
        temp.push(root);
        while (!temp.empty()) {
            auto node = temp.front();
            temp.pop();
            if (node->left) {
                temp.push(node->left);
                if (node->right) {
                    temp.push(node->right);
                }
            }
            if (!node->right) {
                leaves.push_back(node);
            }
        }
        this->root = root;
    }

    int insert(int v) {
        auto node = new TreeNode(v);
        auto front = leaves.front();
        if (!front->left) {
            front->left = node;
        } else {
            front->right = node;
            leaves.pop_front();
        }
        leaves.push_back(node);
        return front->val;
    }

    TreeNode* get_root() {
        return root;
    }

private:
    TreeNode *root;
    list<TreeNode *> leaves;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif