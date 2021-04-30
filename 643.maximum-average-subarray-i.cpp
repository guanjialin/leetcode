//
// Created by addzero on 2021/4/30.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = std::accumulate(nums.begin(), nums.begin() + k, 0);
        int cur = ans;

        for (int i = k; i < nums.size(); ++i) {
            cur = cur + nums[i] - nums[i - k];
            ans = max(cur, ans);
        }

        return (double)ans / k;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    cout << Solution().findMaxAverage(nums, 4) << endl;

    return 0;
}

#endif