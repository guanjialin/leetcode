//
// Created by dell on 2020/10/24.
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
    int numComponents(ListNode* head, vector<int>& G) {
        int ans = 0;
        int flag = false;
        unordered_set<int> unset;

        for (auto g : G) {
            unset.insert(g);
        }

        while (head) {
            if (unset.find(head->val) != unset.end()) {
                flag = true;
            } else {
                ans += flag ? 1 : 0;
                flag = false;
            }
            head = head->next;
        }

        return flag ? ans + 1 : ans;
    }
};

int main()
{
    vector<int> data = {0, 1, 2, 3};
    vector<int> G = {0, 1, 3};
    cout << Solution().numComponents(ListNode::create(data), G) << endl;

    return 0;
}