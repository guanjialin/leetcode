//
// Created by addzero on 2021/5/4.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int sum = 0;
        for (int i = shifts.size() - 1; i >= 0; --i) {
            sum += shifts[i];
            sum %= 26;
            S[i] = (S[i] + sum - 'a') % 26 + 'a';
        }

        return S;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> shifts = {3,5,9};
    cout << Solution().shiftingLetters("abc", shifts) << endl;

    return 0;
}

#endif