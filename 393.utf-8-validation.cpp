//
// Created by addzero on 2020/12/30.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int index = 0;

        while (index < data.size()) {
            int num = prefix1num((data[index] & 0xF0) >> 4);
            if (1 == num || (data[index] & (0x80 >> num)) != 0) {
                return false;
            }

            for (int i = 1; i < num; ++i) {
                if (++index >= data.size() || (data[index] & 0x80) != 0x80) {
                    return false;
                }
            }
            ++index;
        }

        return true;
    }

private:
    int prefix1num(int num) {
        int ans = 0;
        int bit = 0x8;

        while (num & bit) {
            ++ans;
            bit >>= 1;
        }
        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> data = {23,56,65,23,0};
    cout << Solution().validUtf8(data) << endl;

    return 0;
}

#endif