//
// Created by addzero on 2021/1/13.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif