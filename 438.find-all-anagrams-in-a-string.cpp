//
// Created by addzero on 2020/11/22.
//


#include "cppheader.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        int left = 0;
        int right = 0;
        vector<int> ans;
        int need[26] = {0};
        int window[26] = {0};

        for (auto c : p) {
            ++need[c - 'a'];
        }

        while (right < s.size()) {
            int cur = s[right++] - 'a';
            ++window[cur];

            while (window[cur] > need[cur]) {
                --window[s[left++] - 'a'];
            }

            if (right - left == p.size()) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};

int main() {
    auto ans = Solution().findAnagrams("ababababab", "aab");
    vector_print(ans);

    return 0;
}