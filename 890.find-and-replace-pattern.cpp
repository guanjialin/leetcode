//
// Created by dell on 2020/10/30.
//

#include "header/cppheader.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for (const auto& word : words) {
            if (match(word, pattern)) {
                ans.push_back(word);
            }
        }

        return ans;
    }

private:
    bool match(string word, string pattern) {
        unordered_map<char, char> map_w2p;
        unordered_map<char, char> map_p2w;

        for (int i = 0; i < word.size(); ++i) {
            if (map_w2p.find(word[i]) == map_w2p.end()
                && map_p2w.find(pattern[i]) == map_p2w.end()) {
                map_w2p[word[i]] = pattern[i];
                map_p2w[pattern[i]] = word[i];
            } else if ((map_w2p.find(word[i]) != map_w2p.end()
                        && map_w2p[word[i]] != pattern[i])
                    || (map_p2w.find(pattern[i]) != map_p2w.end()
                        && map_p2w[pattern[i]] != word[i])) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    vector<string> ans = Solution().findAndReplacePattern(words, "abb");
    for (const auto& elem : ans) {
        cout << elem << '\t';
    }

    return 0;
}