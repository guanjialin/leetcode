//
// Created by addzero on 2020/11/23.
//


#include "header/cppheader.h"


class Solution {
public:
    int numSplits(string s) {
        int prefix[s.size()];
        int suffix[s.size()];
        unordered_set<char> set_prefix;
        unordered_set<char> set_suffix;

        for (int i = 0; i < s.size(); ++i) {
            set_prefix.insert(s[i]);
            prefix[i] = set_prefix.size();
            set_suffix.insert(s[s.size() - 1 - i]);
            suffix[s.size() - 1 - i] = set_suffix.size();
        }

        int ans = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (prefix[i] == suffix[i + 1]) {
                ++ans;
            }
        }

        return ans;
    }
};


int main() {
    cout << Solution().numSplits("aacaba") << endl;
    cout << Solution().numSplits("abcd") << endl;
    cout << Solution().numSplits("aaaaa") << endl;
    cout << Solution().numSplits("acbadbaada") << endl;

    return 0;
}