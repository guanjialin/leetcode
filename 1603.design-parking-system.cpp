//
// Created by addzero on 2020/12/4.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        max_parking_num[0] = big;
        max_parking_num[1] = medium;
        max_parking_num[2] = small;
    }

    bool addCar(int carType) {
        if (current_parking_num[carType - 1] < max_parking_num[carType - 1]) {
            ++current_parking_num[carType - 1];
            return true;
        }

        return false;
    }

private:
    int max_parking_num[3] = {0};
    int current_parking_num[3] = {0};
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

#ifdef __LOCAL__
int main()
{

    
    return 0;
}
#endif