//
// Created by addzero on 2020/12/14.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> map_count;

        for (int i = 0; i < s.length(); ++i) {
            string sub = s.substr(i, 10);
            if (map_count.count(sub) && 1 == map_count[sub]) {
                ans.push_back(sub);
            }
            ++map_count[sub];
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector_print(Solution().findRepeatedDnaSequences(""));
    vector_print(Solution().findRepeatedDnaSequences("AAAAAAAAAAAAA"));
    vector_print(Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));

    return 0;
}

#endif