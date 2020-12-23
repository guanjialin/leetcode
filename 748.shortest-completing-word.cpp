//
// Created by addzero on 2020/12/23.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string ans;
        auto plate = process(licensePlate);

        ans.resize(16);
        for (const auto &word : words) {
            if (word.size() < ans.size() && compare(plate, process(word))) {
                ans = word;
            }
        }

        return ans;
    }

private:
    unordered_map<char, int> process(string s) {
        unordered_map<char, int> ret;

        for (auto c : s) {
            if (isalpha(c)) {
                ++ret[tolower(c)];
            }
        }

        return ret;
    }

    bool compare(const unordered_map<char, int> &plate, unordered_map<char, int> word) {
        for (auto item : plate) {
            if (!word.count(item.first) || word[item.first] < item.second) {
                return false;
            }
        }
        return true;
    }
};

#ifdef __LOCAL__

int main() {
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    cout << Solution().shortestCompletingWord("1s3 PSt", words) << endl;

    return 0;
}

#endif