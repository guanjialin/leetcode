//
// Created by addzero on 2021/1/14.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = words.size();
        bitset<26> base;

        for (const auto &c : allowed) {
            base.set(c - 'a');
        }

        for (const auto &word : words) {
            for (const auto &c : word) {
                if (!base.test(c - 'a')) {
                    --ans;
                    break;
                }
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<string> words = {"ad","bd","aaab","baa","badab"};
    cout << Solution().countConsistentStrings("ab", words) << endl;

    return 0;
}

#endif