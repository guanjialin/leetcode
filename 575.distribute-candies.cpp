//
// Created by addzero on 2020/11/26.
//


#include "cppheader.h"

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return std::min(candyType.size() / 2,
                        unordered_set<int>(candyType.begin(), candyType.end()).size());
    }
};

int main() {
    vector<int> candies = {1,1,2,2,3,3};
    cout << Solution().distributeCandies(candies) << endl;

    return 0;
}