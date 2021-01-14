//
// Created by addzero on 2020/12/31.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        string base = "1";
        vector<string> ans;

        std::sort(folder.begin(), folder.end());
        for (auto & i : folder) {
            if (std::strncmp(base.c_str(), i.c_str(), base.size()) != 0) {
                base = i;
                ans.emplace_back(base);
                base += "/";
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<string> folder = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    vector_print(Solution().removeSubfolders(folder));

    return 0;
}

#endif