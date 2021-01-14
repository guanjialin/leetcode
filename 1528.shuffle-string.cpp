//
// Created by addzero on 2021/1/8.
//


#ifdef __LOCAL__

#include "header.h"

#endif

#if 0
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans;
        ans.resize(s.size());
        for (int i = 0; i < s.size(); ++i)  {
            ans[indices[i]] = s[i];
        }

        return ans;
    }
};
#else
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            int idx = indices[i];
            while (idx != i) {
                std::swap(s[idx], ch);
                std::swap(indices[idx], idx);
            }
            s[i] = ch;
            indices[idx];
        }

        return s;
    }
};
#endif

#ifdef __LOCAL__

int main() {
    string s = "codeleet";
    vector<int> indices = {4,5,6,7,0,2,1,3};
    cout << Solution().restoreString(s, indices) << endl;

    return 0;
}

#endif