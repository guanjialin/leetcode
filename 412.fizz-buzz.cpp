//
// Created by addzero on 2020/12/31.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            int mod3 = i % 3;
            int mod5 = i % 5;
            if (!mod3 && !mod5) {
                ans.emplace_back("FizzBuzz");
            } else if (!mod3) {
                ans.emplace_back("Fizz");
            } else if (!mod5) {
                ans.emplace_back("Buzz");
            } else {
                ans.emplace_back(std::to_string(i));
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector_print(Solution().fizzBuzz(3));

    return 0;
}

#endif