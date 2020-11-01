//
// Created by dell on 2020/10/31.
//

#include "cppheader.h"

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int ans = 0;
        unordered_set<string> set_record;

        for (auto s : A) {
            set_record.insert(pretreatment(s));
        }

        return set_record.size();
    }

private:
    string pretreatment(string s) {
        string odd;
        string even;

        for (int i = 0; i < s.size(); ++i) {
            if (i % 2) {
                odd.push_back(s[i]);
            } else {
                even.push_back(s[i]);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        return even + odd;
    }
};

int main()
{
    vector<string> A = {"abcd","cdab","cbad","xyzz","zzxy","zzyx"};
    cout << Solution().numSpecialEquivGroups(A) << endl;

    return 0;
}