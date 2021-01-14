//
// Created by addzero on 2020/11/6.
//


#include "header/cppheader.h"

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;

        for (auto log : logs) {
            if (log == "../") {
                ans += ans > 0 ? -1 : 0;
            } else if (log != "./") {
                ++ans;
            }
        }

        return ans;
    }
};

int main() {
    vector<string> logs = {"d1/","d2/","./","d3/","../","d31/"};
    cout << Solution().minOperations(logs) << endl;

    return 0;
}