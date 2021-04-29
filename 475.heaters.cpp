//
// Created by addzero on 2021/4/29.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());

        int left = 0, right = max(houses.back(), heaters.back());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(houses, heaters, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

private:
    static bool check(const vector<int> &houses, const vector<int> &heaters, int dist) {
        int i = 0, j = 0;
        while (i < houses.size() && j < heaters.size()) {
            if (abs(houses[i] - heaters[j]) <= dist) {
                ++i;
            } else {
                ++j;
            }
        }

        return i >= houses.size();
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> houses = {1, 2, 3};
    vector<int> heaters = {2};
    cout << Solution().findRadius(houses, heaters) << endl;


    return 0;
}

#endif