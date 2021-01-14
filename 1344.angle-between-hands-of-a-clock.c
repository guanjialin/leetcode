//
// Created by addzero on 2020/11/13.
//


#include "header.h"

double angleClock(int hour, int minutes){
    double angle_minutes = (double) minutes / 60 * 360;
    double angle_hour = (double) minutes / 60 * 30 + hour % 12 * 30;
    double ans = fabs(angle_minutes - angle_hour);

    return fmin(ans, 360 - ans);
}

int main() {
    printf("%lf\n", angleClock(3, 30));

    return 0;
}