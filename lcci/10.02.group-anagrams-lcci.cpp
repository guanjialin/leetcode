//
// Created by dell on 2020/11/1.
//

#include "../cppheader.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map_record;
        vector<vector<string>> ans;

        for (const auto& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            map_record[s].push_back(str);
        }

        ans.reserve(map_record.size());
        for (const auto& val : map_record) {
            ans.push_back(val.second);
        }

        return ans;
    }
};

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = Solution().groupAnagrams(strs);
    for (auto val : ans) {
        for (auto word : val) {
            cout << word << '\t';
        }
        cout << endl;
    }

    return 0;
}