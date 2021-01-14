//
// Created by addzero on 2020/11/22.
//


#include "header/cppheader.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> map_ans;

        for (auto str : strs) {
            string sorted_str = str;
            std::sort(sorted_str.begin(), sorted_str.end());
            map_ans[sorted_str].push_back(str);
        }

        vector<vector<string>> ans;
        for (const auto &str : map_ans) {
            ans.push_back(str.second);
        }

        return ans;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = Solution().groupAnagrams(strs);
    for (const auto &vec : ans) {
        vector_print(vec);
    }

    return 0;
}