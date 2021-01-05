//
// Created by addzero on 2021/1/5.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class SnapshotArray {
public:
    SnapshotArray(int length) {
        array.resize(length);
    }

    void set(int index, int val) {
        if (array[index].empty() || array[index].back().first != snap_id) {
            array[index].push_back({snap_id, val});
        } else {
            array[index].back().second = val;
        }
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        auto it = std::upper_bound(array[index].begin(), array[index].end(), std::make_pair(snap_id, 0),
                         [](const pair<int, int> &p1, const pair<int, int> &p2)->bool {
                             return p1.first < p2.first; });

        return it == array[index].begin() ? 0 : (--it)->second;
    }

private:
    int snap_id = 0;
    vector<vector<pair<int, int>>> array; // first -> snap_id, second -> val;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

#ifdef __LOCAL__

int main() {
    auto *obj = new SnapshotArray(4);
//    obj->set(1, 5);
//    cout << obj->snap() << endl;
//    obj->set(0, 16);
//    cout << obj->snap() << endl;
//    obj->set(2, 15);
//    cout << obj->snap() << endl;
//    obj->set(2, 5);
//    cout << obj->get(1, 0) << endl;
//    cout << obj->get(0, 2) << endl;
//    cout << obj->snap() << endl;

//    obj->set(0, 5);
//    cout << obj->snap() << endl;
//    obj->set(0, 6);
//    cout << obj->get(0, 0) << endl;

    cout << obj->snap() << endl;
    cout << obj->get(1, 0) << endl;
    cout << obj->get(0, 0) << endl;
    obj->set(1, 8);
    cout << obj->get(1, 0) << endl;
    obj->set(0, 20);
    cout << obj->get(0, 0) << endl;
    obj->set(0, 7);

    return 0;
}

#endif