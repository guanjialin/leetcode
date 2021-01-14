//
// Created by dell on 2020/10/21.
//

#include "header/cppheader.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        auto *dummy = new ListNode(0);
        dummy->next = head;
        std::unordered_map<int, ListNode *> unmap;

        int sum = 0;
        for (auto d = dummy; d != nullptr; d = d->next) {
            sum += d->val;
            unmap[sum] = d;
        }

        sum = 0;
        for (auto d = dummy; d != nullptr; d = d->next) {
            sum += d->val;
            d->next = unmap[sum]->next;
        }

        return dummy->next;
    }
};

int main()
{
    vector<int> data = {1, 2, 3, -3, -2};
    auto ans = Solution().removeZeroSumSublists(ListNode::create(data));
    ans->print();

    return 0;
}