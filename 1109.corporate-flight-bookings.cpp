//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n + 1);

        for (auto booking : bookings) {
            ans[booking[0] - 1] += booking[2];
            ans[booking[1]] -= booking[2];
        }

        for (int i = 1; i < n; ++i) {
            ans[i] += ans[i - 1];
        }

        ans.resize(n);
        return ans;
    }
};

#ifdef __LOCAL__
int main()
{
    vector<vector<int>> bookings = {
            {1, 2, 10}, {2, 3, 20}, {2, 5, 25},
    };
    vector_print(Solution().corpFlightBookings(bookings, 5));

    return 0;
}
#endif