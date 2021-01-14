//
// Created by dell on 2020/11/1.
//

#include "header/cppheader.h"

class Solution {
public:
    string customSortString(string S, string T) {
        int record[26] = {0};
        string ans;

        for (auto c : T) {
            ++record[c - 'a'];
        }

        for (auto c : S) {
            ans += string(record[c - 'a'], c);
            record[c - 'a'] = 0;
        }

        for (int i = 0; i < 26; ++i) {
            ans += string(record[i], i + 'a');
        }

        return ans;
    }
};

int main()
{
    cout << Solution().customSortString("cba", "abcd") << endl;

    return 0;
}