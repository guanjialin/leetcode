//
// Created by addzero on 2021/4/20.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		for (auto num : to_delete) {
			exist.insert(num);
		}

		auto ret = dfs(root);
		if (ret) {
		    ans.push_back(ret);
		}
		return ans;
    }

private:
	TreeNode *dfs(TreeNode *root) {
		if (!root) {
			return nullptr;
		}

		root->left = dfs(root->left);
		root->right = dfs(root->right);

		if (exist.count(root->val)) {
            if (root->left) {
                ans.push_back(root->left);
            }

            if (root->right) {
                ans.push_back(root->right);
            }

            root = nullptr;
		}

        return root;
	}

private:
    unordered_set<int> exist;
	vector<TreeNode *> ans;
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif