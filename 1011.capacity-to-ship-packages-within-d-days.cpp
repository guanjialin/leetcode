//
// Created by addzero on 2021/4/28.
//

/*
 * 这道题需要慎重考虑 left 和 right 的取值
 */

#ifdef __LOCAL__
#include "header.h"
#endif

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *std::max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(),  weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(weights, D, mid)) {
                right = mid;    // 满足的情况，mid可能是解，故要留下
            } else {
                left = mid + 1; // 不满足的情况，mid一定不是解，故需要跳过
            }
        }

        return right;
    }

private:
    static bool check(const vector<int> &weights, int D, int sum) {
        int cur = 0;

        for (auto weight : weights) {
            if ((cur += weight) > sum) {
                cur = weight;
                if (--D < 0) return false;  // 剪枝
            }
        }

        return D > 0;
    }
};

#ifdef __LOCAL__
int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    cout << Solution().shipWithinDays(weights, 5) << endl;
    
    return 0;
}
#endif