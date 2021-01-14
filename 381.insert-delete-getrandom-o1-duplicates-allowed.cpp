//
// Created by dell on 2020/10/31.
//

#include "header/cppheader.h"

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        data.push_back(val);
        index[val].push_back(data.size() - 1);

        return index[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (index[val].empty()) {
            return false;
        }

        auto will_erase_index = index[val].back();
        index[val].pop_back();
        data[will_erase_index] = data.back();
        index[data.back()].push_back(will_erase_index);
        index[data.back()].pop_back();
        data.pop_back();

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        srandom(time(nullptr));
        return data[random() % data.size()];
    }

private:
    vector<int> data;
    unordered_map<int, vector<int>> index;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main()
{
    RandomizedCollection obj = RandomizedCollection();
    cout << obj.insert(1) << endl;
//    cout << obj.insert(1) << endl;
    cout << obj.remove(1) << endl;
    cout << obj.insert(1) << endl;
//    cout << obj.remove(1) << endl;
    cout << obj.getRandom() << endl;

    return 0;
}