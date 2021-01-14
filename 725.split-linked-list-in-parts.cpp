//
// Created by dell on 2020/10/21.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "header/cppheader.h"

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = ListNodeLength(root);
        int size = len / k; // 每段最小长度
        int remainder = len % k;    // 有多少段需要+1
        vector<ListNode *> ans = vector<ListNode *>(k);

        int iter = 0;
        int realk = len < k ? len : k;
        for (int i = 0; i < realk; ++i) {
            ans[i] = root;

            iter = i < remainder ? size : size - 1;
            for (int j = 0; j < iter; ++j) {
                root = root->next;
            }

            ListNode *temp = root->next;
            root->next = nullptr;
            root = temp;
        }

        return ans;
    }
};

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto list = ListNode::create(data, sizeof(data) / sizeof(int));
    auto ans = Solution().splitListToParts(list, 3);

    for (auto sub_list : ans) {
        sub_list->print();
    }

    return 0;
}