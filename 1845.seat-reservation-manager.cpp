//
// Created by addzero on 2021/5/10.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            seats.push(i);
        }
    }

    int reserve() {
        auto ans = seats.top();
        seats.pop();
        return ans;
    }

    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }

private:
    priority_queue<int, vector<int>, std::greater<>> seats;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif