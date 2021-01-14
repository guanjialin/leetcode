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
    vector<int> nextLargerNodes(ListNode* head) {
        int cnt = 0;
        stack<pair<int, int>> sp;
        vector<int> ans = vector<int>(ListNodeLength(head));

        while (head) {
            while (!sp.empty() && head->val > sp.top().second) {
                auto p = sp.top();
                sp.pop();
                ans[p.first] = head->val;
            }

            sp.push(pair<int, int>(cnt++, head->val));

            head = head->next;
        }

        return ans;
    }
};

int main()
{
    auto ans = Solution().nextLargerNodes(ListNode::create(vector<int>{2, 1, 5}));
    for (auto val : ans) {
        cout << val << '\t';
    }
    cout << endl;

    return 0;
}