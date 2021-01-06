//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        while (--n > 0) {
            int left = 0;
            string temp;
            for (int i = 0; i < ans.size(); ++i) {
                if (i + 1 == ans.size() || ans[i] != ans[i + 1]) {
                    temp += std::to_string(i - left + 1) + ans[i];
                    left = i + 1;
                }
            }
            ans = temp;
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    cout << Solution().countAndSay(1) << endl;
    cout << Solution().countAndSay(2) << endl;
    cout << Solution().countAndSay(3) << endl;
    cout << Solution().countAndSay(4) << endl;
    cout << Solution().countAndSay(5) << endl;

    return 0;
}

#endif