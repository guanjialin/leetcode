//
// Created by addzero on 2021/4/23.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, std::greater<>> pq;

        for (int i = 1; i < heights.size(); ++i) {
            int height = heights[i] - heights[i - 1];
            if (height > 0) {
                pq.push(height);

                if (pq.size() == ladders + 1) {
                    auto min_height = pq.top(); pq.pop();
                    if (bricks >= min_height) {
                        bricks -= min_height;
                    } else {
                        return i - 1;
                    }
                }
            }
        }

        return heights.size() - 1;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> heights = {4,2,7,6,9,14,12};
    cout << Solution().furthestBuilding(heights, 5, 1) << endl;

    return 0;
}

#endif