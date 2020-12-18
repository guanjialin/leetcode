//
// Created by addzero on 2020/12/18.
//


#ifdef __LOCAL__

#include "header.h"

#endif

#ifdef __REVERSE__
// 两次旋转的做法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = nums.size() - k % nums.size();
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};
#else
// 环状替换做法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int count = 0;

        for (int i = 0; count < nums.size(); ++i) {
            int cur = i;
            int next;
            int cur_val = nums[cur];
            do {
                next = (cur + k) % nums.size();
                int next_val = nums[next];

                nums[next] = cur_val;
                cur = next;
                cur_val = next_val;
                ++count;
            } while (next != i);
        }
    }
};
#endif

#ifdef __LOCAL__

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution().rotate(nums, 3);
    vector_print(nums);

    return 0;
}

#endif