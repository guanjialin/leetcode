//
// Created by addzero on 2020/11/26.
//


#include "../cppheader.h"

#if __HEAP__
// 堆
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>> pq(arr.begin(), arr.begin() + k);

        for (int i = k; i < arr.size(); ++i) {
            pq.push(arr[i]);
            pq.pop();
        }

        for (int i = 0; i < k; ++i) {
            ans.emplace_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
#elif __QUICK_SELECTION__
// 快速选择
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k)
    {
        int pivot = -1;
        int left = 0, right = arr.size() - 1;

        while (pivot != k - 1) {
            pivot = partition(arr, left, right);
            if (pivot > k) {
                right = pivot - 1;
            } else if (pivot < k) {
                left = pivot + 1;
            }
        }

        return vector<int>(arr.begin(), arr.begin() + k);
    }

private:
    static int partition(vector<int> &arr, int left, int right)
    {
        int val = arr[left];

        while (left < right) {
            while (left < right && arr[right] >= val) {
                --right;
            }
            std::swap(arr[left], arr[right]);

            while (left < right && arr[left] <= val) {
                ++left;
            }
            std::swap(arr[left], arr[right]);
        }

        return left;
    }
};
#else
// BFPRT 调用标准库
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (!k) {
            return vector<int>();
        }

        std::nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
        int nth = arr[k - 1];
        vector<int> ans;

        for (int i = 0; i < arr.size() && ans.size() < k; ++i) {
            // 由于可能存在不少元素等于 nth，并且分布在前面，导致后面小于 nth 的元素没有放进去
            // 故不能直接 <=
            if (arr[i] < nth) {
                ans.emplace_back(arr[i]);
            }
        }

        while (ans.size() < k) {
            ans.emplace_back(nth);
        }

        return ans;
    }
};
#endif

int main() {
    vector<int> data = {62577,-220,-8737,-22,-6,59956,5363,-16699,0,-10603,64,-24528,-4818,96,5747,2638,-223,37663,-390,35778,-4977,-3834,-56074,7,-76,601,-1712,-48874,31,3,-9417,-33152,775,9396,60947,-1919,683,-37092,-524,-8,1458,80,-8,1,7,-355,9,397,-30,-21019,-565,8762,-4,531,-211,-23702,3,3399,-67,64542,39546,52500,-6263,4,-16,-1,861,5134,8,63701,40202,43349,-4283,-3,-22721,-6,42754,-726,118,51,539,790,-9972,41752,0,31,-23957,-714,-446,4,-61087,84,-140,6,53,-48496,9,-15357,402,5541,4,53936,6,3,37591,7,30,-7197,-26607,202,140,-4,-7410,2031,-715,4,-60981,365,-23620,-41,4,-2482,-59,5,-911,52,50068,38,61,664,0,-868,8681,-8,8,29,412};
    vector_print(Solution().smallestK(data, 131));

    return 0;
}