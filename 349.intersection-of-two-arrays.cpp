//
// Created by dell on 2020/11/2.
//

#include "header/cppheader.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> set_existing;

        for (auto num : nums1) {
            set_existing.insert(num);
        }

        for (auto num : nums2) {
            if (set_existing.find(num) != set_existing.end()) {
                ans.push_back(num);
                set_existing.erase(num);
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {2, 2};
    vector_print(Solution().intersection(nums1, nums2));

    return 0;
}