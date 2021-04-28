//
// Created by addzero on 2021/4/29.
//


#ifdef __LOCAL__

#include "header.h"

#endif

struct cmp
{
    bool operator() (const pair<int, string> &p, int timestamp) {
        return p.first <= timestamp;
    }
};

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!data.count(key) || data[key][0].first > timestamp) {
            return "";
        }

        return (--std::lower_bound(data[key].begin(), data[key].end(), timestamp, cmp()))->second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

#ifdef __LOCAL__

int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl;
    cout << timeMap.get("foo", 3) << endl;
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl;
    cout << timeMap.get("foo", 5) << endl;

    return 0;
}

#endif