//
// Created by addzero on 2020/12/17.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        set<int> tables;
        map<string, unordered_multiset<string>> food_table;
        unordered_map<string, int> tables_table;

        for (const auto &order : orders) {
            food_table[order[2]].insert(order[1]);
            tables.insert(atoi(order[1].c_str()));
        }

        ans.resize(tables.size() + 1);
        int idx = 1;
        for (const auto & table : tables) {
            ans[idx].resize(food_table.size() + 1, "0");
            tables_table[std::to_string(table)] = idx;
            ans[idx][0] = std::to_string(table);
            idx++;
        }

        idx = 1;
        ans[0].push_back("Table");
        for (const auto &table : food_table) {
            ans[0].push_back(table.first);
            for (const auto &t : table.second) {
                ans[tables_table[t]][idx] = std::to_string(atoi(ans[tables_table[t]][idx].c_str()) + 1);
            }
            ++idx;
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<vector<string>> orders = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
    auto ans = Solution().displayTable(orders);
    for (const auto &row : ans) {
        for (const auto & col : row) {
            cout << col << '\t';
        }
        cout << endl;
    }

    return 0;
}

#endif