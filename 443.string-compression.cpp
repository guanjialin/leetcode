//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int left = 0;

        for (int i = 0; i < chars.size(); ++i) {
            if (i + 1 == chars.size() || chars[i] != chars[i + 1]) {
                chars[ans++] = chars[i];
                if (i > left) {
                    auto s = std::to_string(i - left + 1);
                    for (auto c : s) {
                        chars[ans++] = c;
                    }
                }
                left = i + 1;
            }
        }
        chars.resize(ans);

        return ans;
    }
};

#ifdef __LOCAL__
int main()
{
    string s = "aaabbaa";
    vector<char> chars(s.begin(), s.end());
    cout << Solution().compress(chars) << endl;
    vector_print(chars);

    return 0;
}
#endif