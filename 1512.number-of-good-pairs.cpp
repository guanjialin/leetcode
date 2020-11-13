//
// Created by addzero on 2020/11/13.
//


#include "cppheader.h"

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> map_count;

        for (auto num : nums) {
            ans += ++map_count[num] - 1;
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,3,1,1,3};
    cout << Solution().numIdenticalPairs(nums) << endl;

    return 0;
}