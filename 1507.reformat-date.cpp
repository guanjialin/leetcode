//
// Created by addzero on 2020/11/4.
//


#include "header/cppheader.h"

class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> map_months = {
                {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"},
                {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"},
                {"Nov", "11"}, {"Dec", "12"},
        };
        string ans = date.substr(date.size() - 4, 4) + "-";
        ans += map_months[date.substr(date.size() - 8, 3)] + "-";
        string day = date.substr(0, date.size() - 11);
        ans += day.size() == 1 ? "0" + day : day;

        return ans;
    }
};

int main() {
    cout << Solution().reformatDate("20th Oct 2052") << endl;
    cout << Solution().reformatDate("6th Jun 1933") << endl;
    cout << Solution().reformatDate("26th May 1960") << endl;

    return 0;
}