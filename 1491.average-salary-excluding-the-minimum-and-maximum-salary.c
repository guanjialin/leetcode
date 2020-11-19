//
// Created by addzero on 2020/11/19.
//


#include "header.h"

double average(int* salary, int salarySize)
{
    int salary_min = fmin(salary[0], salary[1]);
    int salary_max = fmax(salary[0], salary[1]);
    double sum = 0;

    for (int i = 2; i < salarySize; ++i) {
        if (salary[i] < salary_min) {
            sum += salary_min;
            salary_min = salary[i];
        } else if (salary[i] > salary_max) {
            sum += salary_max;
            salary_max = salary[i];
        } else {
            sum += salary[i];
        }
    }

    return sum / (salarySize - 2);
}

int main()
{
    int data[] = {4000, 3000, 1000, 2000};
    printf("%lf\n", average(data, array_int_len(data)));

    return 0;
}