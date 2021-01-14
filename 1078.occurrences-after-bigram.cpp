//
// Created by addzero on 2020/11/5.
//


#include "header/cppheader.h"

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;

        string pattern = first + " " + second + " ";
        while (true) {
            auto iter = text.find(pattern);
            if (iter == string::npos) {
                break;
            }
            if (iter != 0 && text[iter - 1] != ' ') {
                text = text.substr(iter + first.size() + second.size() + 2);
                continue;
            }

            text = text.substr(iter + first.size() + second.size() + 2);
            auto thrid_end = text.find(' ');
            ans.push_back(text.substr(0, thrid_end == string::npos ? text.size() : thrid_end));
        }

        return ans;
    }
};

int main() {
    Solution().findOcurrences("alice is a good girl she is a good student", "a", "good");
    Solution().findOcurrences("alice is a good girl she is a good student", "good", "student");
    Solution().findOcurrences("alice is a good girl she is a good student", "student", "a");

    return 0;
}