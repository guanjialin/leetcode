//
// Created by dell on 2020/11/1.
//

#include "cppheader.h"

#ifdef __DFS__
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for (const auto& word : wordDict) {
            set_dict.insert(word);
        }

        mem.resize(s.size() + 1);

        return dfs(s);
    }

private:
    bool dfs(const string &s) {
        if (s.empty()) {
            return true;
        }

        if (mem[s.size()]) {
            return false;
        }

        for (int i = 1; i <= s.size(); ++i) {
            if (set_dict.find(s.substr(0, i)) != set_dict.end()) {
                if (dfs(s.substr(i))) {
                    return true;
                }
            }
        }

        mem[s.size()] = true;
        return false;
    }

private:
    vector<bool> mem;
    unordered_set<string> set_dict;
};
#else
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set_dict;
        for (const auto& word : wordDict) {
            set_dict.insert(word);
        }

        vector<bool> dp = vector<bool>(s.size() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && set_dict.find(s.substr(j, i - j)) != set_dict.end()) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size()];
    }
};
#endif

int main()
{
    vector<string> wordDict = {"leet", "code"};
    cout << Solution().wordBreak("leetcode", wordDict) << endl;

    vector<string> wordDict1 = {"cats", "dog", "sand", "and", "cat"};
    cout << Solution().wordBreak("catsandog", wordDict1) << endl;

    return 0;
}