//
// Created by addzero on 2021/1/3.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        max_val = N - blacklist.size();
        unordered_set<int> lt, ge;
        for (auto ele : blacklist) {
            if (ele >= max_val) {
                ge.insert(ele);
            } else {
                lt.insert(ele);
            }
        }

        int temp = max_val;
        for (auto ele : lt) {
            while (ge.count(temp)) ++temp;
            black_map[ele] = temp++;
        }
    }

    int pick() {
        int r = random() % max_val;
        return black_map.count(r) ? black_map[r] : r;
    }

private:
    int max_val;
    unordered_map<int, int> black_map;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif