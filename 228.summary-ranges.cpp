//
// Created by addzero on 2021/1/9.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int left = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 == nums.size() || nums[i] + 1 != nums[i + 1]) {
                ans.emplace_back(std::to_string(nums[left]) + (left == i ? "" : "->" + std::to_string(nums[i])));
                left = i + 1;
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> data = {0,1,2,4,5,7};
    vector_print(Solution().summaryRanges(data));

    return 0;
}

#endif