//
// Created by addzero on 2021/4/29.
//


#ifdef __LOCAL__

#include "header.h"

#endif

struct cmp
{
    bool operator()(int time, const pair<int, int> &p1) {
        return time < p1.first;
    }
};

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int cur_max_person = 0;
        unordered_map<int, int> cnt;

        data.resize(times.size());
        for (int i = 0; i < times.size(); ++i) {
            data[i] = std::make_pair(times[i], ++cnt[persons[i]] >= cnt[cur_max_person] ? persons[i] : cur_max_person);
            if (cnt[persons[i]] >= cnt[cur_max_person]) {
                cur_max_person = persons[i];
            }
        }
    }

    int q(int t) {
        return (--std::upper_bound(data.begin(), data.end(), t, cmp()))->second;
    }

private:
    vector<pair<int, int>> data;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

#ifdef __LOCAL__

int main() {
    vector<int> persons = {0,0,1,1,2}, times = {0,67,69,74,87};
    TopVotedCandidate vote(persons, times);
    cout << vote.q(4) << endl;
    cout << vote.q(62) << endl;
    cout << vote.q(100) << endl;
    cout << vote.q(88) << endl;
    cout << vote.q(70) << endl;
    cout << vote.q(73) << endl;

    return 0;
}

#endif