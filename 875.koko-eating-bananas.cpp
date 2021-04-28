//
// Created by addzero on 2021/4/28.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // left 的最小值应该是 std::ceil(sum / h) ，小于这个值肯定吃不完，没有意义
        // right 的最大值应该是所有堆中最大的值，如果大于这个值，也没有意义
        // 如果用 std::accumulate 和 max_element 需要遍历两次，感觉没必要
        double sum = 0;
        int left = 0, right = 0;
        for (auto pile : piles) {
            right = std::max(right, pile);
            sum += pile;
        }
        left = std::ceil(sum / h);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

private:
    static bool check(const vector<int> &piles, int h, int mid) {
        for (int pile : piles) {
            if ((h -= ceil((double) pile / mid)) < 0) {
                return false;
            }
        }

        return true;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> piles = {3,6,7,11};
    cout << Solution().minEatingSpeed(piles, 8) << endl;

    return 0;
}

#endif