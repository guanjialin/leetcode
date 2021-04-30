//
// Created by addzero on 2021/4/30.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int cntB[26] = {0};
        for (const auto &word : B) {
            int cnt[26] = {0};
            for (auto c : word) {
                auto idx = c - 'a';
                cntB[idx] = max(cntB[idx], ++cnt[idx]);
            }
        }

        vector<string> ans;
        for (const auto &word : A) {
            int cnt[26] = {0};
            for (auto c : word) {
                ++cnt[c - 'a'];
            }

            if (!check(cnt, cntB)) {
                continue;
            }
            ans.emplace_back(word);
        }

        return ans;
    }

private:
    static bool check(const int cntA[26], const int cntB[26]) {
        for (int i = 0; i < 26; ++i) {
            if (cntA[i] < cntB[i]) return false;
        }

        return true;
    }
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif