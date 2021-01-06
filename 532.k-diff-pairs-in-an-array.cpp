//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> num_count;

        for (auto num : nums) {
            ++num_count[num];
        }

        for (auto it = num_count.begin(); it != num_count.end();) {
            if (!k) {
                ans += (it++)->second >= 2 ? 1 : 0;
            } else {
                ans += num_count.count(it->first + k) ? 1 : 0;
                ans += num_count.count(it->first - k) ? 1 : 0;
                num_count.erase(it++);
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    cout << Solution().findPairs(nums, 2) << endl;

    return 0;
}

#endif