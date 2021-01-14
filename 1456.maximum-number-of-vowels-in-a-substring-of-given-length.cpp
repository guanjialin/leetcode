//
// Created by addzero on 2021/1/9.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int maxVowels(string s, int k) {
        int num = 0;
        int ans = 0;
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < k; ++i) {
            if (vowel.count(s[i])) {
                ++num;
            }
        }
        ans = num;

        for (int i = k; i < s.size(); ++i) {
            num -= vowel.count(s[i - k]);
            num += vowel.count(s[i]);
            ans = std::max(num, ans);
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    cout << Solution().maxVowels("abciiidef", 3) << endl;

    return 0;
}

#endif