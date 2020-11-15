//
// Created by addzero on 2020/11/15.
//


#include "cppheader.h"

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map_cnt;

        for (auto num : nums) {
            ++map_cnt[num];
        }

        std::sort(nums.begin(), nums.end(), [&map_cnt](int x, int y) -> bool {
            return map_cnt[x] == map_cnt[y] ? x > y : map_cnt[x] < map_cnt[y];
        });

        return nums;
    }
};

int main() {
    vector<int> nums = {1,1,2,2,2,3};
    Solution().frequencySort(nums);
    for (const auto &num : nums) {
        cout << num << '\t';
    }

    return 0;
}