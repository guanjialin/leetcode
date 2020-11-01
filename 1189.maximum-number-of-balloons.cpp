//
// Created by dell on 2020/11/1.
//

#include "cppheader.h"

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> map_count;

        for (auto c : text) {
            ++map_count[c];
        }

        return min({map_count['b'], map_count['a'], map_count['l'] / 2, map_count['o'] / 2, map_count['n']});
    }
};

int main()
{
    cout << Solution().maxNumberOfBalloons("balon");

    return 0;
}