//
// Created by addzero on 2021/1/15.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    string printBin(double num) {
        string ans = "0.";

        while ((num *= 2) && ans.length() <= 32) {
            ans.push_back((num >= 1) + '0');
            num -= (num >= 1);
        }

        return ans.length() > 32 ? "ERROR" : ans;
    }
};

#ifdef __LOCAL__

int main() {
    cout << Solution().printBin(0.625) << endl;
    cout << Solution().printBin(0.1) << endl;

    return 0;
}

#endif