//
// Created by addzero on 2020/12/23.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int>> temp(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            temp[i] = {i, nums[i]};
        }

        std::sort(temp.begin(), temp.end(), [](pair<int, int> x, pair<int, int> y){
            return x.second > y.second;
        });

        vector<string> ans(nums.size());
        if (temp.size() > 0) ans[temp[0].first] = "Gold Medal";
        if (temp.size() > 1) ans[temp[1].first] = "Silver Medal";
        if (temp.size() > 2) ans[temp[2].first] = "Bronze Medal";
        for (int i = 3; i < nums.size(); ++i) {
            ans[temp[i].first] = std::to_string(i + 1);
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    vector_print(Solution().findRelativeRanks(nums));

    return 0;
}

#endif