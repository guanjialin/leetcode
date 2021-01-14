//
// Created by addzero on 2020/12/30.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());

        while (heap.size() > 1) {
            int y = heap.top(); heap.pop();
            int x = heap.top(); heap.pop();
            if (x != y) {
                heap.push(y - x);
            }
        }

        return heap.empty() ? 0 : heap.top();
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << Solution().lastStoneWeight(stones) << endl;

    return 0;
}

#endif