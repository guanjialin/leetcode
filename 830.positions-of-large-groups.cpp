//
// Created by addzero on 2021/1/5.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int begin = 0;
        for (int i = 1; i <= s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                if (i - begin >= 3) {
                    ans.push_back({begin, i - 1});
                }
                begin = i;
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__
int main()
{
    string s = "abbxxxxzzy";
    auto ans = Solution().largeGroupPositions(s);
    for (auto item : ans) {
        vector_print(item);
    }
    
    return 0;
}
#endif