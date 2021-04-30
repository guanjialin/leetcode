//
// Created by addzero on 2021/4/30.
//

/*
 * 本题向上取整的方法太值得学了
 * (num - 1) / divisor + 1
 */

#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *std::max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum(nums, mid) <= threshold) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

private:
    static int sum(const vector<int> &nums, int divisor) {
        int ans = 0;

        for (auto num : nums) {
            ans += (num - 1) / divisor + 1; // 向上取整方法太值得学习了
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> nums = {1, 2, 5, 9};
    cout << Solution().smallestDivisor(nums, 6) << endl;

    return 0;
}

#endif