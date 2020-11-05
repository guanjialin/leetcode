//
// Created by addzero on 2020/11/5.
//


#include "cppheader.h"

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 0;

        for (const auto& item : bank) {
            set_bank.insert(item);
        }

        queue_temp.push(start);
        set_bank.insert(start);

        while (!queue_temp.empty()) {
            ++ans;

            int size = queue_temp.size();
            for (int i = 0; i < size; ++i) {
                string front = queue_temp.front();
                queue_temp.pop();

                if (processor(front, end)) {
                    return ans;
                }
            }
        }

        return -1;
    }

private:
    bool processor(string s, const string &end)
    {
        for (auto &c : s) {
            char ori = c;
            for (auto d : direction) {
                c = d;
                if (set_bank.find(s) != set_bank.end()
                    && set_visited.find(s) == set_visited.end()) {
                    if (s == end) {
                        return true;
                    }
                    queue_temp.push(s);
                    set_visited.insert(s);
                }
            }
            c = ori;
        }

        return false;
    }

private:
    string direction = "ACGT";
    unordered_set<string> set_bank;
    unordered_set<string> set_visited;
    queue<string> queue_temp;
};

int main() {
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    cout << Solution().minMutation("AACCGGTT", "AAACGGTA", bank) << endl;

    return 0;
}