//
// Created by addzero on 2020/12/7.
//


#ifdef __LOCAL__
#include "header.h"
#endif

#ifdef __HEAP__
// 堆解法
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (const auto &num : nums) {
            helper(num);
        }
    }

    int add(int val) {
        helper(val);
        return heap.top();
    }

private:
    void helper(int val)
    {
        heap.push(val);
        if (heap.size() > k) {
            heap.pop();
        }
    }

private:
    int k = 0;
    priority_queue<int, vector<int>, std::greater<>> heap;
};
#else
// 评论区大佬的 multiset 解法
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (const auto &num : nums) {
            helper(num);
        }
    }

    int add(int val) {
        helper(val);

        return *mset.begin();
    }

private:
    void helper(int val)
    {
        mset.insert(val);
        if (mset.size() > k) {
            mset.erase(mset.begin());
        }
    }

private:
    int k;
    multiset<int> mset;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
#endif

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

#ifdef __LOCAL__
int main()
{
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;
    cout << kthLargest.add(5) << endl;
    cout << kthLargest.add(10) << endl;
    cout << kthLargest.add(9) << endl;
    cout << kthLargest.add(4) << endl;

    return 0;
}
#endif