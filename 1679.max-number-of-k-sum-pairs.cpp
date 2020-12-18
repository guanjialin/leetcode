//
// Created by addzero on 2020/12/18.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class Solution {
public:
    // 双指针 + sort 解法，时间复杂度O(NlogN)，空间复杂度O(logN)
#if 0
    int maxOperations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1, ans = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < k) {
                ++left;
            } else if (sum > k) {
                --right;
            } else {
                ++ans;
                ++left;
                --right;
            }
        }

        return ans;
    }
#else
    // hash_map 解法，时间复杂度O(N)空间复杂度O(N)
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> map_record;

        for (const auto &num : nums) {
            ++map_record[num];
            if (map_record.count(k - num)) {
                int add = k - num == num
                        ? map_record[num] / 2 : std::min(map_record[num], map_record[k - num]);
                ans += add;
                map_record[num] -= add;
                map_record[k - num] -= add;
            }
        }

        return  ans;
    }
#endif
};

#ifdef __LOCAL__
int main()
{
    vector<int> nums = {1,2,3,4,5};
    cout << Solution().maxOperations(nums, 6) << endl;

    return 0;
}
#endif