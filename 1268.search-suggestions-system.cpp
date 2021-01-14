//
// Created by addzero on 2020/11/3.
//


#include "header/cppheader.h"

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        vector<int> prefix_table = vector<int>(products.size());

        sort(products.begin(), products.end());
        for (int i = 0; i < products.size(); ++i) {
            prefix_table[i] = prefix(products[i], searchWord);
        }

        ans.reserve(searchWord.size());
        for (int i = 0; i < searchWord.size(); ++i) {
            vector<string> temp;
            for (int j = 0; j < prefix_table.size() && temp.size() < 3; ++j) {
                if (prefix_table[j] >= i + 1) {
                    temp.push_back(products[j]);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }

private:
    int prefix(const string &product, const string &searchWord)
    {

        int left = 0, right = 0;

        while (left < product.size() && right < searchWord.size()
            && product[left] == searchWord[right]) {
            ++left; ++ right;
        }

        return left;
    }
};

int main()
{
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    auto ans = Solution().suggestedProducts(products, "mouse");

    for (const auto &product : ans) {
        for (const auto &pro : product) {
            cout << pro << " ";
        }
        cout << endl;
    }

    return 0;
}