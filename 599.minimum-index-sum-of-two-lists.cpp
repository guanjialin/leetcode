//
// Created by addzero on 2020/12/14.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map_l1;

        for (int i = 0; i < list1.size(); ++i) {
            map_l1[list1[i]] = i;
        }

        int min_val = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < list2.size(); ++i) {
            if (map_l1.count(list2[i]) && i + map_l1[list2[i]] <= min_val) {
                if (i + map_l1[list2[i]] < min_val) {
                    min_val = i + map_l1[list2[i]];
                    ans.clear();
                }
                ans.push_back(list2[i]);
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Tapioca Express", "Shogun", "Burger King"};
    vector_print(Solution().findRestaurant(list1, list2));

    return 0;
}

#endif