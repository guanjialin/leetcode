//
// Created by addzero on 2020/11/6.
//


#include "header/cppheader.h"

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) {
            return 0;
        }

        // 如果只包含一种字母，则必定为回文
        if (isPalindrome(s)) {
            return 1;
        }

        return 2;
    }

private:
    bool isPalindrome(const string &s) {
        string r = s;
        std::reverse(r.begin(), r.end());
        return s == r;
    }
};

int main() {
    cout << Solution().removePalindromeSub("ababa") << endl;

    return 0;
}