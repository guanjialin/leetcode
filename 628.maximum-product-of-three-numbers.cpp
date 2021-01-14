//
// Created by addzero on 2021/1/5.
//


#ifdef __LOCAL__

#include "header.h"

#endif

#if 0
// 排序，时间复杂度O(logN) 空间复杂度O(logN)，不是最佳解法
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return std::max(nums[0] * nums[1] * nums[nums.size() - 1],
                        nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }
};
#else
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (auto num : nums) {
            if (num > max1) {
                max3 = max2; max2 = max1; max1 = num;
            } else if (num > max2) {
                max3 = max2; max2 = num;
            } else if (num > max3) {
                max3 = num;
            }

            if (num < min1) {
                min2 = min1; min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
#endif

#ifdef __LOCAL__

int main() {
    vector<int> nums = {-10,-1,0,1,2,3,4};
    cout << Solution().maximumProduct(nums) << endl;

    return 0;
}

#endif