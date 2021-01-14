//
// Created by addzero on 2021/1/3.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> base(26, A.size());
        vector<int> comp(26);

        for (const auto &str : A) {
            std::fill(comp.begin(), comp.end(), 0);
            for (auto c : str) {
                ++comp[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                base[i] = min(base[i], comp[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < base[i]; ++j) {
                ans.emplace_back(1, i + 'a');
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<string> A = {
            "bella", "label", "roller"
    };
    vector_print(Solution().commonChars(A));

    return 0;
}

#endif