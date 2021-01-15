//
// Created by addzero on 2021/1/15.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;

        for (const auto &account : accounts) {
            ans = std::max(std::accumulate(account.begin(), account.end(), 0), ans);
        }

        return ans;
    }
};

#ifdef __LOCAL__
int main()
{

    
    return 0;
}
#endif